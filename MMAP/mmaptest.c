#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(){
    char *p=NULL;
    int fd = open("test.txt", O_RDWR, 0);
    if(fd<0){
        perror("error");
        exit(1);
    }
    int len = ftruncate(fd,4);
    if(len==-1){
        perror("error");
        exit(1);
    }
    p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); //创建一个内存映射区,成功返回指针
    if(p== MAP_FAILED){
        perror("mmap error");
        exit(1);
    }
    strcpy(p, "abc"); //写数据
    int ret = munmap(p,4); //收回
    if(ret==-1){
        perror("ret error");
        exit(1);
    }
    close(fd);
    return 0;
}
