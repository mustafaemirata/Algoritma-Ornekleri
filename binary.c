#include <stdio.h>

int ikiliArama(int dizi[], int boyut, int hedef) {
    int sol = 0, sag = boyut - 1;

    while (sol <= sag) {
        int ortadaki = sol + (sag - sol) / 2;

        if (dizi[ortadaki] == hedef)
            return ortadaki;

        if (dizi[ortadaki] > hedef)
            sag = ortadaki - 1;

        else
            sol = ortadaki + 1;
    }

    return -1;
}

int main() {
    int dizi[] = {2, 3, 4, 10, 40};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    int hedef = 10;

    int sonuc = ikiliArama(dizi, boyut, hedef);

    if (sonuc != -1)
        printf("Eleman %d. indekste bulundu.\n", sonuc);
    else
        printf("Eleman bulunamadı.\n");

    return 0;
}
