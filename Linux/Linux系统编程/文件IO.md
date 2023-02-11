# 文件IO:card_file_box: 

## 1. 文件IO:open_file_folder: 

**:shopping_cart: 虚拟地址空间 $\rightarrow$ 内核区 $\rightarrow$ PCB $\rightarrow$ 文件描述符表 $\rightarrow$ 文件描述符 $\rightarrow$ 文件IO操作使用文件描述符** 

### 1.1 C库IO函数的工作流程

使用 `fopen` 函数打开一个文件，返回一个 `FILE* pf` ,这个指针执行那个的结构体有三个重要的成员：

1. **文件描述符**：通过文件描述可以找到文件的 `inode` ,通过 `inode` 可以找到对应的数据块
2. 文件指针：读和写共享一个文件指针，读或写都会引起文件指针的变化
3. 文件缓冲区：读或写会先通过文件缓冲区，主要目的是为了减少对磁盘的读写次数，提高读写磁盘的效率

【:loudspeaker:】头文件stdio.h的48行处：`typedef struct _IO_FILE FILE`  
             头文件libio.h的269行处：`struct _IO_FILE` 这个 结构体定义中有一个 `int _fileno` 成员，这个就是文件描述符

### 1.2 C库函数与系统函数的关系

**库函数和系统函数的关系：调用和被调用的关系；库函数是对 系统函数的进一步封装**  
【:ticket:】系统调用：由操作系统实现并提供给外部应用程序的编程接口  
（Application Programming Interface，API），是应用程序同系统之间数据交互的桥梁

---

<font color=CornflowerBlue>**c标准函数**</font>   
【`printf` 函数 $\rightarrow$ 标准输出(stdout)：FILE*】`printf("hello")` $\rightarrow$【FD/FP_POS/BUFFER】

​									$\downarrow$ 调用 `write` 函数将文件描述符传递过去

<font color=CornflowerBlue>**系统API**</font>  
【应用层 `write(fd, "hello", 5)`】   
			用户空间 $\rightarrow$ 内核空间  
【系统调用 `sys_write()`】  
					调用设备驱动  
【内核层 设备驱动函数】

​									$\downarrow$ 通过设备驱动操作硬件

<font color=CornflowerBlue>**硬件层**</font>  
【硬件 显示器】

### 1.3 虚拟地址空间

Linux为每一个运行的程序（进程）操作系统（32位）都会为其分配一个0~4G的地址空间（虚拟地址空间）

---

<font color=DeepPink>**4~3G 内核区**</font>  
用户既不能读也不能写

【内存管理】  
【进程管理】$\rightarrow$ 【PCB】  
【设备驱动管理】  
【VFS虚拟文件系统】

【:loudspeaker:】内核区中很重要的一个就是进程管理，进程管理中有一个区域就是PCB（本质是一个结构体）；  
             PCB中有文件描述符表，文件描述符表中存放着打开的文件描述符，涉及到文件的IO操作都会用到这个文件描述符

<font color=DeepPink>**3~0G 用户区**</font>  
高地址 $\rightarrow$ 低地址

【环境变量（env）】  
【命令行参数（main函数参数）`int main(int argc, char* argv[])` 】  
【栈空间（小端）】  
【共享库】  
【堆空间（大端）】  
【.bss（未初始化全局变量）】  
【.data（已初始化全局变量）】  
【.text（代码段，二进制机器指令）】   
【受保护的地址（0~4k）】

### 1.4 pcb和文件描述符表

<font color=Gold>**Linux Kernel 进程管理** </font>  
<font color=Gold>**PCB（进程控制块）** </font> 

【文件描述符表】

|            文件描述符             |
| :-------------------------------: |
| 0 - > `STDIN_FILENO` （标准输入） |
| 1 -> `STDOUT_FILENO` （标准输出） |
| 2 -> `STDERR_FILENO` （标准错误） |
|                 3                 |
|                ...                |
|               1023                |

【:ticket:】1~3 默认打开状态  
              每打开一个新文件，则占用一个文件描述符，而且是空闲的最小的一个文件描述符

【:loudspeaker:】pcb：结构体 `task_stuct` 

### 1.5 open/close

头文件

```C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
```

#### open函数

- 函数描述：打开或者新建一个文件
- 函数原型：  
  `int open(const char* pathname,int flags);`  
  `int open(const char* pathname,int flags,mode_t mode);` 
- 函数参数：
  - `pathname` 参数是要打开或创建的文件名，和 `fopen` 一样，既可以是相对路径也可以是绝对路径
  - `flags` 参数有一系列常数值可供选择，可以同时选择多个常数
    - 必选参数（下面三个必须要有一个）
      - O_RDONLY ：只读
      - O_WRONLY ：只写
      - O_RDWR ：可读可写
    - 可选参数（仅列出常用参数）
      - O_APPEND ：追加的方式打开
      - O_CREAT ：如果文件不存在则创建
      - O_EXCL ：和 O_CREAT 一块使用，如果文件存在则报错
      - O_TRUNC：如果文件已存在，将其长度截断为0字节
      - O_NONBLOCK ：对于设备文件，非阻塞的方式打开文件
  - `mode` 权限位  
    文件最终权限：`mode & ~umask ` （与取反文件掩码）
- 函数返回值：
  - 成功：返回一个最小且未被占用的文件描述符
  - 失败：返回 -1，并设置 `errno` 

#### close函数

- 函数描述：关闭文件
- 函数原型：  
  `int close(int fd);` 
- 函数参数：
  - `fd` 文件描述符
- 函数返回值：
  - 成功：返回 0
  - 失败：返回 -1 ，并设置 `errno`  

### 1.6 read/write

#### read函数

- 函数描述：从打开的设备或文件中读取数据
- 函数原型：  
  `ssize_t read(int fd,void* buf,size_t count);` 
- 函数参数：
  - `fd` 文件描述符
  - `buf` 读上来的数据保存在缓冲区buf中
  - `count` buf缓冲区存放的最大字节数

- 函数返回值：
  - `>0` 读取到的节数
  - `=0` 文件读取完毕
  - `-1` 出错，并设置 `errno` 


#### write函数

- 函数描述：向打开的设备或文件中写数据
- 函数原型：  
  `ssize_t write(int fd,const void* buf,size_t count);` 
- 函数参数：
  - `fd` 文件描述符
  - `buf` 缓冲区，要写入文件或设备的数据
  - `count` buf中数据的长度
- 函数返回值：
  - 成功：返回写入的字节数
  - 错误：返回 -1 ，并设置 `errno` 


### 1.7 lseek

- 函数描述：移动文件指针
- 函数原型：  
  `off_t lseek(int fd,off_t offset,int whence);` 
- 函数参数：
  - `fd` 文件描述符
  - `offset` 的含义取决于参数 `whence` 
    - 如果 `whence` 是 SEEK_SET ，文件偏移量将设置为 offset
    - 如果  `whence` 是 SEEK_CUR ，文件偏移量将被设置为 cfo 加上 offset ，offset可为正也可为负
    - 如果  `whence` 是 SEEK_END ，文件偏移量将被设置为文件长度加上 offset ，offset可为正也可为负
- 函数返回值：若 lseek 成功执行，则返回新的偏移量
- lseek函数获取文件大小  
  `lseek(fd, 0, SEEK_END);` 
- lseek函数文件扩展  
  `lseek(fd, 100, SEEK_SET);` 移动文件指针到100个字节处   
  `write(fd, "H", 1);` 进行一次写入操作 

```C
  1 //IO函数测试--->open close read write lseek
  2 #include<stdio.h>
  3 #include<stdlib.h>
  4 #include<string.h>
  5 #include<sys/types.h>
  6 #include<unistd.h>
  7 #include<sys/stat.h>
  8 #include<fcntl.h>
  9 
 10 int main(int argc, char *argv[])
 11 {
 12     //打开文件
 13     int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
 14     if (fd<0)
 15     {
 16         perror("open error");
 17     }
 18     //写文件
 19     //ssize_t write(int fd,const void* buf,size_t count);
 20     write(fd, "hello world", strlen("hello world"));
 21 
 22     //移动文件指针到文件开始处
 23     //off_t lseek(int fd,off_t offset,int whence);
 24     lseek(fd, 0, SEEK_SET);
 25     
 26     //读文件
 27     //ssize_t read(int fd,void* buf,size_t count);
 28     char buf[1024];
 29     memset(buf, 0x00, sizeof(buf));
 30     int n = read(fd, buf, sizeof(buf));
 31     printf("n==[%d], buf==[%s]", n, buf);
 32     
 33     //关闭文件
 34     close(fd);
 35     
 36     return 0;
 37 }
```

### 1.8 perro/errno

`errno` 是一个全局变量，当系统调用后若出错将 `errno`进行设置，`perror` 可以将 `errno` 对应的描述信息打印出来  
【:printer:】 `perro("open");`  >>> open：错误信息

### 1.9 阻塞/非阻塞

**阻塞和非阻塞不是 `read` 函数的属性，而是文件本身的属性** 

非阻塞：普通文件

阻塞：设备文件/ socket/ pipe

## 2. 文件和目录:file_cabinet: 

### 2.1 文件操作相关函数

#### stat/lstat函数

- 函数描述：获取文件属性
- 函数原型：  
  `int stat(const char* pathname,struct stat* buf);`  
  `int lstat(const char* pathname,struct stat* buf);` 
- 函数返回值：
  - 成功返回 0 
  - 失败返回 -1

```C
 struct stat {
     dev_t     st_dev;         /* ID of device containing file */
     ino_t     st_ino;         /* inode number */
   👉mode_t    st_mode;        /* file type and mode */
     nlink_t   st_nlink;       /* number of hard links */
     uid_t     st_uid;         /* user ID of owner */
     gid_t     st_gid;         /* group ID of owner */
     dev_t     st_rdev;        /* device ID (if special file) */
     off_t     st_size;        /* total size, in bytes */
     blksize_t st_blksize;     /* blocksize for filesystem I/O */
     blkcnt_t  st_blocks;      /* number of 512B blocks allocated */

     struct timespec st_atim;  /* time of last access */
     struct timespec st_mtim;  /* time of last modification */
     struct timespec st_ctim;  /* time of last status change */

     #define st_atime st_atim.tv_sec      /* Backward compatibility */
     #define st_mtime st_mtim.tv_sec
     #define st_ctime st_ctim.tv_sec
 };
```

【:ticket:】 **st_mode权限** 16位整数

- 0-2bit其他人权限

| 宏        | 值                                                 |
| --------- | -------------------------------------------------- |
| `S_IROTH` | 00004（读权限）                                    |
| `S_IWOTH` | 00002（写权限）                                    |
| `S_IXOTH` | 00001（执行权限）                                  |
| `S_IRWXO` | 00007（掩码，过滤st_mode中除其他人权限以外的信息） |

```C
//判断其他人权限
if (si_mode & S_IROTH)	//True可读
if (si_mode & S_IWOTH)	//True可写
if (si_mode & S_IXOTH)	//True可执行
```

- 3-5bit所属组权限

| 宏        | 值                                                 |
| --------- | -------------------------------------------------- |
| `S_IRGRP` | 00040（读权限）                                    |
| `S_IWGRP` | 00020（写权限）                                    |
| `S_IXGRP` | 00010（执行权限）                                  |
| `S_IRWXG` | 00070（掩码，过滤st_mode中除所属组权限以外的信息） |

```C
//判断所属组权限
if (si_mode & S_IRGRP)	//True可读
if (si_mode & S_IWGRP)	//True可写
if (si_mode & S_IXGRP)	//True可执行
```

- 6-8bit所有者权限

| 宏        | 值                                                 |
| --------- | -------------------------------------------------- |
| `S_IRUSR` | 00400（读权限）                                    |
| `S_IWUSR` | 00200（写权限）                                    |
| `S_IXUSR` | 00100（执行权限）                                  |
| `S_IRWXU` | 00700（掩码，过滤st_mode中除所有者权限以外的信息） |

```C
//判断所有者权限
struct stat st;
stat(pathname, &st);
if (st.si_mode & S_IRUSR)	//True可读
if (st.si_mode & S_IWUSR)	//True可写
if (st.si_mode & S_IXUSR)	//True可执行
```

- 12-15bit文件类型

| 宏         | 值                          |
| ---------- | --------------------------- |
| `S_IFSOCK` | 0140000（socket）           |
| `S_IFLNK`  | 0120000（symbolic link）    |
| `S_IFREG`  | 0100000（regular file）     |
| `S_IFBLK`  | 0060000（block device）     |
| `S_IFDIR`  | 0040000（directory）        |
| `S_IFCHR`  | 0020000（character device） |
| `S_IFIFO`  | 0010000（FIFO）             |

【:japanese_goblin:】 `S_IFMT` 0170000 掩码

```C
//判断文件类型
struct stat st;
stat(pathname, &st);
if ((st.st_mode & S_IFMT)==S_IFREG)	//True普通文件
if (S_IFREG(st.st_mode))			//True普通文件
```

【:loudspeaker:】**stat/lstat函数**  
             1.对于普通文件来说，两者相同  
             2.对于软连接文件来说，lstat函数获取的是链接文件本身的属性，stat函数获取的是链接文件指向的文件属性

### 2.2 目录操作相关函数

```C
#include <sys/types.h>
#include <dirent.h>
```

#### opendir函数

- 函数描述：打开目录
- 函数原型：  
  `DIR *opendir(const char *name);` 
- 函数返回值：
  - 成功：目录流指针
  - 错误：返回 NULL ，并设置 `errno` 

#### readdir函数

- 函数描述：读取目录--目录项
- 函数原型：  
  `struct dirent *readdir(DIR *dirp);` 
- 函数参数：`opendir` 函数返回值
- 函数返回值：
  - 成功：读取的目录项指针
  - 目录末尾：返回 NULL
  - 错误：返回 NULL ，并设置 `errno` 

```C
struct dirent {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* not an offset; see NOTES */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                   by all file system types */
    char           d_name[256]; /* filename */
};
```

#### closedir函数

- 函数描述：关闭目录
- 函数原型：  
  `int closedir(DIR *dirp);` 
- 函数返回值：
  - 成功：返回 0 
  - 错误：返回 -1 ，并设置 `errno` 

#### 读取目录内容的一般步骤

1. `DIR *pDir = opendir("dir");` 打开目录 
2. `while((p = readdir(pDir)) != NULL){}` 循环读取文件
3. `closedir(pDir);` 关闭目录

```C
  1 //目录操作测试：opendir readdir closedir
  2 #include<stdio.h>
  3 #include<stdlib.h>
  4 #include<string.h>
  5 #include<sys/types.h>
  6 #include<unistd.h>
  7 #include<dirent.h>
  8 
  9 int main(int argc, char *argv[])
 10 {
 11     //打开目录
 12     //DIR *opendir(const char ＊name);
 13     DIR *pDir = opendir(argv[1]);
 14     if (pDir==NULL)
 15     {
 16         perror("opendir error");
 17         return -1;
 18     }
 19 
 20     //循环读取目录
 21     struct dirent *pDent = NULL;
 22     while((pDent=readdir(pDir))!=NULL)
 23     {
 24         //过滤./.. 
 25         if (strcmp(pDent->d_name,".")==0 || strcmp(pDent->d_name,"..")==0)
 26         {
 27             continue;
 28         }
 29         printf("[%s]--->",pDent->d_name);
 30         //判断文件类型
 31         switch(pDent->d_type)
 32         {
 33             case DT_REG:
 34                 printf("普通文件");
 35                 break;
 36             case DT_DIR:
 37                 printf("目录文件");
 38                 break;
 39             case DT_LNK:
 40                 printf("链接文件");
 41                 break;
 42             default:
 43                 printf("未知文件");
 44                 break;
 45         }
 46         printf("\n");
 47     }
 48 
 49     //关闭目录
 50     closedir(pDir);
 51     return 0;
 52 }
```

### 2.3 dup/dup2/fcntl

```C
#include <unistd.h>
#include <fcntl.h>
```

#### dup函数

- 函数描述：复制文件描述符  
  两个文件描述符指向同一个文件（类似硬链接）计数为 0 才被关闭
- 函数原型：  
  `int dup(int fildes);` 
- 函数参数：`fildes` 要复制的文件描述符
- 函数返回值：
  - 成功：返回最小且没被占用的文件描述符
  - 错误：返回 -1 ，并设置 `errno` 

#### dup2函数

- 函数描述：复制文件描述符
- 函数原型：  
  `int dup2(int fildes, int fildes2);` 
-  函数参数：
  - `fildes` 原文件描述符
  - `fildes2` 新文件描述符（指定）  
    若指定的文件描述已被占用，则关闭指向文件，重新指向 `fildes` 原文件
- 函数返回值：
  - 成功：返回新文件描述符
  - 错误：返回 -1 ，并设置 `errno` 

```C
  1 //使用dup2函数实现标准输出重定向
  2 #include<stdio.h>
  3 #include<stdlib.h>
  4 #include<string.h>
  5 #include<sys/types.h>
  6 #include<sys/stat.h>
  7 #include<unistd.h>
  8 #include<fcntl.h>
  9 
 10 int main(int argc, char *argv[])
 11 {
 12     //打开文件
 13     int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
 14     if (fd<0)
 15     {
 16         perror("open error");
 17         return -1;
 18     }
 19     //调用dup2函数实现文件重定向
 20     dup2(fd, STDOUT_FILENO);
 21 
 22     printf("hello world");
 23 
 24     //关闭文件
 25     close(fd);
 26     
 27     return 0;
 28 }
```

#### fcntl函数

- 函数描述：改变已打开的文件的属性
- 函数原型：  
  `int fcntl(int fildes, int cmd, ...);` 
- 函数参数：
  - `cmd` F_DUPFD，复制文件描述符（dup）  
    `int newfd = fcntl(fd, F_DUPFD, 0);` 
  - `cmd` F_GETFL，获取文件描述符的 flag 属性值  
    `int flag = fcntl(fd, F_GETFL, 0);` 
  - `cmd` F_SETFL，设置文件描述符的 flag 属性   
    `flag |= O_APPEND;`  
    `fcntl(fd, F_SETFL, flag);`  
- 函数返回值：
  - 成功：
    - `cmd` F_DUPFD，返回新的文件描述符
    - `cmd` F_GETFL，返回文件描述符的 flag 属性值
    - `cmd` F_SETFL，返回 0 
  - 错误：返回 -1 ，并设置 `errno` 

---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 