#include <stdio.h>

void hanoiKuleleri(int diskSayisi, char kaynakCubuk, char hedefCubuk, char araCubuk) {
    if (diskSayisi == 1) {
        printf("Disk 1'i %c çubuğundan %c çubuğuna taşı\n", kaynakCubuk, hedefCubuk);
        return;
    }
    hanoiKuleleri(diskSayisi - 1, kaynakCubuk, araCubuk, hedefCubuk);
    printf("Disk %d'i %c çubuğundan %c çubuğuna taşı\n", diskSayisi, kaynakCubuk, hedefCubuk);
    hanoiKuleleri(diskSayisi - 1, araCubuk, hedefCubuk, kaynakCubuk);
}

int main() {
    int diskSayisi;

    printf("Hanoi Kuleleri için disk sayısını girin: ");
    scanf("%d", &diskSayisi);

    hanoiKuleleri(diskSayisi, 'A', 'C', 'B');

    return 0;
}
