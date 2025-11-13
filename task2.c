#include <stdio.h>
#include <stdlib.h>


int main() {
    int rows, cols;
    printf("Введите количество рядов, затем столбцов: ");
    scanf("%d %d", &rows, &cols);

    int **arr = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Заполнение массива\n");
    for (int i = 0; i < rows; i++) {
        printf("Row number: %d\n", i);
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
            printf("arr[%d][%d] = %2d | Addr: %p\n", 
                i, j, arr[i][j], &arr[i][j]);
         }
    }
    printf("Анализ адресов\n");
    for (int i = 0; i < rows - 1; i++) {
        long diff = (char*)arr[i+1] - (char*)arr[i];
        printf("Расстояние между рядом %d и %d: %ld байтов\n", i, i+1, diff);
    }

    for (int i = 0; i < rows; i++) {
         free(arr[i]);
    }
    free(arr);
    return 0;
}
