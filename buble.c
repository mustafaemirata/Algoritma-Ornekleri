#include <stdio.h>

void bubbleSort(int dizi[], int boyut) {
    for (int i = 0; i < boyut - 1; i++) {
        for (int j = 0; j < boyut - 1 - i; j++) 
        {
            if (dizi[j] > dizi[j + 1]) {
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

int main() {
    int dizi[] = {64, 34, 25, 12, 22, 11, 90};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    printf("Sıralama öncesi: \n");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    bubbleSort(dizi, boyut);


    printf("Sıralama sonrası: \n");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    return 0;
}
