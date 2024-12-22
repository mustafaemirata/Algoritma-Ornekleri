#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

typedef struct Dugum Dugum;

void yiginEkle(Dugum** tepe, int veri) {
    Dugum* yeniDugum = (Dugum*)malloc(sizeof(Dugum));
    if (!yeniDugum) {
        printf("Bellek tahsisi başarısız!\n");
        exit(1);
    }
    yeniDugum->veri = veri;
    yeniDugum->sonraki = *tepe;
    *tepe = yeniDugum;
}

int yiginCikar(Dugum** tepe) {
    if (*tepe == NULL) {
        printf("Yığın boş!\n");
        return -1;
    }
    Dugum* silinecek = *tepe;
    int cikarilanVeri = silinecek->veri;
    *tepe = silinecek->sonraki;
    free(silinecek);
    return cikarilanVeri;
}

int yiginTepe(Dugum* tepe) {
    if (tepe == NULL) {
        printf("Yığın boş!\n");
        return -1;
    }
    return tepe->veri;
}

void yiginYazdir(Dugum* tepe) {
    if (tepe == NULL) {
        printf("Yığın boş!\n");
        return;
    }
    Dugum* gecici = tepe;
    while (gecici != NULL) {
        printf("%d\n", gecici->veri);
        gecici = gecici->sonraki;
    }
}

void yiginTemizle(Dugum** tepe) {
    while (*tepe != NULL) {
        yiginCikar(tepe);
    }
}

int main() {
    Dugum* tepe = NULL; 

    yiginEkle(&tepe, 10);
    yiginEkle(&tepe, 20);
    yiginEkle(&tepe, 30);

    printf("Yığın elemanları:\n");
    yiginYazdir(tepe);

    printf("Tepe elemanı: %d\n", yiginTepe(tepe));

    printf("Çıkarılan eleman: %d\n", yiginCikar(&tepe));

    printf("Yığın elemanları (güncel):\n");
    yiginYazdir(tepe);

    yiginTemizle(&tepe);

    return 0;
}
