#include <stdio.h>

int main ()
{
  FILE * pFile;
  pFile = fopen ( "example.txt" , "wb" );
  fputs ( "This is an apple." , pFile );
  fseek ( pFile , 9 , SEEK_SET );
  fprintf (  pFile," sam"  );
  fprintf (pFile , "KDLASDKLA");
  fclose ( pFile );
  return 0;
}
