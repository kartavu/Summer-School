#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_MAX 100
int main() {

    int task = 0;
    printf("Введите номер задания: ");
    scanf("%d", &task);

    switch(task) {
        case 1: {
            int n = 0;
            char matrix[N_MAX][N_MAX];
            printf("Введите N:\n");
            if (scanf("%d", &n) != 1 || n < 0 || n > N_MAX) {
                printf("n/a");
                return 1;
            }
            printf("Введите Мaтрицу:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%s", &matrix[i][j]);
                }
            }

            printf("Готовая Матрица:\n");
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    printf("%c ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;
        }

        case  2: {
            char array[N_MAX];
            char new_array[N_MAX];

            int m = 0;

            printf("Введите N:\n");
            if (scanf("%d", &m) != 1 || m < 0 || m > N_MAX) {
                printf("n/a");
                return 1;
            }

            printf("Введите Массив:\n");
            for (int i = 0; i < m; i++) {
                scanf("%s", &array[i]);
            }
            printf("\n");

            for (int i = 0; i < m; i++) {
                for (int j = m - 1; j >= 0; j--){
                    new_array[i++] = array[j];
                }
            }
            printf("Развернутый Массив:\n");
            for (int i = 0; i < m; i++) {
                printf("%c ", new_array[i]);
            }
            printf("\n");
            break;
        }

        case 3: {
            int n = 0;
            char matrix[N_MAX][N_MAX];
            printf("Введите N:\n");
            if (scanf("%d", &n) != 1 || n < 0 || n > N_MAX) {
                printf("n/a");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j< n; j++) {
                    if (i + j >= n - 1) {
                        matrix[i][j] = '1';
                    } else {
                        matrix[i][j] = '0';
                    }
                }
            }
            printf("Готовая Матрица:\n");
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    printf("%c ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;
        }

        case 4: {
            int n = 0; 
            int el = 1;
            int matrix[N_MAX][N_MAX];
            printf("Введите N:\n");
            if (scanf("%d", &n) != 1 || n < 0 || n > N_MAX) {
                printf("n/a");
                return 1;
            }
            int top = 0;
            int edge = n - 1;
            int right = n - 1;
            int left = 0;
            while (el <= pow(n, 2)) {
                for (int i = left; i <= right; i++) {
                    matrix[top][i] = el++;
                } 
                top++;
                for (int i = top; i <= edge; i++) {
                    matrix[i][right] = el++;
                }
                right--;
                for (int i = right; i >= left; i--) {
                    matrix[edge][i] = el++;
                }
                edge--;
                for (int i = edge; i >= top; i--) {
                    matrix[i][left] = el++;
                }
                left++;
            }
            printf("Готовая Матрица:\n");
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;
        }
        default:
            printf("Неверный номер задания.\n");
            break;
    }

    return 0;
}