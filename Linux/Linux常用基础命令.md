# Linux常用基础命令:kick_scooter: 

## 命令解析器:rotating_light: 

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

## 1. Linux常用快捷键:bookmark_tabs: 

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

## 2. Linux目录结构:cactus: 

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

## 3. 文件和目录相关的命令:pager: 

#### 3.1 tree 命令

- 以树状形式查看指定目录内容，使用该命令需要安装软件 tree  
  `sudo apt-get update`     `sudo apt-get install tree` 

- 使用方法：

  - `tree` 当前目录文件信息  
    `tree 目录` 指定目录文件信息

  【:loudspeaker:】只能查看目录内容，不能查看文件内容

```Linux
[xfk@centos ~]$ tree TESTDIR
TESTDIR
├── file.c
├── file.c.h
├── file.c.s -> /home/xfk/TESTDIR/file.c
├── function.c
├── print.c
├── test1.cpp
└── test1.cpp.bak

0 directories, 7 files
```

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

**创建硬链接（ 指向同一个 inode 互为硬链接，不可跨文件系统）** 

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

#### 3.19 wc 命令

**显示文件行数，单词数，字节数** 

- 使用方法：
  - `wc 文件`

- 相关选项

| 选项 | 含义             |
| ---- | ---------------- |
| -l   | 显示文件总行数   |
| -w   | 显示文件总单词数 |
| -c   | 显示文件总字节数 |

```Linux
>>>
[xfk@centos TESTDIR]$ wc file.c
10 15 96 file.c
[xfk@centos TESTDIR]$ wc -l file.c
10 file.c
[xfk@centos TESTDIR]$ wc -w file.c
15 file.c
[xfk@centos TESTDIR]$ wc -c file.c
96 file.c
```

#### 3.20 whoami 命令

**显示当前登录的用户名** 

- 使用方法：
  - `whoami` 

```Linux
>>>
[xfk@centos TESTDIR]$ whoami
xfk
[xfk@centos TESTDIR]$ echo $USER
xfk
```

## 4. 用户权限、用户、用户组:alien: 

#### 4.1 修改文件权限 chmod

- 文字设定
  - `chmod [who][+|-|=][mode],... 文件` 
    - 操作对象【who】  
      `u` 用户 `g` 同组用户 `o` 其他用户 `a` 所有用户（默认）
    - 操作符【+-=】  
      `+` 添加权限 `-` 撤销权限 `=` 赋予制定权限撤销其他权限
    - 权限【mode】  
      `r` 只读 `w` 只写 `x` 只执行

```Linux
[xfk@centos TESTDIR]$ ls -l function.c 
-rw-rw-r--. 1 xfk xfk 0 1月   9 20:36 function.c
>>>
[xfk@centos TESTDIR]$ chmod u+x,o+w function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-rwxrw-rw-. 1 xfk xfk 0 1月   9 20:36 function.c
>>>
[xfk@centos TESTDIR]$ chmod go-w function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-rwxr--r--. 1 xfk xfk 0 1月   9 20:36 function.c
>>>
[xfk@centos TESTDIR]$ chmod go=rx function.c
[xfk@centos TESTDIR]$ ls -l function.c 
-rwxr-xr-x. 1 xfk xfk 0 1月   9 20:36 function.c
```

- 数字设定

  - `chmod [+|-|=][数字],... 文件` 
    - 操作符【+-=】  
      `+` 添加权限 `-` 撤销权限 `=` 赋予制定权限撤销其他权限（默认）
    - 数字含义  
      `0` 无权限 `1` 执行权限 `2` 写权限 `4` 读权限

  【:loudspeaker:】一位数字o，两位数字go ，三位数字ugo  
               规范使用三位8进制数

```Linux
>>>
[xfk@centos TESTDIR]$ chmod 766 function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-rwxrw-rw-. 1 xfk xfk 0 1月   9 20:36 function.c
>>>
[xfk@centos TESTDIR]$ chmod +111 function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-rwxrwxrwx. 1 xfk xfk 0 1月   9 20:36 function.c
>>>
[xfk@centos TESTDIR]$ chmod 555 function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-r-xr-xr-x. 1 xfk xfk 0 1月   9 20:36 function.c
>>> 
[xfk@centos TESTDIR]$ chmod +2 function.c 
[xfk@centos TESTDIR]$ ls -l function.c 
-r-xr-xrwx. 1 xfk xfk 0 1月   9 20:36 function.c
```

#### 4.2 修改文件所有者和所属组 chown

**修改文件所有者/所属组** 

- 使用方法：

  - `chown 所有者 文件名`
  - `chown [所有者]:所属组 文件名` （所有者不改可省略）

  【:loudspeaker:】普通用户需要用管理员用户权限执行该命令 `sudo`   
               `sudo adduser` 创建新用户

```Linux
>>>
[xfk@centos TESTDIR]$ ls -l file.c
-rw-rw-r--. 2 xfk xfk 96 1月   9 23:34 file.c
[xfk@centos TESTDIR]$ sudo chown root file.c
[xfk@centos TESTDIR]$ ls -l file.c
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 file.c
>>> 
[xfk@centos TESTDIR]$ sudo chown root:root file.c
[xfk@centos TESTDIR]$ ls -l file.c
-rw-rw-r--. 2 root root 96 1月   9 23:34 file.c
```

####  4.3 修改文件所属组 chgrp

**修改文件所属组** 

- 使用方法：
  - `chown 所属组 文件名` 

```Linux
[xfk@centos TESTDIR]$ ls -l file.c
-rw-rw-r--. 2 root root 96 1月   9 23:34 file.c
[xfk@centos TESTDIR]$ sudo chgrp xfk file.c
[xfk@centos TESTDIR]$ ls -l file.c
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 file.c
```

## 5. 查找、过滤、压缩:postbox: 

#### 5.1 find 命令

**查找文件/目录**  

- 使用方法：
  - `find 路径 [选项] [参数]` 

- 相关选项

| 选项                           | 含义                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| -name                          | 按文件名查找 ["文件名"]                                      |
| -type                          | 按文件类型查找 [f/d/l/b/c/s/p]                               |
| -size                          | 按文件大小查找 [+大于\|-小于\|=等于] 大小 [M\|k\|c字节]      |
| -ctime<br />-mtime<br />-atime | 按文件创建日期 [-n/+n]<br />按文件修改日期 [-n/+n]<br />按文件访问日期 [-n/+n] |
| -maxdepth<br />-mindepth       | 搜索n层以下的目录，搜索的层数不超过n层<br />搜索n层以上的目录，搜索的层数不小于n层 |

```Linux
[xfk@centos TESTDIR]$ find ./ -name "file*"
./file.c.s
./file.c
./file.c.h
[xfk@centos TESTDIR]$ find ./ -type l
./file.c.s
普通文件 f、目录文件 d、设备文件（字符设备文件 c、块设备文件 b）
管道文件 p、软链接文件 l、套接字文件 s
[xfk@centos TESTDIR]$ find ./ -size 24c
./file.c.s
[xfk@centos TESTDIR]$ find ./ -size +10c -size -50c
./file.c.s
区间需要写两次-size
>>> 一天内创建文件
[xfk@centos TESTDIR]$ find ./ -ctime -1
./
./test1.cpp
./test1.cpp.bak
区间写两次-ctime
```

- 高级查找

  - `find 路径 [选项] [参数] -exec shell命令 {} \; `  
    `find 路径 [选项] [参数] -ok shell命令 {} \; `   
    - 查找当前目录下所有目录并列出文件详细信息  
      `find ./ -type d -exec ls -l {} \;`   
      `find ./ -type d -ok ls -l {} \;` 

  【:loudspeaker:】 ok比较安全（提示），特别是在rm删除文件的时候

  - `find 路径 [选项] [参数] | xargs shell命令`   
    `find ./ -type d | xargs ls -l`

```Linux
>>>
[xfk@centos TESTDIR]$ find ./ -name "file*" -exec ls -l {} \;
lrwxrwxrwx. 1 xfk xfk 24 1月  10 00:40 ./file.c.s -> /home/xfk/TESTDIR/file.c
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 ./file.c
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 ./file.c.h
>>> 
[xfk@centos TESTDIR]$ find ./ -name "file*" | xargs ls -l
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 ./file.c
-rw-rw-r--. 2 root xfk 96 1月   9 23:34 ./file.c.h
lrwxrwxrwx. 1 xfk  xfk 24 1月  10 00:40 ./file.c.s -> /home/xfk/TESTDIR/file.c
```

#### 5.2 grep 命令

**文本搜索** 

- 使用方法：
  - `grep [选项] "查找的内容" 路径`
- 相关选项

| 选项 | 含义                 |
| ---- | -------------------- |
| -r   | 目录递归搜索         |
| -n   | 显示查找内容所在行号 |
| -i   | 忽略大小写           |
| -v   | 不显示含有某字符串   |

```Linux
[xfk@centos TESTDIR]$ grep -rin "include" ./
./print.c:1:#include <tsdio.h>
./file.c:1:#include <tsdio.h>
./file.c.h:1:#include <tsdio.h>
```

【:loudspeaker:】find结合grep   
             `find ./ -name "file*" | xargs grep -n "main"` 

```Linux
[xfk@centos TESTDIR]$ find ./ -name "file*" | xargs grep -n "main"
./file.c.s:6:int main()
./file.c:6:int main()
./file.c.h:6:int main()
```

#### 5.3 压缩工具

- **gzip **和 **bzip2** 

【:loudspeaker:】不能压缩目录，只能一个一个文件进行压缩，压缩之后会使源文件消失

| 命令      | 含义                       |
| --------- | -------------------------- |
| gzip *    | 压缩当前目录下所有文件     |
| gunzip *  | 解压当前目录下所有.gz文件  |
| bzip2 *   | 压缩当前目录下所有文件     |
| bunzip2 * | 解压当前目录下所有.bz2文件 |

```Linux
[xfk@centos TESTDIR]$ ls -l
-r-xrwxrwx. 1 xfk  xfk  0 1月   9 20:36 function.c
-rw-rw-r--. 1 xfk  xfk 96 1月   9 23:35 print.c
-rw-rw-r--. 1 xfk  xfk  0 1月   9 21:18 test1.cpp
-rw-rw-r--. 1 xfk  xfk  0 1月   9 21:30 test1.cpp.bak
[xfk@centos TESTDIR]$ gzip *
[xfk@centos TESTDIR]$ ls -l
-r-xrwxrwx. 1 xfk  xfk  31 1月   9 20:36 function.c.gz
-rw-rw-r--. 1 xfk  xfk 107 1月   9 23:35 print.c.gz
-rw-rw-r--. 1 xfk  xfk  34 1月   9 21:30 test1.cpp.bak.gz
-rw-rw-r--. 1 xfk  xfk  30 1月   9 21:18 test1.cpp.gz
```

- **tar** 

| 选项 | 含义                      |
| ---- | ------------------------- |
| z    | 用gzip来压缩/解压文件     |
| j    | 用bzip2来压缩/解压文件    |
| c    | 创建新的压缩文件，与x互斥 |
| x    | 解压压缩文件，与c互斥     |
| v    | 详细报告tar处理的文件信息 |
| f    | 指定压缩文件的名字        |
| t    | 查看压缩包中有哪些文件    |

1. 压缩方法：
   - `tar cvf xxx.tar 原材料[要打包压缩的文件或目录]`  
     `tar zcvf xxx.tar.gz 原材料[要打包压缩的文件或目录]`  
     `tar jcvf xxx.tar.bz2 原材料[要打包压缩的文件或目录]`  

2. 解压缩方法：
   - `tar xvf  压缩包` （xxx.tar）  
     `tar zxvf  压缩包` （xxx.tar.gz）  
     `tar jxvf  压缩包` （xxx.tar.bz2）   
     解压到指定目录：添加参数 `-C 目录（必须存在）` （默认当前目录）

3. 查看压缩包内文件 `tar tvf 压缩包`

```Linux
>>> 压缩
[xfk@centos TESTDIR]$ tar zcvf mytar.tar.gz print.c.gz function.c.gz 
print.c.gz
function.c.gz
[xfk@centos TESTDIR]$ ls
file.c  file.c.h  file.c.s  function.c.gz  mytar.tar.gz  print.c.gz  test1.cpp.bak.gz  test1.cpp.gz
>>> 查看
[xfk@centos TESTDIR]$ tar tvf mytar.tar.gz 
-rw-rw-r-- xfk/xfk         107 2023-01-09 23:35 print.c.gz
-r-xrwxrwx xfk/xfk          31 2023-01-09 20:36 function.c.gz
>>> 解压
[xfk@centos TESTDIR]$ tar zxvf mytar.tar.gz -C ../MYTAR
print.c.gz
function.c.gz
[xfk@centos TESTDIR]$ ls -l ../MYTAR
总用量 8
-r-xrwxr-x. 1 xfk xfk  31 1月   9 20:36 function.c.gz
-rw-rw-r--. 1 xfk xfk 107 1月   9 23:35 print.c.gz
```

- zip
  1. 压缩 `zip [-r] 压缩包名 要压缩的文件（含文件和目录）`   
     生成 `xxx.zip` 文件
  2. 解压 `unzip 压缩包 [-d 解压目录（不存在创建）]`

```Linux
>>> 压缩
[xfk@centos TESTDIR]$ zip xxx aa.c bb.c 
  adding: aa.c (stored 0%)
  adding: bb.c (stored 0%)
[xfk@centos TESTDIR]$ ls -l xxx.zip 
-rw-rw-r--. 1 xfk xfk 294 1月  11 01:03 xxx.zip
>>> 解压
[xfk@centos TESTDIR]$ unzip xxx.zip -d ./ZIP
Archive:  xxx.zip
 extracting: ./ZIP/aa.c              
 extracting: ./ZIP/bb.c
[xfk@centos TESTDIR]$ ls -ld ZIP
drwxrwxr-x. 2 xfk xfk 30 1月  11 01:05 ZIP
```

## 6. 软件安装和卸载:computer: 

#### 6.1 在线安装

- Centos
  - yum：rpm包软件管理器，用于自动化安装配置Linux软件，并可以自动解决依赖问题
    - 语法：`yum [-y] [install|remove|search] 软件名`
    - 选项：-y，自动确认
    - install安装，remove卸载，search搜索
- Ubuntu
  - apt：deb包
  - 语法：`apt [-y] [install|remove|search] 软件名`

---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 
