#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi pasien
typedef struct {
    char nama[100];
    char no_telp[20];
    char penyakit[100];
    char status_rawat[20]; // "Rawat Inap" atau "Tidak"
} Pasien;

// Fungsi untuk menyimpan data pasien ke file
void simpanKeFile(const char *filename, Pasien *pasien, int jumlah_pasien) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Gagal membuka file untuk menyimpan data");
        return;
    }
    for (int i = 0; i < jumlah_pasien; i++) {
        fprintf(file, "Nama: %s\nNomor Telepon: %s\nPenyakit: %s\nStatus Rawat: %s\n\n",
                pasien[i].nama, pasien[i].no_telp, pasien[i].penyakit, pasien[i].status_rawat);
    }
    fclose(file);
    printf("Data pasien berhasil disimpan ke file '%s'\n", filename);
}

// Fungsi untuk membaca data pasien dari file
void bacaDariFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Gagal membuka file untuk membaca data");
        return;
    }
    char buffer[256];
    printf("Isi file '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    int jumlah_pasien;
    Pasien *daftar_pasien;
    char filename[100];

    printf("Masukkan nama file untuk menyimpan data pasien: ");
    scanf("%s", filename);
    getchar(); // Membersihkan karakter newline dari input sebelumnya

    printf("Masukkan jumlah pasien: ");
    scanf("%d", &jumlah_pasien);
    getchar(); // Membersihkan karakter newline dari input sebelumnya

    // Alokasi memori untuk daftar pasien
    daftar_pasien = (Pasien *)malloc(jumlah_pasien * sizeof(Pasien));
    if (daftar_pasien == NULL) {
        perror("Gagal mengalokasikan memori");
        return 1;
    }

    // Input data pasien
    for (int i = 0; i < jumlah_pasien; i++) {
        printf("\nMasukkan data untuk pasien %d:\n", i + 1);

        printf("Nama: ");
        fgets(daftar_pasien[i].nama, sizeof(daftar_pasien[i].nama), stdin);
        daftar_pasien[i].nama[strcspn(daftar_pasien[i].nama, "\n")] = '\0'; // Menghapus newline

        printf("Nomor Telepon: ");
        fgets(daftar_pasien[i].no_telp, sizeof(daftar_pasien[i].no_telp), stdin);
        daftar_pasien[i].no_telp[strcspn(daftar_pasien[i].no_telp, "\n")] = '\0';

        printf("Penyakit: ");
        fgets(daftar_pasien[i].penyakit, sizeof(daftar_pasien[i].penyakit), stdin);
        daftar_pasien[i].penyakit[strcspn(daftar_pasien[i].penyakit, "\n")] = '\0';

        printf("Status Rawat (Rawat Inap/Tidak): ");
        fgets(daftar_pasien[i].status_rawat, sizeof(daftar_pasien[i].status_rawat), stdin);
        daftar_pasien[i].status_rawat[strcspn(daftar_pasien[i].status_rawat, "\n")] = '\0';
    }

    // Simpan data ke file
    simpanKeFile(filename, daftar_pasien, jumlah_pasien);

    // Baca data dari file
    bacaDariFile(filename);

    // Membersihkan memori yang dialokasikan
    free(daftar_pasien);

    return 0;
}
