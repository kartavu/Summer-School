#include <stdio.h>
#include <stdlib.h>

#include "libcalc.h"

int main() {
    int menu = 0;
    int a = 0;
    int b = 0;
    
    while(menu != 5) {
        printf("Выберите действие:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");

        scanf("%d", &menu);
        getchar();

        if (menu != 5) { 
            printf("Введите а ");
            scanf("%d", &a);
            printf("Введите b ");
            scanf("%d", &b);    
            getchar();
        }

        switch(menu) {
            case 1:
                printf("%d + %d = %d\n", a, b, add(a, b));
                break;
            case 2:
                printf("%d - %d = %d\n", a, b, sub(a, b));
                break;
            case 3:
                printf("%d * %d = %d\n", a, b, mul(a, b));
                break;
            case 4:
                if (b == 0) {
                    printf("Error");
                    printf("Второе число равно 0\n");
                } else {
                    printf("%d / %d = %d\n", a, b, del(a, b));
                }
                break;
            case 5:
                break;
            default:
                printf("Введено неверное действие\n");
                break;
        }
    }
    printf("Exit\n");
    return 0;
}