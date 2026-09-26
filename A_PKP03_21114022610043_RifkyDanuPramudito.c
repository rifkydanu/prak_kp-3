#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int batas_kesempatan = 6;

int prosesTebakKode(int kode_rahasia, int sisa_kesempatan);
void tampilkanPesanAkhir(int status_berhasil, int kode_rahasia);
void mulaiTebakKode();

int main() {
    srand(time(NULL));
    mulaiTebakKode();
    return 0;
}

int prosesTebakKode(int kode_rahasia, int sisa_kesempatan) {
    int tebakan;

    if (sisa_kesempatan == 0) {
        printf("\nKesempatan Anda telah habis!\n");
        printf("Kode rahasia yang benar adalah: %d\n", kode_rahasia);
        return 0;
    }

    printf("Masukkan tebakan kode Anda: ");
    scanf("%d", &tebakan);

    if (tebakan == kode_rahasia) {
        printf("Tebakan benar.\n");
        return 1;
    } 
    else if (tebakan < kode_rahasia) {
        printf("Tebakan terlalu kecil.\n");
        if (sisa_kesempatan - 1 > 0) {
            printf("Sisa kesempatan Anda: %d\n\n", sisa_kesempatan - 1);
        }
        return prosesTebakKode(kode_rahasia, sisa_kesempatan - 1);
    } 
    else {
        printf("Tebakan terlalu besar.\n");
        if (sisa_kesempatan - 1 > 0) {
            printf("Sisa kesempatan Anda: %d\n\n", sisa_kesempatan - 1);
        }
        return prosesTebakKode(kode_rahasia, sisa_kesempatan - 1);
    }
}

void tampilkanPesanAkhir(int status_berhasil, int kode_rahasia) {
    if (status_berhasil == 1) {
        printf("\nSelamat! Anda telah memenangkan permainan Tebak Kode!\n");
    } else {
        printf("\nGame Over! Anda gagal memecahkan kode.\n");
    }
}

void mulaiTebakKode() {
    int batas_bawah = 1;
    int batas_atas = 20;
    int kode_rahasia = (rand() % (batas_atas - batas_bawah + 1)) + batas_bawah;

    printf("==================================\n");
    printf("       PERMAINAN TEBAK KODE       \n");
    printf("==================================\n");
    printf("Sistem telah menetapkan kode rahasia berupa angka dari %d hingga %d.\n", batas_bawah, batas_atas);
    printf("Anda memiliki maksimal %d kesempatan untuk menebak kode ini.\n\n", batas_kesempatan);

    int status_berhasil = prosesTebakKode(kode_rahasia, batas_kesempatan);

    tampilkanPesanAkhir(status_berhasil, kode_rahasia);
}