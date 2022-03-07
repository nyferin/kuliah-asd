#include <stdio.h>

int main(void) {
  int data[3], *pointer;

  data[0] = 125;
  data[1] = 345;
  data[2] = 750;

  pointer = &data[0];
  
  printf("Data %d memiliki alamat memori %p\n", *pointer, pointer);
  printf("Data %d memiliki alamat memori %p\n", *(pointer + 1), pointer + 1);
  printf("Data %d memiliki alamat memori %p\n", *(pointer + 2), pointer + 2);
  getchar();
  
  return 0;
}