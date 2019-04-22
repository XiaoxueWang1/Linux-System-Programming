# Linux-System-Programming
Linux-System-Programming  
--------------------------------------
1-mmap  头文件<sys/mman.h>
将磁盘的一块存储区映射到内存种，用于IPC  
mmaptest.c 内存映射demo  
test.txt test文件  
API: void* mmap(void* addr,size_t length,int prot,int flags,int fd,off_t offset);  
addr--映射区首地址，内存自动分配  
length--大小  
prot--权限  
flags--是否和磁盘一致  
fd--文件描述符  
offset--偏移量  
