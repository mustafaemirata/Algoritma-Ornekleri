#include <stdio.h>
#include <stdlib.h>

struct notlar {
    int vize1;
    struct notlar* bag;
};

int main() {
    struct notlar *yeniadres, *ilk, *son;

    yeniadres = (struct notlar*)malloc(sizeof(struct notlar));
    if (yeniadres == NULL) {
        printf("Hafiza tahsisi basarisiz!\n");
        return 1;
    }

    printf("Yeniadres: %p\n",yeniadres);
    ilk = yeniadres;
    son = yeniadres;
    yeniadres->vize1 = 79;
    yeniadres->bag = NULL;

    printf("ilk: %p\n", (void*)ilk);
    printf("son: %p\n", (void*)son);
    printf("T1___yeniadres->vize1: %d yeniadres->bag: %p\n", yeniadres->vize1,yeniadres->bag);

    yeniadres = (struct notlar*)malloc(sizeof(struct notlar));
    if (yeniadres == NULL) {
        printf("Hafiza tahsisi basarisiz!\n");
        return 1;
    }

    printf("Yeniadres: %p\n", yeniadres);
    son->bag = yeniadres;
    yeniadres->vize1 = 95;
    yeniadres->bag = NULL;
    son = yeniadres;

    printf("ilk: %p\n", ilk);
    printf("son: %p\n", son);
    printf("T2___yeniadres->vize1: %d yeniadres->bag: %p\n", yeniadres->vize1, yeniadres->bag);

    struct notlar* temp;
    while (ilk != NULL) {
        temp = ilk;
        ilk = ilk->bag;
        free(temp);
    }

    return 0;
}
