# vim操作:racing_car: 

## 1. vim

#### 1.1 vim简单介绍

**vi** 是 visual interface 的简称，它在Linux上的地位就仿佛Windows中的记事本。它可以执行编辑、删除、查找、替换、块操作等众多文本操作，而且用户可以根据自己的需求对其进行定制。vi是一个文本编辑程序，没有菜单，只有命令。

**vim** 更高级，可以理解为vi的高级版本。  
`vimtutor` 可查看相关的帮助文档。

#### 1.2 vim三种模式

vim 有输入和命令 **3** 种工作模式：
1>命令模式>>>  
				`：` 转末行，`iI/oO/aA` 转编辑，`ZZ（大写）` 保存退出  
2>文本（编辑）模式>>>  
				`Esc` 转命令  
3>末行模式>>>  
				`w` 保存 `q` 退出，`Esc Esc ` / `执行一次末行命令`转命令

#### 1.3 vim基本操作

##### 1.3.1 命令模式下的操作

`vim 文件` 进入命令模式  
文本模式 `Esc` 转命令模式

###### 1）保存退出

`ZZ`（大写）

###### 2）代码格式化

`gg=G` 缩进排版

###### 3）光标移动

| 快捷键     | 操作         |
| ---------- | ------------ |
| `hjkl`     | 左下上右     |
| `w`        | 移动一个单词 |
| `gg`       | 移动首行     |
| `G`        | 移动尾行     |
| `0` （零） | 移动行首     |
| `$`        | 移动行尾     |
| [n]G       | 跳转到第n行  |

###### 4）删除命令

| 快捷键                           | 操作                                |
| -------------------------------- | ----------------------------------- |
| `x`                              | 删除光标后一个字符，相当于Del       |
| `X`                              | 删除光标前一个字符，相当于Backspace |
| `dw`                             | 删除光标后一个单词                  |
| `d0`                             | 删除光标前全部内容                  |
| `D/d$`                           | 删除光标后全部内容                  |
| `[n]dd`                          | 剪切从光标所在行n行                 |
| `v（非列模式）/Ctrl+v（列模式）` | 使用hjkl移动选择内容，然后d删除，   |

###### 5）撤销和反撤销

| 快捷键   | 操作   |
| -------- | ------ |
| `u`      | 撤销   |
| `Ctrl+r` | 反撤销 |

###### 6）复制和粘贴

| 快捷键  | 操作                               |
| ------- | ---------------------------------- |
| `[n]yy` | 复制当前行，n行                    |
| `[n]dd` | 剪切当前行，n行                    |
| `p/P`   | 小p向下，大P向上，粘贴开辟新的一行 |

###### 7）可视模式

`v/Ctrl+v`    
使用 `hjkl` 移动选择内容  

- `d` 删除
- `y` 复制
- `p/P` 小p光标前，大P光标后，粘贴

###### 8）查找命令

输入`/nohl`，可以取消高亮

| 快捷键    | 操作                                   |
| --------- | -------------------------------------- |
| `/xxx`    | 光标所在位置开始搜索（n向下，N向上）   |
| `?xxx`    | 光标所在位置开始搜索（n向上，N向下）   |
| `#`       | 光标移动到待查找字符串（n向上，N向下） |
| `Shift+k` | 光标移动到待查找字符串，查看帮助文档   |

###### 9）替换命令

| 快捷键 | 操作                            |
| ------ | ------------------------------- |
| `r`    | 替换当前字符                    |
| `R`    | 替换当前行光标后的字符，Esc退出 |

##### 1.3.2 切换文本输入模式

| 快捷键   | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| `i`      | 在光标前插入                                                 |
| `I`      | 在光标所在行行首插入                                         |
| `o`      | 在光标所在行的下插入新的一行，行首插入                       |
| `O`      | 在光标所在行的上插入新的一行，行首插入                       |
| `a`      | 在光标后插入                                                 |
| `A`      | 在光标所在行行尾插入                                         |
| `s`      | 删除光标后字符，从光标当前位置插入                           |
| `S`      | 删除光标所在当前行，从行首插入                               |
| `Ctrl+v` | 列模式下，`hjkl` 移动选定某多列，`I` 向前插入，最后 `Esc Esc` <br />应用：多行注释 |

##### 1.3.3 末行模式下的操作

命令模式 `:` 转末行模式   
末行模式 `Esc Esc` /  `backspace` / `Enter` 转命令模式

###### 1）保存退出

| 快捷键 | 操作     |
| ------ | -------- |
| `q`    | 退出     |
| `q！`  | 强制退出 |
| `w`    | 保存     |
| `wq/x` | 保存退出 |

###### 2）替换操作

| 快捷键                                                       | 操作                           |
| ------------------------------------------------------------ | ------------------------------ |
| `:s/old/new/`                                                | 光标所在行的第一个old替换为new |
| `:s/old/new/g`                                               | 光标所在行所有old替换为new     |
| `:m,ns/old/new/g`                                            | 将m-n行之间的old替换为new      |
| `:%s/old/new/g`<br />`:1,$s/old/new/g`<br />`:%s/old/new/gc`（提示用户） | 当前文件的所有old替换为new     |

###### 3）快速翻屏

| 快捷键   | 操作                     |
| -------- | ------------------------ |
| `Ctrl+u` | 向下翻半屏，光标向上移动 |
| `Ctrl+d` | 向上翻半屏，光标向下移动 |
| `Ctrl+f` | 向下翻一屏               |
| `Ctrl+b` | 向上翻一屏               |

###### 4）执行shell命令

`:! shell命令`  vim中执行shell命令后返回vim  
`Esc Esc` 返回命令模式

###### 5）分屏操作

| 快捷键                       | 操作                                 |
| ---------------------------- | ------------------------------------ |
| `sp [文件名]`                | 水平分屏                             |
| `vsp [文件名]`               | 垂直分屏                             |
| `Ctrl+w+w`                   | 切换窗口                             |
| `wall/wqall/xall/qall/qall!` | 保存/保存退出/保存退出/退出/强制退出 |

【:loudspeaker:】`vim -o/O 文件1 文件2` 小o水平分屏，大O垂直分屏

##### 1.3.4 vim配置文件

`~/.vimrc` 用户级别

`/etc/vim/vimrc` 系统级别

- `set tabstop=4` 设置缩进4个空格
- `set nu` 设置行号
- `set shiftwidth` 设置`gg=G`缩进4个空格 

## 2. gcc编译器

#### 2.1 gcc工作流程

hello.c【源文件】 :one:>>> hello.i【c文件】 :two:>>> hello.s【汇编文件】 :three:>>> hello.o【二进制文件】 :four:>>> a.out【可执行文件】

:one: 预处理（cpp）`gcc -E xxx.c -o xxx.i`   
**头文件展开，宏替换，去掉注释**

:two: 编译器（gcc）`gcc -S xxx.i -o xxx.s`  
**c文件变成汇编文件**

:three: 汇编器（as） `gcc -c xxx.s -o xxx.o`  
**汇编文件变成二进制文件**

:four: 链接器（ld）`gcc xxx.o -o xxx`  
**将函数库中相应的代码组合到目标文件中**

【:loudspeaker:】四合一 `gcc -o xxx xxx.c` 

```Linux
>>> 预处理
[xfk@centos TESTDIR]$ gcc -E file.c -o file.i
[xfk@centos TESTDIR]$ ls -l file.i
-rw-rw-r--. 1 xfk xfk 16888 1月  11 21:29 file.i
>>> 编译
[xfk@centos TESTDIR]$ gcc -S file.i -o file.s
[xfk@centos TESTDIR]$ ls -l file.s
-rw-rw-r--. 1 xfk xfk 735 1月  11 21:35 file.s
>>> 汇编
[xfk@centos TESTDIR]$ gcc -c file.s -o file.o
[xfk@centos TESTDIR]$ ls -l file.o
-rw-rw-r--. 1 xfk xfk 1632 1月  11 21:38 file.o
>>> 链接
[xfk@centos TESTDIR]$ gcc file.o -o file
[xfk@centos TESTDIR]$ ./file 
hello world
>>> 四合一
[xfk@centos TESTDIR]$ gcc -o file file.c
[xfk@centos TESTDIR]$ ./file
hello world
```

#### 2.2 gcc常用参数

| 参数        | 含义                                              |
| ----------- | ------------------------------------------------- |
| `-v`        | 查看gcc版本号                                     |
| `-E`        | 生成预处理文件                                    |
| `-S`        | 生成汇编文件                                      |
| `-c`        | 只编译，生成`.o`文件（目标文件）                  |
| `-I`        | 指定头文件所在的路径                              |
| `-L`        | 指定库文件所在的路径                              |
| `-l`        | 指定库的名字                                      |
| `-o`        | 指定生成的目标文件的名字                          |
| `-g`        | 包含调试信息，使用`gdb`调试需要添加`-g`参数       |
| `-On n=0~3` | 编译优化，n越大优化的越多                         |
| `-Wall`     | 提示更多警告<br />`gcc -o test -Wall test.c`      |
| `-D`        | 编译时定义宏<br />`gcc -o test test.c -D MAX=100` |

## 3. 静态库和共享（动态）库

#### 3.1 库的介绍

**库** 是二进制文件，是源代码文件的另一种表现形式，是加了密的源代码；是一些功能相近或者是相似的函数的集合体

- 提高代码的可重用性，而且还可以提高代码的健壮性
- 可以减少开发者的代码开发量，缩短开发周期

头文件：包含了库函数的声明

库文件：包含了库函数的代码实现

【:loudspeaker:】库不能单独使用，只能作为其他执行程序的一部分完成某些功能，也就是说只能被其他程序调用才能使用

#### 3.2 静态库（static library）`.a` 

静态库可以认为是一些目标代码的集合，是在可执行程序运行前就已经加入到执行码中，称为执行程序的一部分

静态库命名：`libxxx.a` 

###### 3.2.1 静态库的制作

`func1.c` `func2.c` `head.h` 

步骤：

1. 将 c源文件 生成对应的 `.o`文件

   `gcc -c func1.c func2.c`  
   `gcc -c func1 -o func1.o` & `gcc -c func2.c -o func2.o` 

2.  使用打包工具 `ar` 将准备好的  `.o`文件 打包为 `.a`文件

   - 在使用 `ar` 工具时需要添加参数 **rcs**  
     `r` 更新、`c` 创建、`s` 建立索引
   - 命令：`ar rcs 静态库名 .o文件`  
     `ar rcs libtest1.a func1.o func2.o` 

```Linux
>>> 
[xfk@centos SLib]$ tree
.
├── func1.c
├── func2.c
└── head.h

0 directories, 3 files
>>> 步骤1
[xfk@centos SLib]$ gcc -c func1.c func2.c
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
└── head.h

0 directories, 5 files
>>> 步骤2
[xfk@centos SLib]$ ar rcs libtest1.a func1.o func2.o
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── head.h
└── libtest1.a

0 directories, 6 files
```

###### 3.2.2 静态库的使用

`gcc -o main main.c -I头文件路径 -L库文件路径 -l库名（去除lib和.a）` 

1. `main.c` `head.h` `libtest1.a` 在同级目录的情况

   `gcc -o main main.c -I./ -L./ -ltest1` 

```Linux
>>> 在main.c中调用func1、func2（使用静态库1）
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── head.h
├── libtest1.a
└── main.c

0 directories, 7 files
>>> 
[xfk@centos SLib]$ gcc -o main main.c -I./ -L./ -ltest1
[xfk@centos SLib]$ ls
func1.c  func1.o  func2.c  func2.o  head.h  libtest1.a  main  main.c
>>> 
[xfk@centos SLib]$ ./main
main
func1
func2
```

2. `main.c` `head.h` `libtest1.a` 不在同级目录的情况

   `gcc -o main main.c -I./include -L./lib -ltest1` 

```Linux
>>> 在main.c中调用func1、func2（使用静态库2）
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── include
│   └── head.h
├── lib
│   └── libtest1.a
└── main.c

2 directories, 8 files
>>>
[xfk@centos SLib]$ gcc -o main main.c -I./include -L./lib -ltest1
[xfk@centos SLib]$ ls
func1.c  func1.o  func2.c  func2.o  include  lib  main  main.c
>>> 
[xfk@centos SLib]$ ./main 
main
func1
func2
```

#### 3.3 共享库（shared library）`.so` 

共享库在程序编译时不会被连接到目标代码中，而是在程序运行时才被载入；  
不同的应用程序如果调用相同的库，那么在内存里只需要一份该共享库的拷贝，规避了空间的浪费。

共享库命名：`libxxx.so` 

###### 3.3.1 共享库的制作

`func1.c` `func2.c` `head.h` 

步骤：

1. 生成目标文件 `.o` ,此时要加编译选项：`-fpic`  
   创建与地址无关的编译程序（pic，position independent code），目的就是为了能够在多个应用程序间共享

   `gcc -fpic -c func1.c func2.c` 

2. 生成共享库，此时要加链接器选项：`-shared`   
   指定生成动态链接库

   `gcc -shared func1.o func2.o -o libtest2.so` 

```Linux
>>>
[xfk@centos SLib]$ tree
.
├── func1.c
├── func2.c
└── head.h

0 directories, 3 files
>>> 步骤1
[xfk@centos SLib]$ gcc -fpic -c func1.c func2.c
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
└── head.h

0 directories, 5 files
>>> 步骤2
[xfk@centos SLib]$ gcc -shared func1.o func2.o -o libtest2.so
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── head.h
└── libtest2.so

0 directories, 6 files
```

###### 3.3.2 共享库的使用

`gcc -o main main.c -I头文件路径 -L库文件路径 -l库名（去除lib和.so）` 

1. `main.c` `head.h` `libtest2.so` 在同级目录的情况

   `gcc -o main main.c -I./ -L./ -ltest2` 

```Linux
>>> 在main.c中调用func1、func2（使用静态库1）
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── head.h
├── libtest2.so
└── main.c

0 directories, 7 files
>>> 
[xfk@centos SLib]$ gcc -o main main.c -I./ -L./ -ltest2
[xfk@centos SLib]$ ls
func1.c  func1.o  func2.c  func2.o  head.h  libtest2.so  main  main.c
>>> 
[xfk@centos SLib]$ ./main 
./main: error while loading shared libraries: libtest2.so: cannot open shared object file: No such file or directory
```

2. `main.c` `head.h` `libtest2.so` 不在同级目录的情况

   `gcc -o main main.c -I./include -L./lib -ltest2` 

```Linux
>>> 在main.c中调用func1、func2（使用静态库2）
[xfk@centos SLib]$ tree
.
├── func1.c
├── func1.o
├── func2.c
├── func2.o
├── include
│   └── head.h
├── lib
│   └── libtest2.so
└── main.c

2 directories, 8 files
>>>
[xfk@centos SLib]$ gcc -o main main.c -I./include -L./lib -ltest2
[xfk@centos SLib]$ ls
func1.c  func1.o  func2.c  func2.o  include  lib  main  main.c
>>> 
[xfk@centos SLib]$ ./main 
./main: error while loading shared libraries: libtest2.so: cannot open shared object file: No such file or directory
```

【:warning:】执行程序报错：  
`./main: error while loading shared libraries: libtest2.so: cannot open shared object file: No such file or directory`    
**找不到 libtest2.so** :exclamation: :exclamation: :exclamation: 

```Linux
[xfk@centos SLib]$ ldd main
        linux-vdso.so.1 =>  (0x00007ffdeeff8000)
        libtest2.so => not found
        libc.so.6 => /lib64/libc.so.6 (0x00007f32617c2000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f3261b8f000)
```

【:question:】 原因：

- 当系统加载可执行文件代码时，能够知道其所依赖的库的名字  
  **但是还需要知道所依赖的库的绝对路径**，此时就需要系统动态载入器（dynamic linker/loader）
- 对于ELF格式的可执行程序，是由 `ld-linux.so*` 来完成的，它先后搜索ELF文件  
  `DT_RPATH段` >>> `LD_LIBRARY_PATH环境变量` >>> `/etc/ld.so.cache文件列表` >>> `/lib,/user/lib 目录` 

```Linux
[xfk@centos SLib]$ file main
main: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=a6e3938ae6eb4ad589bbc24c5e37c9296b386c0d, not stripped
```

【:heavy_check_mark:】 解决：

- 拷贝自己制作的共享库到 `/lib` 或 `/user/lib`目录（不建议）

- 临时设置 `LD_LIBRARY_PATH` ：
  - 执行 `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径` 命令（测试临时生效）
- 永久设置  
  把 `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径` 设置到 `/etc/profile` 文件中（不建议）
- 永久设置  
  把 `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径` 设置到 `~/.bashrc` 文件中，然后执行一下方法之一：
  - 执行 `. ~/.bashrc` 使配置文件生效（第一个 `.` 后有一个空格）
  - 执行 `source ~/.bashrc` 使配置文件生效
  - 退出当前终端，然后再次登录使配置文件生效

```Linux
>>> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/lib
[xfk@centos SLib]$ echo $LD_LIBRARY_PATH
:/home/xfk/lib
[xfk@centos SLib]$ ./main
main
func1
func2
```

【:loudspeaker:】动态库文件在编译的时候，连接器需要使用参数 `-L` 找到库文件所在路径；  
             在执行的时候，加载器（ldd）根据动态库的路径进行加载，与编译时候用的 `-L` 路径无关。

---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 