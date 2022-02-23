#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void exchangeSortAscend(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(a[i] > a[j]) {
        swap(&a[i], &a[j]);
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

  printf("EXCHANGE SORT ASCENDING\n\n");
  
  printf("Mengurutkan data:\n[ 23, 65, 30, 8, 33, 24, 76, 7 ]\n\n");

  int data[] = {23, 65, 30, 8, 33, 24, 76, 7};
  int n = sizeof(data)/sizeof(data[0]);
  
  exchangeSortAscend(data, n);

  printf("Data setelah diurutkan secara ascending:\n");
  printArray(data, n);
  
  return 0;
}