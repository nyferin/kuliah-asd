#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void selectionSortAscend(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    int min = i;
    for(int j = i+1; j < n; j++) {
      if(a[min] > a[j]) {
        min = j;
      }
    }
    swap(&a[min], &a[i]);
  }
}

void selectionSortDescend(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    int min = i;
    for(int j = i+1; j < n; j++) {
      if(a[min] < a[j]) {
        min = j;
      }
    }
    swap(&a[min], &a[i]);
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

  printf("SELCTION SORT ASCENDING & DESCENDING\n\n");
  
  printf("Masukkan jumlah data yang ingin dimasukkan: ");
  scanf("%d", &n);

  int data[n];
  
  printf("Masukkan %d data (integer):\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  selectionSortAscend(data, n);

  printf("Data yang telah diurutkan secara ascending:\n");
  printArray(data, n);

  selectionSortDescend(data, n);

  printf("Data yang telah diurutkan secara ascending:\n");
  printArray(data, n);
  
  return 0;
}