#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pleft;
    struct node *pright;
};
typedef struct node node;

void tambahAwal(node **phead);
void tambahTengah(node **phead);
void tambahAkhir(node **phead);
void tranverse(node *phead);
void hapusAwal(node **phead);
void hapusTengah(node **phead);
void hapusAkhir(node **phead);

int main() {
    node *phead = NULL;
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
        printf("MASUKKAN PILIHAN (tekan k untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1')
            tambahAwal(&phead);
        else if (pilih == '2')
            tambahTengah(&phead);
        else if (pilih == '3')
            tambahAkhir(&phead);
        else if (pilih == '4') {
            tranverse(phead);
            getch();
        }
        else if (pilih == '5')
            hapusAwal(&phead);
        else if (pilih == '6')
            hapusTengah(&phead);
        else if (pilih == '7')
            hapusAkhir(&phead);

    } while (pilih != 'k');

    return 0;
}

//========================================================
// Tambah data di awal list
void tambahAwal(node **phead) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->pleft = NULL;
        pNew->pright = *phead;

        if (*phead != NULL)
            (*phead)->pleft = pNew;

        *phead = pNew;
    } else {
        printf("Alokasi memori gagal\n");
        getch();
    }
}

//========================================================
// Tambah data di tengah list
void tambahTengah(node **phead) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*phead);
    printf("\nMasukkan data setelah nilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nMasukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *phead;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->pright;
    }

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan\n");
        getch();
    } else {
        pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("Alokasi memori gagal\n");
            getch();
        } else {
            pNew->data = bil;
            pNew->pleft = pCur;
            pNew->pright = pCur->pright;

            if (pCur->pright != NULL)
                pCur->pright->pleft = pNew;

            pCur->pright = pNew;
        }
    }
}

//========================================================
// Tambah data di akhir list
void tambahAkhir(node **phead) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->pright = NULL;

        if (*phead == NULL) {
            pNew->pleft = NULL;
            *phead = pNew;
        } else {
            pCur = *phead;

            while (pCur->pright != NULL) {
                pCur = pCur->pright;
            }

            pCur->pright = pNew;
            pNew->pleft = pCur;
        }
    } else {
        printf("Alokasi memori gagal\n");
        getch();
    }
}

//========================================================
// Cetak isi list
void tranverse(node *phead) {
    node *pCur = phead;

    if (pCur == NULL) {
        printf("List kosong\n");
        return;
    }

    while (pCur != NULL) {
        printf("%d -> ", pCur->data);
        pCur = pCur->pright;
    }
    printf("NULL\n");
}

//========================================================
// Hapus data di awal list
void hapusAwal(node **phead) {
    node *pCur;

    if (*phead == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *phead;
    *phead = pCur->pright;

    if (*phead != NULL)
        (*phead)->pleft = NULL;

    free(pCur);

    printf("Data awal berhasil dihapus\n");
    getch();
}

//========================================================
// Hapus data di tengah list
void hapusTengah(node **phead) {
    int bil;
    node *pCur;

    system("cls");
    tranverse(*phead);
    printf("\nMasukkan bilangan yang akan dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*phead == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *phead;
    while (pCur != NULL && pCur->data != bil) {
        pCur = pCur->pright;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
        getch();
    } else {
        if (pCur->pleft != NULL)
            pCur->pleft->pright = pCur->pright;

        if (pCur->pright != NULL)
            pCur->pright->pleft = pCur->pleft;

        if (pCur == *phead)
            *phead = pCur->pright;

        free(pCur);
        printf("Data berhasil dihapus\n");
        getch();
    }
}

//========================================================
// Hapus data di akhir list
void hapusAkhir(node **phead) {
    node *pCur;

    if (*phead == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *phead;

    while (pCur->pright != NULL) {
        pCur = pCur->pright;
    }

    if (pCur->pleft != NULL)
        pCur->pleft->pright = NULL;

    if (pCur == *phead)
        *phead = NULL;

    free(pCur);
    printf("Data berhasil dihapus\n");
    getch();
}
