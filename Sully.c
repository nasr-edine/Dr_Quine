#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void close_file(int fd)
{
    int ret;
    ret =  close(fd);
    if(ret == -1)
    {
        perror("Error while closing file.");
        exit(0);
    }
}

int open_source_code() 
{
    int fd;
    fd = open("../Sully.c", O_RDONLY);
    if (fd == -1)
    {
        perror("Error while opening the file ../Sully.c");
        exit(0);
    }
    return fd;
}

char *read_source_code(int fd_src_code)
{
    int bytes_read;
    char *data;
    data = (char *) malloc(1000 * sizeof(char));
    int i = 0;
    do
    {
        bytes_read = read(fd_src_code, &data[i], 1);
        i++;
    }
    while (bytes_read != 0); 
    close_file(fd_src_code);
    return data;
}

// Copy source code in new file
void copy_file(int fd_copy_file, char *data)
{
    if (write(fd_copy_file, data, strlen(data)) != (ssize_t)strlen(data)) 
    {
        write(2, "There was an error writing to copy source\n", 43);
        exit(0);
    }
}

// Create file Sully_5.c    
char *create_file(char *data)
{
    //entier
    int i = 5;
    //char filename[12] = "Sully_5.c";
    char *filename;
    filename = (char *) malloc(10 * sizeof(char));
    strcpy(filename, "Sully_5.c");
    int fd_new_file; 
    
    while(i >= 0)
    {
        fd_new_file = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
        //printf("filename: %s fd: %d\n\n", filename, fd_new_file);
        /* failure */
        if (fd_new_file < 0) 
        {
            if (errno == EEXIST) 
            {
                //printf("[%d]\n", i);
                //printf("error file %s existed\n", filename);
                i--;
                
                filename[6] = i + 48;
            }
        }
        else 
        {
            //printf("file %s is created\n", filename);
            /************************/
            char *str = "int i = 5;";
            //str[8] = i + 48;
            printf("[%c]\n",  i + 48);
            char *p = strstr(data, str);
            // Prints the result 
            if (p) 
            {
                printf("String found\n"); 
                p[8]=  i + 48;
                printf("First occurrence of string '%c' '%c' '%c'\n", p[8], p[1], p[2]); 
            } else
                printf("String not found\n"); 
            /************************/
            
            //p[8]= str[8];
            copy_file(fd_new_file, data);
            //return fd_new_file;
            close(fd_new_file);
            
            return filename;
        }
    }
    
    return NULL;
}

void compile_file(char *filename )
{
    char command[100];
    
    strcpy( command, "clang -Wall -Wextra -Werror -o " );
    strncat(command, filename, 7);
    strcat(command, " ");
    strcat(command, filename);
    //printf("%s\n", command);
    system(command);
}

void execute_file(char *filename )
{
    char command[100];
    
    strcpy( command, "./" );
    strncat(command, filename, 7);
    //strcat(command, " ");
    //strcat(command, filename);
    //printf("%s\n", command);
    system(command);
}

int main()
{
    char *data;
    char *filename;
    int fd_src_code;
    
    fd_src_code = open_source_code();
    data = read_source_code(fd_src_code);
    //printf("%s\n", data);



    //int fd_copy_file;
    filename = create_file(data);
    //printf("filename: %s\n", filename);
    if(filename == NULL)
    {
        printf("end\n");
        return 0;
    }
    //filename = copy_file(fd_copy_file, data);
    //close_file(fd_copy_file);

    //char filename[12] = "Sully_5.c"; 
    compile_file(filename);
    execute_file(filename);
    free(data);
    return 0;
}