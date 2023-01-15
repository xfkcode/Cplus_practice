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



### 3.6 read/write



### 3.7 lseek



### 3.8 perro/errno



### 3.9 阻塞/非阻塞



---
> ✍️ [邢福凯 (xfkcode@github)](https://github.com/xfkcode)  
> 📅 **写于2023年1月** 