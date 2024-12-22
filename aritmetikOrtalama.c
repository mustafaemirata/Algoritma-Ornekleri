#include <stdio.h>

// En küçük elemanı bulan fonksiyon
float enKucuk(float A[], int n)
{
    float enKucuk = A[0];
    for (int k = 1; k < n; k++)
    {
        if (A[k] < enKucuk)
        {
            enKucuk = A[k];
        }
    }
    return enKucuk;
}

// Dizide bir sayıyı arayan fonksiyon
int ikiliArama(int A[], int N, int Sayi)
{
    int i = 0;
    while (i < N)
    {
        if (A[i] == Sayi)
        {
            return i; // Sayı bulundu
        }
        i++;
    }
    return -1; // Sayı bulunamadı
}

int main()
{
    int len;
    printf("Dizi uzunlugunu giriniz: ");
    scanf("%d", &len);

    // Float dizi tanımlama
    float A[len];
    printf("Float dizi elemanlarini giriniz:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%f", &A[i]);
    }

    // En küçük elemanı bulma
    float kucukEleman = enKucuk(A, len);
    printf("Dizinin en kucuk elemani: %.2f\n", kucukEleman);

    // İkili arama için integer dizi tanımlama
    int B[len];
    printf("\nInteger dizi elemanlarini giriniz:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &B[i]);
    }

    // Dizide sayı arama
    int sayi;
    printf("Aramak istediginiz sayiyi giriniz: ");
    scanf("%d", &sayi);

    int aramaSonuc = ikiliArama(B, len, sayi);
    if (aramaSonuc != -1)
    {
        printf("Aranan sayi bulundu! Indeks: %d\n", aramaSonuc);
    }
    else
    {
        printf("Aranan sayi dizide bulunamadi!\n");
    }

    return 0;
}
