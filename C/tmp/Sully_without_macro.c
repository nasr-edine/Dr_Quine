#include<stdio.h>
main(){int i=5;char name[10] = "Sully_X.c";FILE * fp;fp = fopen (name, "w+");char*s="#include<stdio.h>%cmain(){int i=%i;char name[10] = %cSully_X.c%c;FILE * fp;fp = fopen (name, %cw+%c);char*s=%c%s%c;fclose(fp);printf(s,10,--i,34,34,34,34,34,s,34,10);}%c";fclose(fp);printf(s,10,--i,34,34,34,34,34,s,34,10);}
