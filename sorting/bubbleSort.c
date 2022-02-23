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

void bubbleSortDescend(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(a[j] < a[j+1]) {
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
  int n;

  printf("BUBBLE SORT ASCENDING & DESCENDING\n\n");
  
  printf("Masukkan jumlah data yang ingin dimasukkan: ");
  scanf("%d", &n);

  int data[n];
  
  printf("Masukkan %d data (integer):\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  bubbleSortAscend(data, n);

  printf("Data yang telah diurutkan secara ascending:\n");
  printArray(data, n);

  bubbleSortDescend(data, n);

  printf("Data yang telah diurutkan secara descending:\n");
  printArray(data, n);
  
  return 0;
}