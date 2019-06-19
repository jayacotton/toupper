#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *in;
FILE *tmp;
char infilename[30];
char tmpfilename[30];
int c;
char *p;
char bigbuf[4096];
int rz;
int i;
int
main (int argc, char *argv[])
{
  memset (infilename, 0, 80);
  memset (tmpfilename, 0, 80);
  strcpy (infilename, argv[1]);
  strcpy (tmpfilename, "XYZZY.TMP");

  in = fopen (infilename, "r");
  tmp = fopen (tmpfilename, "a");
  if (tmp == 0)
    {
      printf ("can open tmpfile");
      exit (0);
    }
// see what we can do to speed this up a lot.
//      while((c=fgetc(in))!=EOF){
//              if(c == '\n'){
//                      fputc(0x0d,tmp);
//              }else
//                      fputc(toupper(c),tmp);
//      }
  do
    {
      rz = 0;
      memset (bigbuf, 0, 4096);
      rz = fread (bigbuf, 1, 4096, in);
      printf ("read record, size = %d\n", rz);
      if (rz)
	{
	  for (i = 0; i < 4096; i++)
	    {
	      c = toupper (bigbuf[i]);
	      if (c == '\n')
		fputc (0x0d, tmp);
	      else if(c != 0)
		fputc (c, tmp);
	    }
	}
    }
  while (rz != 0);
  fflush (tmp);
  fclose (in);
  fclose (tmp);
  remove (infilename);
  rename (tmpfilename, infilename);
}
