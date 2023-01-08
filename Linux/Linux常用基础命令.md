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



#### 3.2 ls 命令



#### 3.3 cd 命令



#### 3.4 pwd 命令



#### 3.5 which 命令



#### 3.6 touch 命令



#### 3.7 mkdir 命令



#### 3.8 rmdir 命令



#### 3.9 rm 命令



#### 3.10 cp 命令



#### 3.11 mv 命令

