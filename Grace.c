#include <stdio.h>
#define A 1
#define B 2
#define QUINE(x)int main(){ char*s=#x;x}
/*
   comment
*/
QUINE(FILE * fp;fp = fopen ("Grace_kid.c", "w+");fprintf(fp, "#include <stdio.h>\n#define A 1\n#define B 2\n#define QUINE(x)int main(){ char*s=#x;x}\n/*\n   comment\n*/\nQUINE(%s)",s);)