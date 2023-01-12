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

GDB（GNU Debugger）

### 2.2 生成调试信息



### 2.3 启动gdb



### 2.4 显示源代码



---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 