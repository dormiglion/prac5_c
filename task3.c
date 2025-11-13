#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_stats(int arr[], int size, int *min, int *max, double *average) {
    if (size <= 0) {
        *min = *max = 0;
        *average = 0;
        return;
    }
    
    *min = arr[0];
    *max = arr[0];
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
        sum += arr[i];
    }
    
    *average = (double)sum / size;
}

int main() {
    int num_count;
    
    printf("Введите количество элементов: ");
    scanf("%d", &num_count);
    
    if (num_count <= 0) {
        printf("Ошибка: количество элементов должно быть положительным!\n");
        return 1;
    }
    
    int *arr = (int*)malloc(num_count * sizeof(int));
    
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    printf("\nЗаполнение массива\n");
    for (int i = 0; i < num_count; i++) {
        arr[i] = rand() % 100;  // случайные числа от 0 до 99
        printf("arr[%d] = %2d | Addr: %p\n", i, arr[i], &arr[i]);
    }
    
    int min, max;
    double avg;
    get_stats(arr, num_count, &min, &max, &avg);
    
    printf("\n--- Статистика ---\n");
    printf("Минимум: %d\n", min);
    printf("Максимум: %d\n", max);
    printf("Среднее: %.2f\n", avg);
    
    free(arr);
    return 0;
}
