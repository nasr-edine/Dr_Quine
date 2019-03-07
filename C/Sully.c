#include <stdio.h>
#include <stdlib.h>
#define A 1
#define B 2
#define QUINE(x)int main(){ char*s=#x;x}
/*
   comment
*/
QUINE(FILE * fp;fp = fopen ("Sully_5.c", "w+");fprintf(fp, "#include <stdio.h>\n#include <stdlib.h>\n#define A 1\n#define B 2\n#define QUINE(x)int main(){ char*s=#x;x}\n/*\n   comment\n*/\nQUINE(%s)",s);fclose(fp);{int payload = 5;payload--;}system("clang -Wall -Wextra -Werror Sully_5.c -o Sully_5");)