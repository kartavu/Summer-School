#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void binary( unsigned int a, int b) {
    int n = 0;
    char result[MAX_SIZE];

    int flag = 0;

    while (a > 0) {
        result[n++] = (a % 2) + '0';
        a = a / 2;
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", result[i]);
        if (result[i] == '1') {
            flag++;
        }
    }
    printf("\n");
    if (b == 3) {
        printf("Единиц %d", flag);
    }
}

void negative_binary(int a) {
    int n = 0;
    char result[MAX_SIZE];
    char results[MAX_SIZE];

    a = -a;
    while (a > 0) {
        result[n++] = (a % 2) + '0';
        a = a / 2;
    }

    while (n < 8) {
        result[n++] = '0';
    }
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        results[j] = result[i];
        j++;
    }
    for (int i = 0; i < n; i++) {
        if (results[i] == '0') {
            results[i] = '1';
        } else {
            results[i] = '0';
        }
    }
    if (n == 8) {
        results[n - 1] = '1';
    }
    for (int i = 0; i < n; i++) {
        printf("%c", results[i]);
    }
    printf("\n");
}

void changebyte(unsigned int byte, unsigned int new_byte) {
    int byte_index = 3;
    unsigned int mask = ~(0xFF << (byte_index * 8));

    byte &= mask;
    byte |= (new_byte << (byte_index * 8));
    
    printf("Результирующее число: 0x%X\n", byte);
}

int main() {
    
    int task = 0;
    printf("Введите номер задания: ");
    scanf("%d", &task);
    int count = 0;

    switch(task) {
        case 1: {
            unsigned int a = 0;
            printf("Введите положительное число: ");
            scanf("%d", &a);
            
            binary(a, count);
            break;
        }
        case 2: {
            int b = 0;

            printf("Введите отрицательное число: ");
            scanf("%d", &b);
            if (b > 0) {
                printf("Число больше 0");
                return 1;
            }
            negative_binary(b);
            break;
        }
        case 3: {
            unsigned int c = 0;
            printf("Введите положительное число: ");
            scanf("%d", &c);
            count = 3;
            binary(c, count);
            break;
        }
        case 4: {
            unsigned int byte = 0;
            unsigned int new_byte = 0;

            printf("Введите положительное число: ");
            scanf("%d", &byte);
            printf("Введите число для замены байта: ");
            scanf("%d", &new_byte);
            
            changebyte(byte, new_byte);
            break;
        }
    }
    
    return 0;
}