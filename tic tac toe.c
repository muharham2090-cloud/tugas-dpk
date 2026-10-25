
#include <stdio.h>

char papan[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void tampilkanPapan() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n",
               papan[i][0], papan[i][1], papan[i][2]);

        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int cekMenang(char pemain) {
    // Memeriksa baris dan kolom
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == pemain &&
            papan[i][1] == pemain &&
            papan[i][2] == pemain) {
            return 1;
        }

        if (papan[0][i] == pemain &&
            papan[1][i] == pemain &&
            papan[2][i] == pemain) {
            return 1;
        }
    }

    // Memeriksa diagonal
    if (papan[0][0] == pemain &&
        papan[1][1] == pemain &&
        papan[2][2] == pemain) {
        return 1;
    }

    if (papan[0][2] == pemain &&
        papan[1][1] == pemain &&
        papan[2][0] == pemain) {
        return 1;
    }

    return 0;
}

int main() {
    int baris, kolom;
    char pemain = 'X';

    printf("=== TIC TAC TOE ===\n");
    printf("Pemain 1: X\n");
    printf("Pemain 2: O\n");
    printf("Masukkan baris dan kolom dari 1 sampai 3.\n");

    for (int giliran = 0; giliran < 9; giliran++) {
        tampilkanPapan();

        printf("Giliran pemain %c\n", pemain);
        printf("Masukkan baris: ");

        if (scanf("%d", &baris) != 1) {
            printf("Input harus berupa angka!\n");
            return 1;
        }

        printf("Masukkan kolom: ");

        if (scanf("%d", &kolom) != 1) {
            printf("Input harus berupa angka!\n");
            return 1;
        }

        // Memeriksa batas baris dan kolom
        if (baris < 1 || baris > 3 ||
            kolom < 1 || kolom > 3) {
            printf("Baris dan kolom harus 1-3!\n");
            giliran--;
            continue;
        }

        // Mengubah posisi menjadi indeks array
        baris--;
        kolom--;

        // Memeriksa apakah kotak sudah terisi
        if (papan[baris][kolom] != ' ') {
            printf("Kotak sudah terisi! Pilih kotak lain.\n");
            giliran--;
            continue;
        }

        // Menempatkan simbol pemain
        papan[baris][kolom] = pemain;

        // Memeriksa pemenang
        if (cekMenang(pemain)) {
            tampilkanPapan();
            printf("Selamat! Pemain %c menang!\n", pemain);
            return 0;
        }

        // Mengganti giliran pemain
        if (pemain == 'X') {
            pemain = 'O';
        } else {
            pemain = 'X';
        }
    }

    tampilkanPapan();
    printf("Permainan berakhir seri!\n");

    return 0;
}
