#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_BUFFER 10

struct Abonent {
    char name[SIZE_BUFFER];
    char second_name[SIZE_BUFFER];
    char tel[SIZE_BUFFER];
};

struct List {
    struct Abonent *abonent;
    struct List *next;
};

void replace_enter(char *str) {
    int i = 0;
    while ('\0' != str[i]) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

struct List *add_element(struct Abonent *abonent) {
    struct List *new_element = (struct List*)malloc(sizeof(struct List));
    new_element->abonent = abonent;
    new_element->next = NULL;
    return new_element;
}

struct List *delete_element(struct List *element) {
    if (element->abonent) {
        free(element->abonent);
    }
    free(element);
    return NULL;
}

struct Abonent *create_abonent() {
    struct Abonent *abonent = (struct Abonent*)malloc(sizeof(struct Abonent));
    return abonent;
}

void print_abonent(struct Abonent *abonent) {
    printf("Найденные пользователи: %s %s %s\n", abonent->name, abonent->second_name, abonent->tel);
}

struct List *delete_list(struct List *head) {
    struct List *ptr = head, *ptr_del;
    while(ptr) {
        ptr_del = ptr;
        ptr = ptr->next;
        delete_element(ptr_del);
    }
    return NULL;
}

struct Abonent *create_abonents() {
    struct Abonent *abonent = create_abonent();

    printf("Введите имя пользователя: ");
    fgets(abonent->name, SIZE_BUFFER, stdin);
    replace_enter(abonent->name);

    printf("Введите фамилию пользователя: ");
    fgets(abonent->second_name, SIZE_BUFFER, stdin);
    replace_enter(abonent->second_name);

    printf("Введите номер телефона: ");
    fgets(abonent->tel, SIZE_BUFFER, stdin);
    replace_enter(abonent->tel);

    return abonent;
}

struct List *add(struct List *end_list) {
    struct Abonent *new_abonent = create_abonents();
    struct List *new_element = add_element(new_abonent);

    end_list->next = new_element;
    return new_element;
}

void print_list(struct List *head) {
    struct List *ptr = head;
    while(ptr) {
        print_abonent(ptr->abonent);
        ptr = ptr->next;
    }
}

int search_list(struct List *head) {
    struct List *ptr = head;
    char buffer[SIZE_BUFFER];

    printf("Введите номер:\n");
    fgets(buffer, SIZE_BUFFER, stdin);
    replace_enter(buffer);

    while(ptr) {
        if (strcmp(ptr->abonent->tel, buffer) == 0) {
            print_abonent(ptr->abonent);
            return 0;
        }
        ptr = ptr->next;
    }
    printf("Абонент не найден\n");
    return -1;
}

int delete_abonent(struct List *head, struct List **end_list) {
    struct List *ptr = head, *ptr_del;
    char buffer[SIZE_BUFFER];

    printf("Введите номер для удаления: ");
    fgets(buffer, SIZE_BUFFER, stdin);
    replace_enter(buffer);

    while(ptr->next) {
        if (strcmp(ptr->next->abonent->tel, buffer) == 0) {
            ptr_del = ptr->next;
            if (ptr_del->next) {
                ptr->next = ptr_del->next;
            } else {
                ptr->next = NULL;
                *end_list = ptr;
            }
            delete_element(ptr_del);
            return 0;
        }
        ptr = ptr->next;
    }
    printf("Абонент не найден\n");
    return -1;
}

int main() {
    int menu = 0;
    int count = 0;

    struct List *head = add_element(NULL);
    struct List *last_element = head;

    while (menu != 5) {
        printf("Выберите действие:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонента по номеру\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");

        scanf("%d", &menu);
        getchar();

        switch (menu) {
            case 1:
                last_element = add(last_element);
                count++;
                break;
            case 2:
                if (count > 0) {
                    delete_abonent(head, &last_element);
                    count--;
                } else {
                    printf("Список пуст\n");
                }
                break;
            case 3:
                if (count > 0) {
                    search_list(head->next);
                } else {
                    printf("Список пуст\n");
                }
                break;
            case 4:
                if (count > 0) {
                    print_list(head->next);
                } else {
                    printf("Список пуст\n");
                }
                break;
            case 5:
                delete_list(head);
                break;
            default:
                printf("Введено неверное действие\n");
                break;
        }
    }
    return 0;
}
