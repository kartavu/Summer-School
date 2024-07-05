#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 100

int main() {
    int task = 0;

    printf("Введите номер задания:");
    scanf("%d", &task);

    switch (task) {
        case 1: {
            unsigned a = 0;
            unsigned b = 0;

            printf("Введите положительное число: ");
            if (scanf("%d", &a) != 1) {
                printf("n/a\n");
                return 1;
            }

            printf("Введите число, которое заменит 3 байт: ");
            if (scanf("%d", &b) != 1) {
                printf("n/a\n");
                return 1;
            }

            unsigned char* ptr = (unsigned char*)&a;;
            ptr = ptr + 2;
            *ptr = b;

            printf("Change third byte: %u\n", a);
            break;
        }

        case 2: {
            float x = 5.0;
            printf("x = %f, ", x);
            float y = 6.0;
            printf("y =  %f\n", y);

            float *xp = &x;
            *xp = *xp + 1.0;
            printf("xp = %f, ", *xp);
            float *yp = &y;
            printf("Результат: %f\n", *xp + *yp);
            break;
        }

        case 3: {
            int n = 10;
            int array[n];
            
            for (int *ptr = array; ptr < array + n; ptr++) {
                *ptr = rand() % 10;
            }
            int *ptr = array;
            while (ptr !=array + n) {
                printf("%d ", *ptr);
                ptr++;
            }
            printf("\n");
            break;
        }

        case 4: {
            char str1[N_MAX];
            char str2[N_MAX];

            printf("Введите строку: ");
            scanf("%s", str1);

            printf("Введите строку поиска: ");
            scanf("%s", str2);
            char *ptr = NULL;
            for (char *ptr1 = str1; *ptr1 != '\0'; ptr1++) {
                char *p1 = ptr1;
                char *p2 = str2;

                while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
                    p1++;
                    p2++;
                }

                if (*p2 == '\0') {
                    ptr = ptr1;
                    break;
                }
            }
            if (ptr) {
                printf("%s\n", ptr);
            } else {
                ptr = NULL;
                printf("%s\n", ptr);
            }
            break;
        }
        default:
            printf("Неверный номер задания.\n");
            break;

    }
}
