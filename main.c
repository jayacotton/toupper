#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

FILE *in;
FILE *out;
FILE *tmp;
char infilename[30];
char outfilename[30];
char tmpfilename[30];
char c;
char *p;
int main(int argc, char *argv[])
{
	memset(infilename,0,80);
	memset(outfilename,0,80);
	memset(tmpfilename,0,80);
	strcpy(infilename,argv[1]);
	strcpy(outfilename,argv[1]);
	strcpy(tmpfilename,"C:XYZZY.TMP");

	in=fopen(infilename,"r");
	tmp = fopen(tmpfilename,"a");
	if(tmp == 0){
		printf("can open tmpfile");
		exit(0);
	}
	while((c=fgetc(in))!=EOF){
		if(c == '\n'){
			fputc(0x0d,tmp);
		}else
			fputc(toupper(c),tmp);
	}
	fflush(tmp);
	fclose(in);
	fclose(tmp);
}
