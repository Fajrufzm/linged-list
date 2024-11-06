#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **plist);
void tambahTengah(node **plist);
void tambahAkhir(node **plist);
void tranverse(node *plist);
void hapusAwal(node **plist);
void hapusTengah(node **plist);
void hapusAkhir(node **plist);
void cariData(node **plist);
void jumlahData(node **plist);
void totalData(node **plist);

int main() {
    node *plist = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal list\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal list\n");
        printf("6. Hapus data di tengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data di dalam list\n");
        printf("9. Jumlah data di dalam list\n");
        printf("0. Hasil penjumlahan semua data dalam list\n");
        printf("MASUKKAN PILIHAN (tekan k untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1')
            tambahAwal(&plist);
        else if (pilih == '2')
            tambahTengah(&plist);
        else if (pilih == '3')
            tambahAkhir(&plist);
        else if (pilih == '4') {
            tranverse(plist);
            getch();
        }
        else if (pilih == '5')
            hapusAwal(&plist);
        else if (pilih == '6')
            hapusTengah(&plist);
        else if (pilih == '7')
            hapusAkhir(&plist);
        else if (pilih == '8')
            cariData(&plist);
        else if (pilih == '9')
            jumlahData(&plist);
        else if (pilih == '0')
            totalData(&plist);

    } while (pilih != 'k');

    return 0;
}

//========================================================
// Menambah data di awal list
void tambahAwal(node **plist) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *plist;
        *plist = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
// Menambah data di tengah list
void tambahTengah(node **plist) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*plist);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *plist;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else {
        pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("\nAlokasi memori gagal");
            getch();
        } else {
            pNew->data = bil;
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    }
}

//========================================================
// Menambah data di akhir list
void tambahAkhir(node **plist) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*plist == NULL) {
            *plist = pNew;
        } else {
            pCur = *plist;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
// Cetak isi list
void tranverse(node *plist) {
    node *pCur = plist;
    if (pCur == NULL) {
        printf("List kosong\n");
        return;
    }

    while (pCur != NULL) {
        printf("%d -> ", pCur->data);
        pCur = pCur->next;
    }
    printf("NULL\n");
}

//========================================================
// Hapus data di awal
void hapusAwal(node **plist) {
    node *pCur;

    if (*plist == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *plist;
    *plist = pCur->next;
    free(pCur);

    printf("Data awal berhasil dihapus\n");
    getch();
}

//========================================================
// hapus data tengah
void hapusTengah(node **head) {
    int bil;
    node *pCur, *pPrev = NULL;

    system("cls");
    tranverse(*head);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong");
        getch();
        return;
    }

    pCur = *head;

    while (pCur != NULL && pCur->data != bil) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("\nData tidak ditemukan");
        getch();
    } else {
        if (pPrev == NULL) {
            hapusAwal(head);
        } else {
            pPrev->next = pCur->next;
            free(pCur);
            printf("\nData berhasil dihapus");
            getch();
        }
    }
}

//========================================================
// hapus data akhir
void hapusAkhir(node **head) {
    node *pCur, *pPrev = NULL;

    if (*head == NULL) {
        printf("\nList kosong");
        getch();
        return;
    }

    pCur = *head;

    if (pCur->next == NULL) {
        free(pCur);
        *head = NULL;
    } else {
        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = NULL;
        free(pCur);
    }
    printf("\nData berhasil dihapus");
    getch();
}

//========================================================
// cari data
void cariData(node **plist) {
    int bil;
    node *pCur;
    int found = 0;

    if (*plist == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *plist;
    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan dalam list\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->next;
    }

    if (!found) {
        printf("Data %d tidak ditemukan dalam list\n", bil);
    }
    getch();
}

//========================================================
// Menghitung jumlah data dalam list
void jumlahData(node **plist) {
    int count = 0;
    node *pCur;

    if (*plist == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *plist;
    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//========================================================
// Menghitung total penjumlahan data dalam list
void totalData(node **plist) {
    int total = 0;
    node *pCur;

    if (*plist == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *plist;
    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }

    printf("Total penjumlahan semua data dalam list: %d\n", total);
    getch();
}

