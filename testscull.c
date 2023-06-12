#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define NUM 1000
int main()
{
    int fd;
    int i;
    int *data, *buf;
    fd = open("/dev/scull0", O_RDWR);
    data = (int*)malloc(NUM*sizeof(int));
    buf = (int*)malloc(NUM*sizeof(int));
    for(i=0;i<NUM;i++)
        *(data+i) = i;
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    write(fd, data, NUM*sizeof(int));
    lseek(fd,0L,SEEK_SET);
    read(fd, buf, NUM*sizeof(int));
    for(i=0;i<NUM;i++)  
    {
        printf("%d\t",*(buf+i));
        if((i+1)%10==0)
             printf("\n");
    }
    printf("\n");
    close(fd);
    return 0;
}