// Nama : Alqan Nazra (231511068)
// Nama : Muhammad Wildan Gumilang (231511087)

#include "header.h"

int main() {
    int nKota;
    inputJumlahKota(&nKota);

    namaKota P[nKota];
    inputNamaKota(P, nKota);

    int pil;
    do {
        menu(P, nKota);
        printf("\nApakah Anda ingin kembali ke menu utama? (1/0) : ");
        scanf("%d", &pil);
    } while (pil == 1);

    printf("Terima kasih telah menggunakan program ini!\n");

    return 0;
}
