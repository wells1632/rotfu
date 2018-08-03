#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check for input
  if (argc != 2) {
    printf("Must provide an input file\n");
    exit(0);
  }

  // Check if there is a file
  struct stat fileStat;
  if (stat(argv[1], &fileStat) < 0)
    return 1;

  // Check if the file is a regular file, i.e. not a directory, etc.
  if (!S_ISREG(fileStat.st_mode)) {
    printf("Not regular file\n");
    exit(0);
  }
  
  // Create output filename
  char outfile[strlen(argv[1]) + 10];
  strcpy(outfile, argv[1]);
  strcat(outfile, ".rfu");

  // Open input and output files
  FILE *fp;
  fp=fopen(argv[1], "r");
  FILE *fp2;
  fp2=fopen(outfile, "w");

  int c,a,n,cr;
  a=0;
  n=0;
  // Grab each character and manipulate it if it is a letter or number. Leave
  // punctuation alone
  if(fp == NULL) {
    perror("Error in opening file");
    return(-1);
  } do {
    c = fgetc(fp);
    cr=c;
    if (feof(fp)) {
      break;
    }
    if(c > 47 && c<58) {
      n++;
      cr=c+n;
      while(cr>57) {
	cr-=10;
      }
    } else if (c > 64 && c < 91) {
      a++;
      cr=c+a;
      while(cr>90) {
	cr-=26;
      }
    } else if (c>96 && c<123) {
      a++;
      cr=c+a;
      while(cr>122) {
	cr-=26;
      }
    } 
    // print out the result both to stdout and the file
    printf("%c", cr);
    char crout[2];
    sprintf(crout, "%c", cr);
    fprintf(fp2, crout);
  } while(1);

  // Close out the files
  fclose(fp);
  fclose(fp2);
  return(0);
}
