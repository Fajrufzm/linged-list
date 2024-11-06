#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head, int pos);
void hapusAkhir(node **head);
void cariData(node *head, int target);
void hitungData(node *head);
void jumlahkanData(node *head);
void tranverse(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Tampilkan jumlah data\n");
        printf("9. Tampilkan hasil penjumlahan data\n");
        printf("10. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
            hapusAwal(&head);
        else if (pilih == '5') {
            int pos;
            printf("Masukkan nilai yang ingin dihapus: ");
            scanf("%d", &pos);
            hapusTengah(&head, pos);
        }
        else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7') {
            int target;
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &target);
            cariData(head, target);
        }
        else if (pilih == '8')
            hitungData(head);
        else if (pilih == '9')
            jumlahkanData(head);
        else if (pilih == '0') {
            tranverse(head);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void tambahAkhir(node **head) {
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

        if (*head == NULL) {
            *head = pNew; // Jika list kosong
        } else {
            pCur = *head;
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

void hapusAwal(node **head) {
    node *pTemp;

    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus");
        getch();
        return;
    }

    pTemp = *head;
    *head = (*head)->next;
    free(pTemp);
}

//========================================================

void hapusTengah(node **head, int pos) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus");
        getch();
        return;
    }

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node tidak ditemukan");
        getch();
    } else {
        pPrev->next = pCur->next;
        free(pCur);
    }
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus");
        getch();
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = NULL;
        free(pCur);
    }
}

//========================================================

void cariData(node *head, int target) {
    node *pCur = head;
    int posisi = 0;

    while (pCur != NULL) {
        posisi++;
        if (pCur->data == target) {
            printf("Data %d ditemukan di posisi %d\n", target, posisi);
            return;
        }
        pCur = pCur->next;
    }

    printf("Data %d tidak ditemukan dalam list\n", target);
}

//========================================================

void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam linked list: %d\n", count);
}

//========================================================

void jumlahkanData(node *head) {
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah semua data dalam linked list: %d\n", sum);
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    }
    printf("NULL");
}

