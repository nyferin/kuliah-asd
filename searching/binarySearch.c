#include <stdio.h>

int iterativeBinarySearch(int array[], int start_index, int end_index, int element) {
   while (start_index <= end_index) {
      int middle = start_index + (end_index- start_index )/2;
      if (array[middle] == element) {
        return middle;
      }
      else if (array[middle] < element) {
        start_index = middle + 1;
      }
      else {
        end_index = middle - 1;
      }
   }
   return -1;
}

int main(void) {
  int n, cari, data, i, j, p, jumlah = 0;
    printf("Mau input berapa data? ");
    scanf("%d", &n);
    
    int Data[n];
    
    printf("Masukkan %d data (integer)\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &Data[i]);
    }

    for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j){
      if (Data[i] > Data[j]){
        p = Data[i];
        Data[i] = Data[j];
        Data[j] = p;
      }
    }
  }

    printf("Data yang sudah di sortir:\n");
    printf("[");
    for(i = 0; i < n; i++) {
        printf("%d", Data[i]);
        if (i < n - 1) {
          printf(", ");
        }
    }
    printf("]\n");
    
    printf("Cari angka berapa? ");
    scanf("%d", &cari);

    int found_index = iterativeBinarySearch(Data, 0, n-1, cari);
    if(found_index == -1 ) {
      printf("Angka tersebut TIDAK DITEMUKAN!\n");
    }
    else {
      printf("Angka DITEMUKAN pada lokasi/index [%d]\n",found_index);
    }
    return 0;
}