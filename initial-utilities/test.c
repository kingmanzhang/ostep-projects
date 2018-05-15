#include <stdio.h>

int main(int argc, char* argv[]) {
  FILE *fp;
  char str[60];
  
  fp = fopen("my-cat.c", "r");
  if (fp == NULL) {
    printf("error open file\n");
    return 1;
  }

  while (fgets(str, 60, fp) != NULL) {
    printf("%s",str);
  }
  
  fclose(fp);
  return 0;
}
