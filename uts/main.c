#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pasien{
    char NRP[10];
    char nama[50];
    char alamat[150];
    char umur[2];
    char jeniskelamin[10];
};

void inputpasien(struct pasien *psn){
    printf("masukan NRP: ");
    fgets(psn->NRP, sizeof (psn->NRP), stdin);
    psn->NRP[strcspn(psn->NRP, "\n")] = 0;

    printf("masukan nama pasien: ");
    fgets(psn->nama, sizeof(psn->nama), stdin);
    psn->nama[strcspn(psn->nama, "\n")] = 0;

    printf("masukan alamat pasien: ");
    fgets(psn->alamat, sizeof(psn->alamat), stdin);
    psn->alamat[strcspn(psn->alamat, "\n")] = 0;

    printf("masukan umur pasien: ");
    fgets(psn->umur, sizeof(psn->umur), stdin);
    psn->umur[strcspn(psn->umur, "\n")] = 0;

    printf("masukan jenis kelamin pasien: ");
    fgets(psn->jeniskelamin, sizeof(psn->jeniskelamin), stdin);
    psn->jeniskelamin[strcspn(psn->jeniskelamin, "\n")] = 0;

}
void tampilkanpasien(struct pasien psn){
    printf("id: ", psn.NRP);
    printf("nama: ", psn.nama);
    printf("alamat: ", psn.alamat);
    printf("umur: ", psn.umur);
    printf("jenis kelamin: ", psn.jeniskelamin);
}

void caripasien(struct pasien psn, int jumlah, char NRPDicari){
    for (int i = 0; i < jumlah; i++){
        if (strcmp(psn.NRP[i], NRPDicari) == 0){
            jumlah++;
            tampilkanpasien == 1;
        }
    }if (tampilkanpasien == 1){
        printf("pasien ditemukan\n");
    }else{
    printf("pasien tidak ditemukan");
    }
}

int main()
{
    struct pasien *psn;
    char pilih;
    int jumlah;


    do{
     printf("masukkan pilihan\n");
     printf("1. input baru\n");
     printf("2. tampilkan semua pasien\n");
     printf("3. cari pasien\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		inputpasien(psn);
     else if (pilih == '2')
			tampilkanpasien(*psn);
     else if (pilih == '3')
            caripasien(*psn, jumlah);
         getch();
     } while (pilih != '0');

  return 0;
  }




