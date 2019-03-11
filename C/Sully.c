#include<stdlib.h>
#include<stdio.h>
int main(){
int i=5;
if(i<=-1) return(0);char name[10] = "Sully_X.c";name[6]=i+48;FILE * fp;fp = fopen (name, "w+");char*s="#include<stdlib.h>%c#include<stdio.h>%cint main(){%cint i=%i;%cif(i<=-1) return(0);char name[10] = %cSully_X.c%c;name[6]=i+48;FILE * fp;fp = fopen (name, %cw+%c);char*s=%c%s%c;fprintf(fp, s,10,10,10,--i,10,34,34,34,34,34,s,34,34,34,34,34,10);fclose(fp);char command[100]= %cclang -Wall -Wextra -Werror Sully_X.c -o Sully_X%c;command[34] = i + 48+1;command[47] = i + 48+1;system(command);char command2[30]= %c./Sully_X%c;command2[8] = i + 48+1;system(command2);}%c";fprintf(fp, s,10,10,10,--i,10,34,34,34,34,34,s,34,34,34,34,34,10);fclose(fp);char command[100]= "clang -Wall -Wextra -Werror Sully_X.c -o Sully_X";command[34] = i + 48+1;command[47] = i + 48+1;system(command);char command2[30]= "./Sully_X";command2[8] = i + 48+1;system(command2);}
