# Linux常用基础命令

## 命令解析器

- shell 命令解析器
- 作用：对用户输入到终端的命令解析成内核能够识别的指令，调用对应的执行程序

【:loudspeaker:】shell 命令解析器按照 `$PATH` 环境变量搜索命令

Liunx系统结构：

**用户 >> |图形界面| >> 应用层 >> |shell 命令| >> shell 层 >> |系统调用| >> 内核层 >> |驱动指令| >> 硬件** 

- 常用的命令解析器
  - shell -- Bourne Shell
    - /bin/sh
  - bash -- Bourne Again Shell
    - /bin/bash

当前系统所使用的 shell  `echo $AHELL`   
当前系统下有哪些 shell `cat /etc/shells` 

```Linux
[xfk@centos ~]$ echo $SHELL
/bin/bash
[xfk@centos ~]$ cat /etc/shells
/bin/sh
/bin/bash
/usr/bin/sh
/usr/bin/bash
/bin/tcsh
/bin/csh
```

## 1. Linux常用快捷键

#### 1.1 tab 键

- 补齐命令
- 补齐文件（包括目录和文件）

#### 1.2 主键盘快捷键

- 遍历输入的历史命令

  - 从当前位置向上遍历：`Ctrl+p` :arrow_up_small: 
  - 从当前位置向上遍历：`Ctrl+n` :arrow_down_small: 

  【:loudspeaker:】`history` 可显示用户输入的所有命令

- 光标位置移动
  - 左移：`Ctrl+b` :arrow_backward: 
  - 右移：`Ctrl+f` :arrow_forward: 
  - 移动到头部：`Ctrl+a` （home）
  - 移动到尾部：`Ctrl+e` （end）
- 字符删除
  - 删除光标前边的字符：`Ctrl+h ` 
  - 删除光标后边的字符：`Ctrl+d` 
  - 删除光标前所有字符：`Ctrl+u` 
  - 删除光标后所有字符：`Ctrl+k `  

## 2. Linux目录结构

**Linux系统的目录结构是一个倒立的树状结构**（根目录 `/`） 

#### 2.1 主要目录介绍

- `/bin` ：binary，二进制文件，可执行文件 ，shell命令
- `/sbin` ：s是Super User的意思，这里存放的是系统管理员使用的系统管理程序
- `/dev` ：device，在Linux下一切皆文件
  - 硬盘，显卡，显示器
  - 字符设备文件，块设备文件
- `/lib` ：Linux运行时需要加载的动态库
- `/mnt`：手动挂载目录，如U盘
- `/media`：外设的自动挂载目录，如光驱
- `/root`：Linux的超级用户root的家目录
- `/user`：Unix system resource -- 类似于Windows的programe files目录
  - include目录存放头文件
- `/etc`：存放配置文件
  - profile系统的配置文件
- `/opt`：安装第三方应用程序
- `/home`：Linux操作系统所有用户的家目录
- `/tmp`：存放临时文件
  - 新建在这个目录下的文件会在系统重启后自动清除

#### 2.2 路径（绝对/相对）

- 绝对路径：根目录开始直到到达目标文件所经过的所有节点目录  
      				1️⃣ `/.../...` 
- 相对路径：目标目录相对于当前目录的位置  
      		        1️⃣ `./` 当前目录  
            		        2️⃣ `../` 上级目录

- Linux命令提示符：`[xfk@centos ~]$` 
  - `xfk`：当前登录用户
  - `@`：at 在的意思
  - `centos`：主机名
  - `~`：当前工作目录（家目录）
  - `$/#`：命令提示符（普通用户/超级用户）

## 3. 文件和目录相关的命令

#### 3.1 tree 命令

- 以树状形式查看指定目录内容，使用该命令需要安装软件 tree  
  `sudo apt-get update`     `sudo apt-get install tree` 

- 使用方法：

  - `tree` 当前目录文件信息  
    `tree 目录` 指定目录文件信息

  【:loudspeaker:】只能查看目录内容，不能查看文件内容

#### 3.2 ls 命令

**查看指定目录下的文件信息**

- 使用方法：
  - `ls` 显示当前目录下文件信息  
    `ls 目录/文件` 显示指定目录下文件信息

- 相关选项

| 选项 | 含义                                                         |
| ---- | ------------------------------------------------------------ |
| -a   | 列出当前目录下的**所有**文件信息（包括隐藏文件）             |
| -R   | 递归方式列出所有目录中的内容                                 |
| -l   | 列出文件的详细信息                                           |
| -ltr | 列出当前目录下的文件，按照时间逆向排序（**t**ime **r**everse） |
| -i   | 可查看文件 **inode** 硬链接                                  |

```Linux
[xfk@centos ~]$ ls -l
drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Music
//1.文件属性—>文件类型、文件访问权限
  普通文件 -、目录文件 d、设备文件（字符设备文件 c、块设备文件 b）
  管道文件 p、软链接文件 l、套接字文件 s
//2.硬链接计数
//3.文件所有者
//4.文件所属组
//5.文件占用空间大小（Byte）
//6.文件最后修改时间
//7.文件名
```

#### 3.3 cd 命令

**切换目录**

- 使用方法：
  - `cd 目录` 切换至指定目录（绝对/相对）

```Linux
切换至家目录
cd
cd ~
cd /home/xfk
cd $HOME
切换至上一个工作目录
cd - 
```

#### 3.4 pwd 命令

**查看当前所处工作目录** 

- 使用方法：
  - `pwd` （print working directory）

```Linux
[xfk@centos ~]$ pwd
/home/xfk
```

#### 3.5 which 命令

**显示命令所在的目录** 

- 使用方法：
  - `which 命令` 

```Linux
[xfk@centos ~]$ which cd
/usr/bin/cd
```

#### 3.6 touch 命令

**如果文件不存在，创建新文件，如果文件存在，更新文件的最后修改时间** 

- 使用方法：
  - `touch 文件名` 

```Linux
>>> 创建新文件
[xfk@centos ~]$ touch func.c
[xfk@centos ~]$ ls -l func.c 
-rw-rw-r--. 1 xfk xfk 0 1月   9 20:35 func.c
>>> 更新修改时间
[xfk@centos ~]$ touch func.c
[xfk@centos ~]$ ls -l func.c 
-rw-rw-r--. 1 xfk xfk 0 1月   9 20:36 func.c
```

#### 3.7 mkdir 命令

创建新目录 make directory

- 使用方法：
  - `mkdir 目录名` 当前目录下创建  
    `mkdir 路径/目录名` 指定目录下创建
- 相关选项

| 选项 | 含义         |
| ---- | ------------ |
| -p   | 创建多级目录 |

```Linux
>>> 创建多级目录
[xfk@centos ~]$ mkdir -p ./TESTDIR/aa/bb/cc
[xfk@centos ~]$ ls -R TESTDIR/
TESTDIR/:
aa
TESTDIR/aa:
bb
TESTDIR/aa/bb:
cc
TESTDIR/aa/bb/cc:

```

#### 3.8 rmdir 命令

**删除空目录（只能删除空目录）** 

- 使用方法：
  - `rmdir 目录名` 

```Linux
[xfk@centos TESTDIR]$ rmdir aa
rmdir: 删除 "aa" 失败: 目录非空
[xfk@centos TESTDIR]$ mkdir bb
[xfk@centos TESTDIR]$ ls -R 
.:
aa  bb
./aa:
bb
./aa/bb:
cc
./aa/bb/cc:

./bb:

[xfk@centos TESTDIR]$ rmdir bb
[xfk@centos TESTDIR]$ rmdir bb
[xfk@centos TESTDIR]$ ls
aa
```

#### 3.9 rm 命令

**删除文件/目录** 

- 使用方法：
  - `rm 文件` 删除文件  
    `rm -r 目录` 删除目录
- 相关选项

| 选项 | 含义             |
| ---- | ---------------- |
| -r   | 递归删除目录     |
| -i   | 提示用户是否删除 |
| -f   | 强制删除         |

```Linux
[xfk@centos ~]$ rm -ri TESTDIR/
rm：是否进入目录"TESTDIR/"? y
rm：是否进入目录"TESTDIR/aa"? y
rm：是否进入目录"TESTDIR/aa/bb"? y
rm：是否删除目录 "TESTDIR/aa/bb/cc"？y
rm：是否删除目录 "TESTDIR/aa/bb"？y
rm：是否删除目录 "TESTDIR/aa"？y
rm：是否删除目录 "TESTDIR/"？y
[xfk@centos ~]$ ls TESTDIR
ls: 无法访问TESTDIR: 没有那个文件或目录
```

#### 3.10 cp 命令

**复制文件/目录** 

- 使用方法：

  - `cp 源文件/目录 目标文件/目录`   

  【:loudspeaker:】`cp file1 file2（不存在）` 拷贝新建文件  
               `cp file1 file2（存在）` 覆盖  
               `cp file dir(必须存在) `  
               `cp -r dir1 dir2（不存在）` 拷贝新建目录以及内容文件  
               `cp -r dir1 dir2（存在）` 创建拷贝子目录

- 相关选项

| 选项 | 含义                                 |
| ---- | ------------------------------------ |
| -a   | 属性信息拷贝（修改创建时间一并拷贝） |
| -r   | 递归拷贝（目录）                     |
| -i   | 提示用户（覆盖）                     |
| -f   | 强制覆盖                             |

```Linux
>>> 拷贝新文件
[xfk@centos TESTDIR]$ touch test1.cpp
[xfk@centos TESTDIR]$ cp test1.cpp test1.cpp.bak
[xfk@centos TESTDIR]$ ls
test1.cpp  test1.cpp.bak
>>> 文件拷贝到目录
[xfk@centos ~]$ touch aa.c
[xfk@centos ~]$ cp aa.c ./TESTDIR_bak/
[xfk@centos ~]$ ls TESTDIR_bak/
aa.c
>>> 目录拷贝到目录（子目录）
[xfk@centos ~]$ cp -r TESTDIR TESTDIR_bak/
[xfk@centos ~]$ ls ./TESTDIR_bak/
aa.c  TESTDIR
```

#### 3.11 mv 命令

**移动或者改名文件/目录** 

- 使用方法：
  - 移动（第二个参数必须是目录）  
    `mv file dir（必须存在）` 将文件移动到指定目录中  
    `mv dir1 dir2（必须存在）` 将dir1移动到dir2作为子目录
  - 改名  
    `mv file1 file2（不存在）`  
    `mv dir1 dir2（不存在）`  
    `mv file1 file2（存在）` 覆盖改名

```Linux
>>> 文件移动
[xfk@centos ~]$ mv func.c TESTDIR
[xfk@centos ~]$ ls func,c
ls: 无法访问func,c: 没有那个文件或目录
[xfk@centos ~]$ ls TESTDIR
func.c  test1.cpp  test1.cpp.bak
>>> 文件改名
[xfk@centos TESTDIR]$ mv func.c function.c
[xfk@centos TESTDIR]$ ls
function.c  test1.cpp  test1.cpp.bak
```

#### 3.12 cat 命令

**将文件内容一次性输出到终端** 

- 使用方法：

  -  `cat 文件` 

  【:loudspeaker:】文件重定向 `cat file1 > file2` 相当于 `cp file1 file2` 

```Linux
>>> 显示文件内容
[xfk@centos TESTDIR]$ cat file.c 
#include <tsdio.h>
void print()
{
        printf("hello world");
}
int main()
{
        print();
        return o;
}
>>> cat+> 实现拷贝
[xfk@centos TESTDIR]$ cat file.c > print.c
[xfk@centos TESTDIR]$ ls
file.c  function.c  print.c  test1.cpp  test1.cpp.bak
```

#### 3.13 more 命令

**分页显示文件内容到终端，只能向下浏览，不能回退** 

- 使用方法：
  - `more 文件`   
    显示下一行 `回车`   
    显示下一页 `空格`   
    退出 `q` `Ctrl+c`

#### 3.14 less 命令

**分页显示文件内容到终端，可以自由上下浏览** 

- 使用方法：
  - `less 文件`  
    显示下一行 `Ctrl+p` :arrow_down_small: `回车`  
    显示上一行 `Ctrl+n` :arrow_up_small:   
    显示下一页 `PageDown` `空格`  
    显示上一页 `PageUp`  
    退出 `q` `Ctrl+c` 

#### 3.15 head 命令

**从文件头部开始查看前n行内容** 

- 使用方法：
  - `head [-n] 文件 `   
     如果没有指定行数，默认10行

#### 3.16 tail 命令

**从文件尾部开始查看后n行内容** 

- 使用方法：

  - `tail [-n] 文件 `   
     如果没有指定行数，默认10行

  【:loudspeaker:】监视日志 `tail -f test.log`   
               一个终端 `tail -f test.log` 另一个终端 `echo "hello world" >> test.log)` （重定向`>>`追加）

#### 3.17 软链接

**创建软链接（类似于Windows的快捷方式）** 

- 使用方法：

  - `ln -s 文件/目录 软链接名` 

  【:loudspeaker:】创建软链接源文件用绝对路径，否则移动链接文件后，就找不到指向文件（移动源文件失效）  
               软链接文件大小：路径+文件名的总字节数

```Linux
[xfk@centos TESTDIR]$ ln -s /home/xfk/TESTDIR/file.c file.c.s
[xfk@centos TESTDIR]$ ls -l file.c.s
lrwxrwxrwx. 1 xfk xfk 24 1月  10 00:40 file.c.s -> /home/xfk/TESTDIR/file.c
```

#### 3.18 硬链接

**创建硬链接（ 指向同一个 inode 互为硬链接）** 

- 使用方法：

  - `ln 文件（目录不可以） 硬链接名` 

  【:loudspeaker:】作用：1.同步文件 2.保护文件  
               创建硬链接计数+1，删除-1  
               `stat 文件` `ls -i 文件` 可查看文件  inode

```Linux
>>> 创建硬链接
[xfk@centos TESTDIR]$ ls -li file.c
102680741 -rw-rw-r--. 1 xfk xfk 96 1月   9 23:34 file.c
[xfk@centos TESTDIR]$ ln file.c file.c.h
[xfk@centos TESTDIR]$ ls -li file*
102680741 -rw-rw-r--. 2 xfk xfk 96 1月   9 23:34 file.c
102680741 -rw-rw-r--. 2 xfk xfk 96 1月   9 23:34 file.c.h
102680740 lrwxrwxrwx. 1 xfk xfk 24 1月  10 00:40 file.c.s -> /home/xfk/TESTDIR/file.c
```

#### 3.19 wc



#### 3.20 whoami
