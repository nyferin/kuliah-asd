#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSortAscend(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(a[j] > a[j+1]) {
        swap(&a[j], &a[j+1]);
      }
    }
  }
}

void printArray(int a[], int n) {
  printf("[ ");
  for(int i = 0; i < n; ++i) {
    printf("%d", a[i]);
    if(i < n-1) {
      printf(", ");
    }
  }
  printf(" ]\n");
}

int main(void) {

  printf("BUBBLE SORT ASCENDING\n\n");
  
  printf("Mengurutkan data:\n[ 23, 65, 30, 8, 33, 24, 76, 7 ]\n\n");

  int data[] = {23, 65, 30, 8, 33, 24, 76, 7};
  int n = sizeof(data)/sizeof(data[0]);
  
  bubbleSortAscend(data, n);

  printf("Data setelah diurutkan secara ascending:\n");
  printArray(data, n);
  
  return 0;
}