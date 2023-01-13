# makefile-gdb-文件IO

## 1. makefile

**makefile** 文件中定义了 一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作，就像是一个shell脚本，其中也可以执行操作系统的命令。
【:loudspeaker:】**实现自动化编译** :heavy_exclamation_mark::heavy_exclamation_mark::heavy_exclamation_mark: 

**make** 是一个命令工具，是一个解释makefile中指令的命令工具，一般来说，大多数的IDE都有这个命令。

makefile 文件命名： `makefile` 或 `Makefile` 

### 1.1 makefile的基本规则

makefile 由一组规则组成，规则如下：  
目标：依赖  
（tab）命令

makefile 基本三要素：

- 目标：要生成的目标文件
- 依赖：目标文件由哪些文件生成
- 命令：通过执行该命令由依赖文件生成目标

`main.c` `func1.c` `func2.c` `head.h` 同级目录，创建makefile文件

```Linux
makefile文件：(版本1)
1 main: main.c func1.c func2.c 
2 	gcc -o main main.c func1.c fucn2.c [-I头文件目录（同级目录可不写）]

[xfk@centos FUNCSET]$ make
gcc -o main main.c func1.c fucn2.c
```

### 1.2 makefile工作原理

基本原则：

- 若想生成目标，检查规则中所有的依赖文件是否都存在：
  - 如果依赖文件不存在，则向下搜索，看是否有生成该依赖文件的规则：
    - 如果有规则用来生成依赖文件，则执行规则中的命令生成依赖文件；
    - 如果没有规则用来生成依赖文件，则报错。
  - 如果所有依赖都存在，检查规则中的目标是否需要更新，必须先检查它的所有依赖，依赖中有任何一个被更新，则目标必须更新。
    - 若目标时间 > 依赖时间，不更新
    - 若目标时间 < 依赖时间，则更新

```Linux
makefile文件：（版本2）
1 main:main.o func1.o func2.o
2     gcc -o main main.o func1.o func2.o
3 main.o:main.c
4     gcc -c main.c -I./
5 func1.o:func1.c
6     gcc -c func1.c
7 func2.o:func2.c
8     gcc -c func2.c

[xfk@centos FUNCSET]$ make
gcc -c main.c -I./
gcc -c func1.c
gcc -c func2.c
gcc -o main main.o func1.o func2.o

更新func1.c
[xfk@centos FUNCSET]$ make
gcc -c func1.c
gcc -o main main.o func1.o func2.o
```

### 1.3 makefile中的变量

makefile 使用变量有点类似于C语言中的宏定义，使用该变量相当于内容替换，使用变量可以是makefile易于维护，修改起来变得简单。

#### 1.3.1 普通变量

- 定义 `变量名 =` 
- 使用 `$(变量名)` 

```Linux
定义了两个变量：foo，bar，其中bar的值是foo变量值的引用
foo =abc			//定义变量并赋值
bar = $(foo)		//使用变量
```

#### 1.3.2 自带变量

makefile 中提供了一些变量（变量名大写）供用户直接使用

| 变量       | 含义                            |
| ---------- | ------------------------------- |
| `CC`       | 指定编译器                      |
| `CPPFLAGS` | C预处理的选项 `-I`              |
| `CFLAGS`   | C编译器的选项 `-Wall` `-g` `-c` |
| `LDFLAGS`  | 链接器选项 `-L` `-l`            |

#### 1.3.3 自动变量

【:loudspeaker:】只能在命令中使用

- `$@` ：表示规则中的目标
- `$<` ：表示规则中的第一个条件
- `$^` ：表示规则中的所有条件，组成一个列表，以空格隔开，如果这个列表中有重复的项，则消除重复项

```Liunx
makefile文件：（版本3）
1 target=main
2 objects=main.o add.o sub.o mul.o divd.o
3 CC=gcc
4 CPPFLAGS=-I./
5 $(target):$(objects)
6     $(CC) -o $@ $^
7 main.o:main.c
8     $(CC) -c $< $(CPPFLAGS)
9 add.o:func1.c
10    $(CC) -c $<
11 sub.o:func2.c
12    $(CC) -c $<

[xfk@centos FUNCSET]$ make
gcc -c main.c -I./
gcc -c add.c
gcc -c sub.c
gcc -c mul.c
gcc -c divd.c
gcc -o main main.o add.o sub.o mul.o divd.o
```

#### 1.3.4 模式规则

在目标和依赖中使用 `%` 表示一个或多个  
`%.o:%.c` 前后的%必须是相同的

```Linux
makefile文件：（版本4）
1 target=main
2 objects=main.o add.o sub.o mul.o divd.o
3 CC=gcc
4 CPPFLAGS=-I./
5 $(target):$(objects)
6     $(CC) -o $@ $^
7 %.o:%.c
8     $(CC) -c $< $(CPPFLAGS)
```

### 1.4 makefile函数

1. wildcard 查找指定目录下的指定类型的文件  
   `src=$(wildcard *.c)` 当前目录下所有`.c`文件赋值给src
2. patsubst 匹配替换  
   `obj=$(patsubst %.c,%.o,$(src))` 把src变量里所有后缀为`.c`的文件替换成`.o` 

```Linux
makefile文件：（版本5）
1 target=main
2 src=$(wildcard *.c)
3 objects=$(patsubst %.c,%.o,$(src))      
4 CC=gcc
5 CPPFLAGS=-I./
6 $(target):$(objects)
7     $(CC) -o $@ $^
8 %.o:%.c
9     $(CC) -c $< $(CPPFLAGS)
```

### 1.5 makefile的清理操作

清除编译生成的的中间`.o`文件和最终目标文件

- 伪目标声明：  
  `.PHONY:clean` （伪目标不会检查是否存在或者该目标是否需要更新）

```Linux
.PHONY:clean
clean:
	rm -f ...
```

- 终极目标：makefile文件中第一个出现的目标叫终极目标，`make` 默认生成终极目标  

【:loudspeaker:】 其他目标可以通过指定生成 `make clean` 

```Linux
makefile文件：（版本6）
1 target=main
2 src=$(wildcard *.c)
3 objects=$(patsubst %.c,%.o,$(src))      
4 CC=gcc
5 CPPFLAGS=-I./
6 $(target):$(objects)
7     $(CC) -o $@ $^
8 %.o:%.c
9     $(CC) -c $< $(CPPFLAGS)
10 .PHONY:clean
11 clean:
12    [@/-]rm -f $(objects) $(target)		//@不显示操作,-该命令报错不影响下面的命令执行
```

【:ticket:】`make -f xxxx [clean]` 指定makefile文件（改名）

## 2. gdb调试

### 2.1 gdb介绍

GDB（GNU Debugger）是GCC的调试工具。  
GDB主要有一下四个方面的功能：

1. 启动程序，可以按照你的自定义的要求随心所欲的运行程序
2. 可让被调试的程序在你所指定的断点处停住（断点可以是条件表达式）
3. 当程序被停住时，可以检查此时你的程序中所发生的事
4. 动态的改变你程序的执行环境

### 2.2 生成调试信息

一般来说GDB主要调试的是C/C++的程序。  
要调试C/C++的程序，首先在编译时，我们必须要把调试信息加到可执行文件中。

- 编译器（cc/gcc/g++）参数 `-g` 用来生成调试信息  
  `gcc -g hello.c -o hello` （单个文件）  

```Linux
makefile 文件
1 target=main
2 src=$(wildcard *.c)
3 objects=$(patsubst %.c,%.o,$(src))
4 CC=gcc
5 CPPFLAGS=-I./
6 $(target):$(objects)
7     $(CC) -o $@ $^
8 %.o:%.c
9     $(CC) -c $< $(CPPFLAGS) -g		#源文件编译步骤加入-g
10 .PHONY:clean
11 clean:
12     rm -f $(objects) $(target)
```

### 2.3 启动gdb

- 启动gdb：`gdb program` 
- 退出gdb：`quit` 
- 设置运行参数
  - `set args` 可指定运行时参数
  - `show args` 可查看设置好的运行参数
- 启动程序
  - `run ` 程序开始执行，如果又断点，停在第一个断点处
  - `start` 程序向下执行一行，在

### 2.4 显示源代码

- `list(简写l)` 显示源代码

| 命令                 | 操作                                     |
| -------------------- | ---------------------------------------- |
| `list linenum `      | 显示第linenum行的上下文内容              |
| `list function`      | 显示函数名为function的函数源程序         |
| `list`               | 显示当前行                               |
| `list -`             | 显示当前文件开始处的源程序               |
| `list file:linenum`  | 显示file文件下的第n行                    |
| `list file:function` | 显示file文件函数名为function的函数源程序 |

【:loudspeaker:】默认显示10行  
             更改默认值 `set listsize num`，查看默认值 `show listsize`   

### 2.5 设置断点

- `break(简写b)` 设置断点 

| 命令                | 操作                             |
| ------------------- | -------------------------------- |
| `b linenum`         | 在源程序第linenum行设置断点      |
| `b func`            | 在func函数入口处设置断点         |
| `b file:linenum`    | 在file文件第linenum行设置断点    |
| `b file:func`       | 在file文件func函数入口处设置断点 |
| `b ... if 判断条件` | 条件断点                         |

【:loudspeaker:】`info break(简写i b)` 显示断点信息

修改断点  
`disable m n | m-n`   
`enable m n | m-n` 

删除断点  
`delete m n | m-n` 

### 2.6 调试代码

- `run` 运行程序，可简写为r
- `next` 单步跟踪，函数调用当做一条简单语句执行，可简写为n
- `step` 单步跟踪，函数调用进入被调用函数体内，可简写为s
- `finish` 退出进入的函数（如果出不去，看一下函数体中的循环中是否有断点，如果有删除或设置无效）
- `until` 在一个循体内单步跟踪时，可运行程序直到退出循环体，可简写为u（如果出不去，看一下函数体中的循环中是否有断点，如果有删除或设置无效）
- `contiue` 继续运行程序，可简写为c（若有断点，则跳到下一个断点）

### 2.7 查看断点的值

- 查看运行时变量的值  
  `print 变量名`
- 自动显示变量的值
- 查看修改变量的值

---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 