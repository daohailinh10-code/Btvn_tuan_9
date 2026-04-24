#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== C?U TRÚC ======
Struct Sinhvien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
} ;

struct Ngay
{
   int ngay, thang, nam;
};
struct Node 
{ 
   Sinhvien data;
   Node *link;
};
struct List
{
   Node *first;
   Node *last;
};

void initList(List *l) {
    l->head = NULL;
}

Node* createNode(Sinhvien sv) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = sv;
    p->next = NULL;
    return p;
}

// ====== SO SÁNH MÃ SV ======
int cmpMaSV(char *a, char *b) {
    return strcmp(a, b);
}

// ====== CHÈN CÓ S?P X?P ======
void insertSorted(List *l, SinhVien sv) {
    Node *p = createNode(sv);

    if (l->head == NULL || cmpMaSV(sv.maSV, l->head->data.maSV) < 0) {
        p->next = l->head;
        l->head = p;
        return;
    }

    Node *cur = l->head;
    while (cur->next != NULL && cmpMaSV(cur->next->data.maSV, sv.maSV) < 0) {
        cur = cur->next;
    }

    p->next = cur->next;
    cur->next = p;
}

// ====== NH?P ======
void nhapDanhSach(List *l, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        printf("\nNhap SV thu %d:\n", i + 1);

        printf("Ma SV: ");
        scanf("%s", sv.maSV);
        getchar();

        printf("Ho ten: ");
        fgets(sv.hoTen, 50, stdin);
        sv.hoTen[strcspn(sv.hoTen, "\n")] = 0;

        printf("Gioi tinh: ");
        fgets(sv.gioiTinh, 10, stdin);
        sv.gioiTinh[strcspn(sv.gioiTinh, "\n")] = 0;

        printf("Ngay sinh: ");
        scanf("%s", sv.ngaySinh);
        getchar();

        printf("Dia chi: ");
        fgets(sv.diaChi, 100, stdin);
        sv.diaChi[strcspn(sv.diaChi, "\n")] = 0;

        printf("Lop: ");
        scanf("%s", sv.lop);

        printf("Khoa: ");
        scanf("%s", sv.khoa);

        insertSorted(l, sv); // chèn luôn dúng th? t?
    }
}

// ====== IN ======
void inDanhSach(List l) {
    Node *p = l.head;
    while (p != NULL) {
        printf("%s | %s | %s | %s | %s | %s | %s\n",
               p->data.maSV,
               p->data.hoTen,
               p->data.gioiTinh,
               p->data.ngaySinh,
               p->data.diaChi,
               p->data.lop,
               p->data.khoa);
        p = p->next;
    }
}

// ====== Ð?M NGÀY SINH ======
int demNgaySinh(List l, char *ngay) {
    int count = 0;
    Node *p = l.head;
    while (p != NULL) {
        if (strcmp(p->data.ngaySinh, ngay) == 0)
            count++;
        p = p->next;
    }
    return count;
}

void inSVTrungNgaySinh(List l) {
    Node *p = l.head;
    int found = 0;

    while (p != NULL) {
        if (demNgaySinh(l, p->data.ngaySinh) > 1) {
            printf("%s | %s | %s\n",
                   p->data.maSV,
                   p->data.hoTen,
                   p->data.ngaySinh);
            found = 1;
        }
        p = p->next;
    }

    if (!found)
        printf("khong tim thay sinh vien cung ngay sinh\n");
}

void xoaTheoNgaySinh(List *l, char *ngay) {
    while (l->head != NULL && strcmp(l->head->data.ngaySinh, ngay) == 0) {
        Node *tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }

    Node *p = l->head;
    while (p != NULL && p->next != NULL) {
        if (strcmp(p->next->data.ngaySinh, ngay) == 0) {
            Node *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
}

void xoaSVTrungNgaySinh(List *l) {
    Node *p = l->head;

    while (p != NULL) {
        if (demNgaySinh(*l, p->data.ngaySinh) > 1) {
            char ngay[15];
            strcpy(ngay, p->data.ngaySinh);
            xoaTheoNgaySinh(l, ngay);
            p = l->head; // duy?t l?i t? d?u
        } else {
            p = p->next;
        }
    }
}

// ====== MAIN ======
int main() {
    List l;
    initList(&l);

    int n;
    printf("Nhap so luong SV: ");
    scanf("%d", &n);

    nhapDanhSach(&l, n);

    printf("\nDanh sach sau khi sap xep:\n");
    inDanhSach(l);

    printf("\nSinh vien trung ngay sinh:\n");
    inSVTrungNgaySinh(l);

    xoaSVTrungNgaySinh(&l);

    printf("\nDanh sach sau khi xoa:\n");
    inDanhSach(l);

    return 0;
}

