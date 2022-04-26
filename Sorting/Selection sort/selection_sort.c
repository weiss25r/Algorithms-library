#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//selection sorts an array of n elements
void selectionSort(int *array, int n) {
    for(int i = 0; i < n; i++) {
        int min = i;

        for(int j = i+1; j < n; j++) {
            if(array[j] < array[min])
                min = j;
        }

        if(min != i)
            swap(&array[i], &array[min]);
    }
}

void printArray(int *array, int n) {
    for (size_t i = 0; i < n; i++)
        printf("%d\t", array[i]);
    
    puts("");
}

int main(void) {
    int test[] = {5, 4, 3, 2, 1};
    
    puts("Unsorted array: ");
    printArray(test, 5);

    selectionSort(test, 5);

    puts("Sorted array");
    printArray(test, 5);
}
