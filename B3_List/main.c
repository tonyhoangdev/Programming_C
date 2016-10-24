#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef struct
{
    char name[10];
    int maSo;
    float diemTB;
    char account[10];
} fresher_t;

typedef enum
{
    maSo,
    diemTB
} kieuSX;

void printListFresher(list *pl);
void sapXep(list *list, kieuSX kieu);

int main()
{
    printf("Hello list fresher!\n");

    fresher_t fresherArr[] =
    {
        {"Nhi",  1, 8.5,"NhiNtk"},
        {"Minh", 5, 9,  "Minhkt"},
        {"Hoang",2, 9.5,"HoangMt"},
        {"Ngoc", 4, 8,  "NgocHk"}
    };

    int soLuong = sizeof(fresherArr) / sizeof(fresher_t);

    list *fresher = list_create();

    /* Them vao list */
    for (int i = 0; i < soLuong; i++)
    {
        list_push_end(fresher, fresherArr + i);
    }
    /* Print */
    printListFresher(fresher);

    /* Remove */
    list_remove_head(fresher);
    printf("Removed head element:\n");
    printListFresher(fresher);

    /* sap xep theo ma so */
    sapXep(fresher, maSo);
    printf("Sap xep theo ma so:\n");
    printListFresher(fresher);

    /* sap xep theo diem TB */
    sapXep(fresher, diemTB);
    printf("Sap xep theo diem TB:\n");
    printListFresher(fresher);

    /* Giai phong bo nho */
    list_destroy(fresher);

    /* Dung chuong trinh */
    printf("Press any key to exit...");
    getchar();
    return 0;
}

void printListFresher(list *pl)
{
    node *p = pl->head;
    while (p)
    {
        fresher_t *f = (fresher_t *)p->value;
        printf("%-12s%-5d%-5.1f%12s\n", f->name, f->maSo, f->diemTB, f->account);

        p = p->next;
    }
}

void sapXep(list *list, kieuSX kieu)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (node *p = list->head; p != list->tail; p = p->next)
        {
            fresher_t *fres1 = (fresher_t*)p->value;
            fresher_t *fres2 = (fresher_t*)p->next->value;
            float sx1 = 0;
            float sx2 = 0;

            if (kieu == maSo)
            {
                sx1 = fres1->maSo;
                sx2 = fres2->maSo;
            }
            else if (kieu == diemTB)
            {
                sx1 = fres1->diemTB;
                sx2 = fres2->diemTB;
            }

            if (sx1 > sx2)
            {
                void *c = p->value;
                p->value = p->next->value;
                p->next->value = c;
                sorted = false;
            }
        }
    }
}
