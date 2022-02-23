#include <stdio.h>

void insertionSortAscend(int a[], int n) {
  for(int i = 0; i < n; i++) {
    int tmp = a[i], j = i;
    while(j > 0 && a[j-1] > tmp) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = tmp;
  }
}

void insertionSortDescend(int a[], int n) {
  for(int i = 0; i < n; i++) {
    int tmp = a[i], j = i;
    while(j > 0 && a[j-1] < tmp) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = tmp;
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

  printf("INSERTION SORT ASCENDING\n\n");
  
  printf("Masukkan jumlah data yang ingin dimasukkan: ");
  scanf("%d", &n);

  int data[n];
  
  printf("Masukkan %d data (integer):\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  insertionSortAscend(data, n);

  printf("Data yang telah diurutkan secara ascending:\n");
  printArray(data, n);

  insertionSortDescend(data, n);

  printf("Data yang telah diurutkan secara descending:\n");
  printArray(data, n);
  
  return 0;
}