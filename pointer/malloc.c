#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pointer;

  pointer = (int *) malloc(sizeof(int));

  printf("Bernilai %d\n", *pointer);
  printf("Beralamat %p\n\n", pointer);

  *pointer = 10;

  printf("Bernilai %d\n", *pointer);
  printf("Beralamat %p\n\n", pointer);

  free(pointer);

  printf("Bernilai %d\n", *pointer);
  printf("Beralamat %p\n\n", pointer);
  
  getchar();
  return 0;
}