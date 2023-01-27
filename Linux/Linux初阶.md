# Linux初阶:boxing_glove: 

### 1. Linux文件系统🗃️

#### 1.1 目录结构 

- `/` : 根目录
- `/bin` : 可执行二进制文件
- `/dev` : 设备文件
- `/etc` : 配置文件
- `/home` : 用户家目录
- `/lib` : 系统库函数
- `/root` : 系统管理员root的家目录
- `/tmp` : 临时文件
- `/usr` : 用户应用程序（`/usr/lib`库，`/usr/include`头文件）

#### 1.2 路径

- 绝对路径：根目录开始直到到达目标文件所经过的所有节点目录  
                     1️⃣ `/.../...` 
- 相对路径：目标目录相对于当前目录的位置  
                     1️⃣ `./` 当前目录  
                     2️⃣ `../` 上级目录

```
cd   //回家目录
cd ~ //回家目录（等价 cd）
cd - //回上一次工作目录
```

#### 1.3 文件分类

**Unix/Linux** 系统中常用的文件类型有 ***7*** 种：

- [x] **普通文件 -、目录文件 d、设备文件（字符设备文件 c、块设备文件 b）** 
  **管道文件 p、软链接文件 l、套接字文件 s** 

```
ls -l
>>> drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Music
//1.文件属性—>文件类型、文件访问权限
//2.硬链接计数
//3.文件所有者
//4.文件所属组
//5.文件占用空间大小（Byte）
//6.文件最后修改时间
//7.文件名
```

```
文件访问权限：
>>> rwxr-xr-x
//r读 w写 x执行 -无权限
//三组：文件所有者 文件所属组 其他用户
```

### 2. Linux命令🥽

Linux命令格式：  
`command [-options] [parameter1] ...` 

- command：命令名
- [-options]：选项
- parameter1 ... ：参数可多个

Linux帮助文档：  
`command --help` 

Linux man手册：man 是系统的手册分页程序  
`man [选项] 命令名`

1. 可执行程序或shell命令
2. 系统调用（内核提供的函数）
3. 库调用（程序库中的函数）

Linux 热键：

| 热键   | 含义       |
| ------ | ---------- |
| Ctrl+p | 上一条命令 |
| Ctrl+n | 下一条命令 |
| Ctrl+u | 清空       |
| Ctrl+a | 光标置前   |
| Ctrl+e | 光标置后   |

#### 2.1 常用命令

##### 2.1.1 文件管理

###### 1）ls 查看文件信息

Linux 通配符：

`*` 表示0-n个字符

`?` 表示1个字符

| 通配符   | 含义                                        |
| -------- | ------------------------------------------- |
| ls te*   | 查找以te开头的文件                          |
| ls *html | 查找结尾为html的文件                        |
| ls ?.c   | 查找第一个字符任意，后面字符为.c 的文件     |
| ls a.?   | 查找前两个字符为a. ，最后一个字符任意的文件 |

###### 2）> / >> 输出重定向

```
ls > outfile		//outfile不存在创建，存在覆盖
cat outfile
>>> 
        Desktop
        Documents
        Downloads
        Music
        ...
ls -l >> outflie	//outfile追加内容
cat outfile
>>>
		Desktop
        Documents
        Downloads
        Music
        ...
        drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Desktop
        drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Documents
        drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Downloads
        drwxr-xr-x. 2 xfk  xfk    6 11月 17 16:39 Music
		...
```

###### 3）clear 清屏

​		快捷键 **Ctrl+l**

###### 4）cd 切换目录

​		[参见1.2 路径](####1.2 路径) 

###### 5）pwd 显示当前路径

```
[xfk@centos ~]$ pwd
/home/xfk
```

###### 6）mkdir 创建目录

```
[xfk@centos ~]$ mkdir testfiles
[xfk@centos ~]$ ls
Desktop  Documents  Downloads  Music  ...  testfiles  Videos  work.txt  yum.conf
```

###### 7）rm 删除文件

| 参数 | 含义                                 |
| ---- | ------------------------------------ |
| -i   | 以进行交互式方式执行                 |
| -f   | 强制删除，忽略不存在的文件，无需提示 |
| -r   | 递归的删除目录下的内容               |

```
[xfk@centos ~]$ rm testfiles
rm: 无法删除"testfiles": 是一个目录
[xfk@centos ~]$ rm -ri testfiles
rm：是否删除目录 "testfiles"？y
[xfk@centos ~]$ ls
Desktop  Documents  Downloads  Music  ...  Videos  work.txt  yum.conf
```

###### 8）cat 查看或合并文件内容

```
[xfk@centos ~]$ cat 1.txt
xfk
[xfk@centos ~]$ cat 2.txt
tq
[xfk@centos ~]$ cat 1.txt 2.txt > 3.txt
[xfk@centos ~]$ cat 3.txt
xfk
tq
```

###### 9）cp 拷贝文件

| 参数 | 含义                                   |
| ---- | -------------------------------------- |
| -i   | 交互式复制，在覆盖目标文件之前给出提示 |
| -f   | 覆盖已存在的目标文件不提示             |
| -r   | 递归复制目录下所有文件                 |

```
>>>文件拷贝
[xfk@centos ~]$ cp outfile ./outfile1				//不存在创建
[xfk@centos ~]$ ls -l outfile1
-rw-rw-r--. 1 xfk xfk 978 1月   5 18:49 outfile1

>>>目录拷贝
[xfk@centos ~]$ ls Testdir
abc.c  outfile  test.txt
[xfk@centos ~]$ cp -r  Testdir ./Testdir_cp
[xfk@centos ~]$ ls Testdir_cp
abc.c  outfile  test.txt
```

###### 10）mv 移动文件

移动文件或目录、改名

```
>>>文件转移
[xfk@centos ~]$ ls
Desktop    Downloads  outfile   Pictures  ...  test1.txt  test2.txt  Testdir_cp  work.txt
[xfk@centos ~]$  mv -i test1.txt ./Testdir				//test1.txt文件转移，原目录移除
[xfk@centos ~]$ ls
Desktop    Downloads  outfile   Pictures  Templates  test1  test2.txt  Testdir_cp  work.txt
Documents  Music      outfile1  Public    test       test2  Testdir    Videos      yum.conf
[xfk@centos ~]$ ls ./Testdir						//目标目录出现test.txt
abc.c  outfile  test1.txt  test.txt

>>>目录转移
[xfk@centos ~]$ ls -ld mvdir						//mvdir文件转移
drwxrwxr-x. 2 xfk xfk 47 1月   5 22:00 mvdir
[xfk@centos ~]$ mv mvdir ./Testdir
[xfk@centos ~]$ ls -ld mvdir
ls: 无法访问mvdir: 没有那个文件或目录
[xfk@centos ~]$ ls -ld ./Testdir
drwxrwxr-x. 3 xfk xfk 80 1月   5 22:02 ./Testdir

>>>改名（同一个目录下）
[xfk@centos ~]$ ls -ld test
dr---w---x. 3 root root 17 11月 17 19:37 test
[xfk@centos ~]$ mv test TEST
[xfk@centos ~]$ ls -ld TEST
dr---w---x. 3 root root 17 11月 17 19:37 TEST
```

###### 11）file 查看文件属性

```
>>> file 文件名
[xfk@centos dev]$ file log
log: socket
[xfk@centos dev]$ file core 
core: symbolic link to `/proc/kcore'
```

###### 12）tar 归档管理

备份工具，可以把一系列文件归档到一个打文件中，也可以把档案文件解开以恢复数据（打包文件并不压缩）。

`tar [zcvf/jcvf] 打包文件名xxx.tar.gz/bz2 文件 ...` <<<**打包压缩**  
压缩zcvf：z -> gzip   解压tar zxvf xxx.tar.gz  
压缩jcvf：j -> bzip2  解压tar jxvf xxx.tar.bz2 

| 参数 | 含义                                                  |
| ---- | ----------------------------------------------------- |
| -c   | 生成档案文件，创建打包文件                            |
| -f   | 指定档案文件名称，f后面一定是.tar文件，必须放选项最后 |
| -v   | 列出归档解档的详细过程，显示进度                      |
| -x   | 解压                                                  |

```
>>>压缩
[xfk@centos ~]$ cd ./Testdir
[xfk@centos Testdir]$ ls
abc.c  mvdir  outfile  test1.txt  test.txt
[xfk@centos Testdir]$ tar zcvf xxx.tar.gz abc.c outfile mvdir					//参数-可省略，gzip压缩
abc.c
outfile
mvdir/
mvdir/abc.c
mvdir/abc.h
mvdir/abc.txt
[xfk@centos Testdir]$ ls
abc.c  mvdir  outfile  test1.txt  test.txt  xxx.tar.gz
[xfk@centos Testdir]$ file  xxx.tar.gz
xxx.tar.gz: gzip compressed data, from Unix, last modified: Thu Jan  5 22:38:41 2023

>>>解压
[xfk@centos Testdir_cp]$ ls
abc.c  outfile  test.txt  xxx.tar.gz
[xfk@centos Testdir_cp]$ tar zxvf xxx.tar.gz
abc.c
outfile
mvdir/
mvdir/abc.c
mvdir/abc.h
mvdir/abc.txt
[xfk@centos Testdir_cp]$ ls
abc.c  mvdir  outfile  test.txt  xxx.tar.gz
```

##### 2.1.2 用户、权限管理

###### 1）su  切换用户

| 命令             | 含义                                     |
| ---------------- | ---------------------------------------- |
| su / su root     | 切换到 root 用户                         |
| su - / su - root | 切换到root用户，同时切换目录到/root      |
| su 普通用户      | 切换到普通用户                           |
| su - 普通用户    | 切换到普通用户，同时切换目录到用户家目录 |

```
[xfk@centos ~]$ su -
Password: 											//隐藏输入密码
Last login: Thu Jan  5 23:07:05 CST 2023 on pts/0
[root@centos ~]#
```

###### 2）passwd 修改密码

```
[xfk@centos ~]$ passwd
Changing password for user xfk.
Changing password for xfk.
(current) UNIX password: 
New password: 
BAD PASSWORD: The password is shorter than 8 characters
New password: 
Retype new password: 
passwd: all authentication tokens updated successfully.
```

###### 3）chmod 修改文件权限

字母法：`chmod [u/g/o/a] [+/-/=] [rwx] 文件`   
**u**文件所有者 **g**文件所属组 **o**其他用户 **a**以上三种  
**+**增加权限 **-**撤销权限 **=**设定权限  
**r**读 **w**写 **x**执行

```
>>>g-rwx，所属组权限撤销rwx
[xfk@centos ~]$ ls -ld Testdir
drwxrwxr-x. 3 xfk xfk 80 Jan  5 22:51 Testdir
[xfk@centos ~]$ chmod g-rwx Testdir
[xfk@centos ~]$ ls -ld Testdir
drwx---r-x. 3 xfk xfk 80 Jan  5 22:51 Testdir

>>>g=x,所属组权限这是为只执行x
[xfk@centos ~]$ ls -ld Testdir
drwxrwxr-x. 3 xfk xfk 80 Jan  5 22:51 Testdir
[xfk@centos ~]$ chmod g=x Testdir
[xfk@centos ~]$ ls -ld Testdir
drwx--xr-x. 3 xfk xfk 80 Jan  5 22:51 Testdir
```

数字法：`chmod [u/g/o/a =] 数字 文件`  

| rwx        | 数字 |
| ---------- | ---- |
| ---（000） | 0    |
| --x（001） | 1    |
| -w-（010） | 2    |
| -wx（011） | 3    |
| r--（100） | 4    |
| r-x（101） | 5    |
| rw-（110） | 6    |
| rwx（111） | 7    |

```
>>>421/u=r,g=w,o=x,所属者只读，所属组只写，其他用户只执行
[xfk@centos ~]$ ls -ld Testdir
drwx--xr-x. 3 xfk xfk 80 Jan  5 22:51 Testdir
[xfk@centos ~]$ chmod 421 Testdir
[xfk@centos ~]$ ls -ld Testdir
dr---w---x. 3 xfk xfk 80 Jan  5 22:51 Testdir

>>>[-R],递归修改目录所有文件
[xfk@centos ~]$ chmod 777 Testdir -R
[root@centos xfk]# ls -l Testdir
total 4
-rwxrwxrwx. 1 xfk xfk   0 Jan  5 18:56 abc.c
drwxrwxrwx. 2 xfk xfk  47 Jan  5 22:00 mvdir
-rwxrwxrwx. 1 xfk xfk 152 Jan  5 18:58 outfile
-rwxrwxrwx. 1 xfk xfk   0 Jan  5 18:57 test.txt
[root@centos xfk]# chmod 666 Testdir -R
[root@centos xfk]# ls -l Testdir
total 4
-rw-rw-rw-. 1 xfk xfk   0 Jan  5 18:56 abc.c
drw-rw-rw-. 2 xfk xfk  47 Jan  5 22:00 mvdir
-rw-rw-rw-. 1 xfk xfk 152 Jan  5 18:58 outfile
-rw-rw-rw-. 1 xfk xfk   0 Jan  5 18:57 test.txt
```

##### 2.1.3 系统管理

###### 1）ps 查看进程

**进程** 是一个具有一定独立功能的程序，它是操作系统动态执行的基本单元。

| 选项 | 含义                   |
| ---- | ---------------------- |
| -a   | 显示终端上所有进程     |
| -u   | 显示进程的详细状态     |
| -x   | 显示没有控制终端的进程 |
| -w   | 显示加宽               |
| -r   | 只显示正在运行的进程   |

```
>>>
[xfk@centos ~]$ ps aux 
USER        PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root          1  0.0  0.4 193804  4600 ?        Ss   03:06   0:11 /usr/lib/systemd/systemd --switched-root --s
root          2  0.0  0.0      0     0 ?        S    03:06   0:00 [kthreadd]
root          3  0.0  0.0      0     0 ?        S    03:06   0:17 [ksoftirqd/0]
root          5  0.0  0.0      0     0 ?        S<   03:06   0:00 [kworker/0:0H]
root          7  0.0  0.0      0     0 ?        S    03:06   0:00 [migration/0]
root          8  0.0  0.0      0     0 ?        S    03:06   0:00 [rcu_bh]
...

>>>结合管道（|）过滤（grep）查看 init 进程 2条
[xfk@centos ~]$ ps aux | grep init
root       6539  0.0  0.0  16892   552 ?        SNs  03:06   0:00 /usr/sbin/alsactl -s -n 19 -c -E ALSA_CONFIG_PATH=/etc/alsa/alsactl.conf --initfile=/lib/alsa/init/00main rdaemon
xfk      117642  0.0  0.0 112728   984 pts/0    R+   16:12   0:00 grep --color=auto init
```

###### 2）kill 终止进程

`kill [-signal] pid`   
信号值0-15，其中9为绝对终止，可以处理一般信号无法终止的进程

```
[xfk@centos ~]$ ps -a
   PID TTY          TIME CMD
100160 pts/1    00:00:03 top
129300 pts/0    00:00:00 ps
[xfk@centos ~]$ kill -9 100160
[xfk@centos ~]$ ps -a
   PID TTY          TIME CMD
   511 pts/0    00:00:00 ps
```

###### 3）reboot、shutdown、init 关机重启

| 命令              | 含义                                   |
| ----------------- | -------------------------------------- |
| reboot / init 6   | 重启操作系统                           |
| init 0            | 关机                                   |
| shutdown -r now   | 重启操作系统，shutdown会给别的用户提示 |
| shutdown -h now   | 立刻关机                               |
| shutdown -h 20:25 | 今天20:25关机                          |
| shutdown -h +10   | 10分钟后关机                           |

###### 4）ifconfig 查看或配置网卡信息

```
>>>查看所有网卡信息
[xfk@centos ~]$ ifconfig
ens33: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.88.130  netmask 255.255.255.0  broadcast 192.168.88.255
        inet6 fe80::adac:60a5:fce1:16b6  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:bd:fb:64  txqueuelen 1000  (Ethernet)
        RX packets 801489  bytes 358600740 (341.9 MiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 1115642  bytes 318304975 (303.5 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 32  bytes 2592 (2.5 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 32  bytes 2592 (2.5 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

virbr0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        inet 192.168.122.1  netmask 255.255.255.0  broadcast 192.168.122.255
        ether 52:54:00:d2:42:17  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

###### 5）ping 测试远程主机联通性

```
>>>终止Ctrl+c
[xfk@centos ~]$ ping 192.168.3.2
PING 192.168.3.2 (192.168.3.2) 56(84) bytes of data.
64 bytes from 192.168.3.2: icmp_seq=1 ttl=128 time=0.749 ms
64 bytes from 192.168.3.2: icmp_seq=2 ttl=128 time=0.687 ms
64 bytes from 192.168.3.2: icmp_seq=3 ttl=128 time=2.79 ms
64 bytes from 192.168.3.2: icmp_seq=4 ttl=128 time=0.754 ms
64 bytes from 192.168.3.2: icmp_seq=5 ttl=128 time=1.10 ms
64 bytes from 192.168.3.2: icmp_seq=6 ttl=128 time=0.595 ms
^C
--- 192.168.3.2 ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 5012ms
rtt min/avg/max/mdev = 0.595/1.113/2.790/0.767 ms
```

### 3. 编辑器💻

##### 3.1 gedit 编辑器

**gedit** 是一个Linux环境下的文本编辑器，类似windows下的写字板程序，在不需要特别复杂的编程环境下，作为基本的文本编辑器比较合适。

##### 3.2 vi/vim 编辑器

vim 是 vi 的升级。  
vim 有输入和命令 **3** 种工作模式：
1>命令模式>>>  
				`：` 转末行，`iI/oO/aA` 转编辑，`ZZ（大写）` 保存退出  

| 命令 | 功能                                                         |
| ---- | ------------------------------------------------------------ |
| i    | 在当前**光标所在位置插入**，光标后的文本相应向右移动         |
| I    | 在**光标所在行的行首插入**，行首是该行的第一个非空白字符，相当于光标移动到行首执行 i 命令 |
| o    | 在**光标所在行的下插入**新的一行。光标停在空行首，等待输入文本 |
| O    | 在**光标所在行的上插入**新的一行。光标停在空行的行首，等待输入文本 |
| a    | 在当前**光标所在位置之后插入**                               |
| A    | 在**光标所在行的行尾插入**，相当于光标移动到行尾再执行 a 命令 |

2>文本（编辑）模式>>>  
				`Esc` 转命令  
3>末行模式>>>  
				`w` 保存 `q` 退出，`Esc Esc ` / `执行一次末行命令`转命令

```
>>>vi/vim 文件，编辑器打开文件
[xfk@centos TESTdir]$ vim hello.txt
#include<stdio.h>

int main()
{
    return 0;
}

~                                                                                                             
~                                                                                                     
"hello.txt" [新文件] 
-- 插入 --
：wq

[xfk@centos TESTdir]$ cat hello.txt
#include<stdio.h>

int main()
{
    return 0;
}
```

```
>>>vim hello.c创建c文件，打印输出 hello world
//编译执行
[xfk@centos TESTdir]$ gcc hello.c -o hello
[xfk@centos TESTdir]$ ls
abc.txt  hello  hello.c
[xfk@centos TESTdir]$ ./hello
hello world
```

###### 1）光标定位

命令模式

| 命令             | 功能                    |
| ---------------- | ----------------------- |
| jkhl             | 上下左右                |
| [n]gg            | 指定 n 跳转，gg文档首行 |
| [n]G             | 指定 n 跳转，G文档尾行  |
| gg=G             | 排版（缩进）            |
| ctrl+b或pageUp键 | 翻屏操作，向上翻        |
| ctrl+f或pageDn键 | 翻屏操作，向下翻        |

###### 2）删除修改

命令模式

| 命令  | 功能                                 |
| ----- | ------------------------------------ |
| [n]x  | 删除光标后 n 个字符                  |
| [n]X  | 删除光标前 n 个字符                  |
| D     | 删除光标所在开始到此行尾的字符       |
| [n]dd | 删除从当前行开始的 n 行（剪切）      |
| [n]yy | 复制从当前行开始的 n 行              |
| p / P | 粘贴（小p粘贴光标后，大P粘贴光标前） |

###### 3）撤销恢复

命令模式

| 命令   | 功能           |
| ------ | -------------- |
| u      | 撤销上一个命令 |
| U      | 撤销所有       |
| Ctrl+r | 恢复           |

###### 4）查找

命令模式

在查找结果中，用`N`、`n`可以切换上下结果；
输入`/nohl`，可以取消高亮

| 命令    | 功能                                 |
| ------- | ------------------------------------ |
| /字符串 | 查找指定字符串                       |
| *       | 光标所在位置字符串                   |
| /^abc   | 查找以 abc 为行首的行                |
| /abc$   | 查找以 abc 为行尾的行                |
| ?abc    | 从光标所在位置**向后查找**字符串 abc |

###### 5）set 指令

末行模式

| 命令         | 功能                        |
| ------------ | --------------------------- |
| :set nu      | 显示行号                    |
| :set nonu    | 不显示行号                  |
| :! linux命令 | vim中执行linux命令后返回vim |

### 4. 远程操作:sunrise_over_mountains:

##### 5.1 SSH

**SSH** 是 Secure Shell 的缩写，建立在应用层和传输层基础上的安全协议。是目前较可靠，转为远程登录会话和其他网络服务提供安全性的协议。  
**常用于远程登录，以及用户之间进行资料拷贝。** 

```
>>>远程登录(Linux—>Linux)
[xfk@centos ~]$ ssh xfk@192.168.88.130
The authenticity of host '192.168.88.130 (192.168.88.130)' can't be established.
ECDSA key fingerprint is SHA256:hxGLVGRS6nbrms8Ds6+FipDakCoV7rxe64aWX5Bh7Xw.
ECDSA key fingerprint is MD5:53:8c:67:4f:76:d1:f9:ff:3c:81:4b:3f:a4:3a:33:98.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added '192.168.88.130' (ECDSA) to the list of known hosts.
xfk@192.168.88.130's password: 
Last login: Sat Jan  7 20:00:43 2023 from 192.168.88.1

[xfk@centos ~]$ exit
登出
Connection to 192.168.88.130 closed.
```


---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 
