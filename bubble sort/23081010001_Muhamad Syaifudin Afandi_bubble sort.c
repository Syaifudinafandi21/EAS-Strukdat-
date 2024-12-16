#include <stdio.h>
#include <string.h>

typedef struct {
    char npm[15];
    char nama[50];
    char prodi[30];
    float ipk;
} Mahasiswa;

void tampilkanData(Mahasiswa mhs[], int jumlah) {
    printf("\nData Mahasiswa:\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("| %s | %-20s | %-10s | %.2f |\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
    printf("---------------------------------------------\n");
}

void urutkanBerdasarkanNPM(Mahasiswa mhs[], int jumlah, int ascending) {
    Mahasiswa temp;
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((ascending && strcmp(mhs[j].npm, mhs[j + 1].npm) > 0) ||
                (!ascending && strcmp(mhs[j].npm, mhs[j + 1].npm) < 0)) {
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

int main() {
    Mahasiswa mhs[] = {
        {"22081010001", "Andi Setiawan", "Informatika", 3.75},
        {"23081020045", "Budi Santoso", "Sistem Informasi", 3.60},
        {"21071010123", "Citra Anggraeni", "Agroteknologi", 3.85},
        {"23031020004", "Dewi Maharani", "Teknik Kimia", 3.40},
        {"23081010011", "Ailsa Maharani", "Informatika", 3.76}
    };
    int jumlah = 5;
    int pilihan;

    printf("Pilih metode penyortiran:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan (1 atau 2): ");
    scanf("%d", &pilihan);

    printf("\nSebelum diurutkan:\n");
    tampilkanData(mhs, jumlah);

    if (pilihan == 1) {
        urutkanBerdasarkanNPM(mhs, jumlah, 1);
    } else if (pilihan == 2) {
        urutkanBerdasarkanNPM(mhs, jumlah, 0);
    } else {
        printf("Pilihan tidak valid.\n");
        return 1;
    }

    printf("\nSetelah diurutkan berdasarkan NPM:\n");
    tampilkanData(mhs, jumlah);

    return 0;
}
