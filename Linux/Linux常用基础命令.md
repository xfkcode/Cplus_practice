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

- 相关参数

| 参数 | 含义                                                         |
| ---- | ------------------------------------------------------------ |
| -a   | 列出当前目录下的**所有**文件信息（包括隐藏文件）             |
| -R   | 递归方式列出所有目录中的内容                                 |
| -l   | 列出文件的详细信息                                           |
| -ltr | 列出当前目录下的文件，按照时间逆向排序（**t**ime **r**everse） |

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
- 相关参数

| 参数 | 含义         |
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
- 相关参数

| 参数 | 含义             |
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



#### 3.11 mv 命令

