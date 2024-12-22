#include <stdio.h>
int main()
{
    int dizi[] = {10, 20, 30, 40, 50};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    int toplam = 0;

    for (int i = 0; i < boyut; i++)
    {
        toplam += dizi[i];
    }

    float ortalama = (float)toplam / boyut;
    printf("Dizinin ortalaması: %.2f\n", ortalama);

    return 0;
}
