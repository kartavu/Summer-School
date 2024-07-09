#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define SIZE_BUFFER 10

struct abonent {
   char name[SIZE_BUFFER];
   char second_name[SIZE_BUFFER];
   char tel[SIZE_BUFFER];
};

void replace_enter(char *str) {
    int i = 0;
    while('\0' != str[i]) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}
int add_abonent(struct abonent *data, int *count, int *found_abonent) {
    if ((*count) >= N) {
        printf("Список абонентов полностью заполнен\n");
        return -1;
    }
    int i;
    for (i = 0; i < N; i++) {
        if (found_abonent[i] == 0) {
            found_abonent[i] = 1;
            (*count)++;
            break;
        }
    }
    printf("Введите имя пользователя: ");
    fgets(data[i].name, SIZE_BUFFER, stdin);
    replace_enter(data[i].name);

    printf("Введите фамилию пользователя: ");
    fgets(data[i].second_name, SIZE_BUFFER, stdin);
    replace_enter(data[i].second_name);

    printf("Введите номер телефона: ");
    fgets(data[i].tel, SIZE_BUFFER, stdin);
    replace_enter(data[i].tel);

    return 0;
}

int delete_abonent(struct abonent *data, int *count, int *found_abonent) {
    if ((*count) == 0) {
        printf("Список абонентов пустой\n");
        return -1;
    }
    char buffer[SIZE_BUFFER];
    printf("Введите номер для удаления: ");
    fgets(buffer, SIZE_BUFFER, stdin);
    replace_enter(buffer);

    int i;
    for (i = 0; i < N; i++) {
        if (found_abonent[i] == 1 && strcmp(data[i].tel, buffer) == 0) {
            printf("Удаление абонента: %s %s %s\n", data[i].name, data[i].second_name, data[i].tel);
            found_abonent[i] = 0;
            (*count)--;
            memset(&data[i], 0, SIZE_BUFFER);
            return 0;
        }
    }
    printf("Абонент не найден\n");
    return -1;
}

int print(struct abonent *data, int *count, int *found_abonent) {
    if ((*count) == 0) {
        printf("Список абонентов пустой\n");
        return -1;
    }

    int i;
    for (i = 0; i < N; i++) {
        if (found_abonent[i] == 1) {
            printf("%s %s %s\n", data[i].name, data[i].second_name, data[i].tel);
        }
    }
    printf("\n");
    return 0;
}

int search_abonent(struct abonent *data, int *count, int *found_abonent) {
    if ((*count) == 0) {
        printf("Список абонентов пустой\n");
        return -1;
    }
    char buffer[SIZE_BUFFER];
    printf("Введите имя для поиска: ");
    fgets(buffer, SIZE_BUFFER, stdin);
    replace_enter(buffer);

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (found_abonent[i] == 1 && strcmp(data[i].name, buffer) == 0) {
            printf("Найденные пользователи: %s %s %s\n", data[i].name, data[i].second_name, data[i].tel);
            found = 1;
        }
    }
    if (!found) {
        printf("Абонент не найден\n");
    }
    return 0;
}

int main() {
    int menu = 0;
    
    struct abonent data[N];
    int found_abonent[N];
    int count = 0;

    for (int i = 0; i < N; i++) {
        found_abonent[i] = 0;
    }

    while (menu != 5) {
        printf("Выберите действие:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        
        scanf("%d", &menu);
        getchar();

        switch (menu) {
            case 1:
                add_abonent(data, &count, found_abonent);
                break;
            case 2:
                delete_abonent(data, &count, found_abonent);
                break;
            case 3:
                search_abonent(data, &count, found_abonent);
                break;
            case 4:
                print(data, &count, found_abonent);
                break;
            case 5:
                break;
            default:
                printf("Введено неверное действие\n");
                break;
        }
    }
    return 0;
}
