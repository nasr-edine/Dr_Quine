#include <stdio.h>

void function(char *str){printf(str, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x22, str, 0x22, 0x0A, 0x0A, 0x0A, 0x0A);}
/*
   comment
*/
int main (void)
{
/*
   comment
*/
char str[]= "#include <stdio.h>%c%cvoid function(char *str){printf(str, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x22, str, 0x22, 0x0A, 0x0A, 0x0A, 0x0A);}%c/*%c   comment%c*/%cint main (void)%c{%c/*%c   comment%c*/%cchar str[]= %c%s%c;%cfunction(str);%creturn 0;%c}";
function(str);
return 0;
}