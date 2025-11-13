#include <stdio.h>
#include <stdlib.h>


int main() {
    int num_count;
    printf("Введите количество: ");
    scanf("%d", &num_count);

    int *arr = (int*)malloc(num_count * sizeof(int));

    printf("Заполнение массива\n");
    
    for (int i = 0; i < num_count; i++) {
        arr[i] = i;
        printf("arr[%d] = %2d | Addr: %p\n", 
               i, arr[i], &arr[i]);
    }
    
    printf("Анализ адресов\n");
    for (int i = 0; i < num_count - 1; i++) {
        long diff = (char*)&arr[i+1] - (char*)&arr[i];
        printf("Расстояние между рядом %d и %d: %ld байтов\n", i, i+1, diff);
    }
    
    free(arr);
    return 0;
}
