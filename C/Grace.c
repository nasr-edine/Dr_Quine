#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>   // for strlen function

#define FT(x)int main(){ /* code */create_file();int fd = open_file();copy_file(fd);close_file(fd);return 0; }
int open_file() 
{
    int fd;
    fd = open("Grace.c", O_RDONLY);
    if (fd == -1)
        exit(0);
    return fd;
}

void close_file(int fd)
{
    int ret;
    ret = close(fd);
    if (ret == -1)
        exit(0);
}

void copy_file(int fd1)
{
    int ret;
    char data[10024];

    while ((ret = read(fd1, data, sizeof(data)-1)) > 0) 
        data[ret] = 0x00;    

    int fd2 = open("Grace_kid.c", O_WRONLY);
 
    if (fd2 < 0)
        exit(0);
 
    if (write(fd2, data, strlen(data)) != (ssize_t)strlen(data))
        exit(0);
}

void create_file()
{
    char *filename = "Grace_kid.c";
    //int fd = open(filename, O_CREAT|O_RDWR, 0644);
    int fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);

    if (fd < 0)
        exit(0);
    close(fd);
}

FT(x);
