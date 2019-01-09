/* comment 2 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>

void read_file()
{
    int fd;
    int ret;
    char data[1024];

    /* fd = open("C/Colleen.c", O_RDONLY);*/
    fd = open("C/Colleen.c", O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Error while opening the file.\n");
        exit(0);
    }
    while ((ret = read(fd, data, sizeof(data)-1)) > 0) 
    {
        data[ret] = 0x00;
    }
    printf("%s", data);
    ret = close(fd);

    if (ret == -1)
    {
        perror("Error while closing the file.\n");
        exit(0);
    }

}

int main()
{
    /* comment 1 */
    read_file();
    return 0;
}
