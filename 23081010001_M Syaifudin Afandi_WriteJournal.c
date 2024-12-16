#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void cetak_jurnal(char judul[], char penulis[], char afiliasi[], char email[], char abstrak[], char kata_kunci[]);
bool validasi_judul(char judul[]);
bool validasi_penulis(char penulis[]);
bool validasi_email(char email[]);
bool validasi_abstrak(char abstrak[]);
bool validasi_kata_kunci(char kata_kunci[]);

int main() {
    char judul[100], penulis[100], afiliasi[50], email[80], abstrak[1000], kata_kunci[80];

    do {
        printf("Masukkan judul (5-14 kata): ");
        fgets(judul, sizeof(judul), stdin);
        judul[strcspn(judul, "\n")] = 0;
    } while (!validasi_judul(judul));

    do {
        printf("Masukkan penulis (maks 3 penulis, dipisah koma): ");
        fgets(penulis, sizeof(penulis), stdin);
        penulis[strcspn(penulis, "\n")] = 0;
    } while (!validasi_penulis(penulis));

    printf("Masukkan afiliasi: ");
    fgets(afiliasi, sizeof(afiliasi), stdin);
    afiliasi[strcspn(afiliasi, "\n")] = 0;

    do {
        printf("Masukkan email (@ac.id): ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;
    } while (!validasi_email(email));

    do {
        printf("Masukkan abstrak (maks 200 kata): ");
        fgets(abstrak, sizeof(abstrak), stdin);
        abstrak[strcspn(abstrak, "\n")] = 0;
    } while (!validasi_abstrak(abstrak));

    do {
        printf("Masukkan kata kunci (3-5 kata, dipisah koma): ");
        fgets(kata_kunci, sizeof(kata_kunci), stdin);
        kata_kunci[strcspn(kata_kunci, "\n")] = 0;
    } while (!validasi_kata_kunci(kata_kunci));

    cetak_jurnal(judul, penulis, afiliasi, email, abstrak, kata_kunci);

    return 0;
}

void cetak_jurnal(char judul[], char penulis[], char afiliasi[], char email[], char abstrak[], char kata_kunci[]) {
    printf("\nJurnal Lengkap:\n");
    printf("Judul: %s\n", judul);
    printf("Penulis: %s\n", penulis);
    printf("Afiliasi: %s\n", afiliasi);
    printf("Email: %s\n", email);
    printf("Abstrak: %s\n", abstrak);
    printf("Kata Kunci: %s\n", kata_kunci);
}

bool validasi_judul(char judul[]) {
    int count = 1;
    for (int i = 0; i < strlen(judul); i++) {
        if (judul[i] == ' ') {
            count++;
        }
    }
    return count >= 5 && count <= 14;
}

bool validasi_penulis(char penulis[]) {
    int count = 1;
    for (int i = 0; i < strlen(penulis); i++) {
        if (penulis[i] == ',') {
            count++;
        }
    }
    return count <= 3;
}

bool validasi_email(char email[]) {
    int len = strlen(email);
    if (len < 9) return false;

    char *domain = strstr(email, ".ac.id");
    if (domain == NULL || strcmp(domain, ".ac.id") != 0) {
        return false;
    }

    char *at = strchr(email, '@');
    if (at == NULL || at > domain) {
        return false;
    }

    return true;
}

bool validasi_abstrak(char abstrak[]) {
    int count = 1;
    for (int i = 0; i < strlen(abstrak); i++) {
        if (abstrak[i] == ' ') {
            count++;
        }
    }
    return count <= 200;
}

bool validasi_kata_kunci(char kata_kunci[]) {
    int count = 1;
    for (int i = 0; i < strlen(kata_kunci); i++) {
        if (kata_kunci[i] == ',') {
            count++;
        }
    }
    return count >= 3 && count <= 5;
}
