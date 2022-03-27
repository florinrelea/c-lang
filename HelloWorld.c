#include <stdio.h>

int main() {
  FILE *filePointer = fopen("test.txt", "a");

  fputs("Holly shit, it is working!", filePointer);

  fclose(filePointer);

  return 0;
}
