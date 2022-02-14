#include <stdio.h>

int main(void) {
    int n, cari, data, i, jumlah = 0;
    printf("Mau input berapa data? ");
    scanf("%d", &n);
    
    int Data[n];
    
    printf("Masukkan %d data (integer)\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &Data[i]);
    }
    
    printf("Cari angka berapa? ");
    scanf("%d", &cari);
    for(i = 0; i < n; i++) {
      if(Data[i] == cari) {
        printf("Angka '%d' DITEMUKAN pada lokasi/indeks [%d]\n", cari, i + 1);
        jumlah++;
      }
    }
    if(jumlah == 0) {
      printf("Angka %d TIDAK DITEMUKAN!\n", cari);
    } else {
      printf("Angka '%d' DITEMUKAN sebanyak %d kali\n", cari, jumlah);
    }
    return 0;
}