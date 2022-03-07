#include <stdio.h>

int main(void) {
  int x = 1, y = 2, *pointerX, *pointerY;

  pointerX = &x;
  pointerY = &y;

  printf("Value:\npointerX= %d\npointerY= %d\n\n", *pointerX, *pointerY);
  
  if(*pointerX < *pointerY) {
    printf("pointerX bernilai lebih kecil dari pointerY\n");
  } else if(*pointerX > *pointerY) {
    printf("pointerX bernilai lebih besar dari pointerY\n");
  } else if(*pointerX == *pointerY) {
    printf("pointerX bernilai sama dengan pointerY\n");
  }
  
  printf("\nAddress:\npointerX= %p\npointerY= %p\n\n", pointerX, pointerY);
  
  if(pointerX < pointerY) {
    printf("pointerX menunjuk ke memori yang lebih kecil dari pointerY\n");
  } else if(pointerX > pointerY) {
    printf("pointerX menunjuk ke memori yang lebih besar dari pointerY\n");
  } else if(pointerX == pointerY) {
    printf("pointerX menunjuk ke memori yang sama dengan pointerY\n");
  }

  getchar();
  return 0;
}