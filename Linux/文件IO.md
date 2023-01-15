# 文件IO

## 1. 文件IO:open_file_folder: 

**:shopping_cart: 虚拟地址空间 $\rightarrow$ 内核区 $\rightarrow$ PCB $\rightarrow$ 文件描述符表 $\rightarrow$ 文件描述符 $\rightarrow$ 文件IO操作使用文件描述符** 

### 3.1 C库IO函数的工作流程

使用 `fopen` 函数打开一个文件，返回一个 `FILE* pf` ,这个指针执行那个的结构体有三个重要的成员：

1. **文件描述符**：通过文件描述可以找到文件的 `inode` ,通过 `inode` 可以找到对应的数据块
2. 文件指针：读和写共享一个文件指针，读或写都会引起文件指针的变化
3. 文件缓冲区：读或写会先通过文件缓冲区，主要目的是为了减少对磁盘的读写次数，提高读写磁盘的效率

【:loudspeaker:】头文件stdio.h的48行处：`typedef struct _IO_FILE FILE`  
             头文件libio.h的269行处：`struct _IO_FILE` 这个 结构体定义中有一个 `int _fileno` 成员，这个就是文件描述符

### 3.2 C库函数与系统函数的关系

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

### 3.3 虚拟地址空间

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

### 3.4 pcb和文件描述符表

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

### 3.5 open/close

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

### 3.6 read/write

#### read函数

- 函数描述：从打开的设备或文件中读取数据
- 函数原型：  
  `ssize_t read(int fd,void* buf,size_t count);` 
- 函数参数：
  - `fd` 文件描述符
  - `buf` 读上来的数据保存在缓冲区buf中
  - `count` buf缓冲区存放的最大字节数

- 函数返回值：
  - `>o` 读取到的节数
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


### 3.7 lseek

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

### 3.8 perro/errno



### 3.9 阻塞/非阻塞



---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 