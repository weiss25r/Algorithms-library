#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int pivotIndex, int lastIndex) {
    int pivot = array[pivotIndex];
    int inf = pivotIndex, sup = lastIndex+1;

    while (1)
    {
        do inf++; while(inf <= lastIndex && array[inf] <= pivot);
        do sup--; while(array[sup] > pivot);

        if(inf <= sup) swap(&array[inf], &array[sup]);
        else break;
    }

    swap(&array[pivotIndex], &array[sup]);
    return sup;
}

void quicksort(int *array, int pivotIndex, int lastIndex) {
    if(pivotIndex < lastIndex) {
        int m = partition(array, pivotIndex, lastIndex);
        quicksort(array, pivotIndex, m-1);
        quicksort(array, m+1, lastIndex);
    }
}

void printArray(int *array, int n) {
    for (size_t i = 0; i < n; i++)
        printf("%d\t", array[i]);
    
    puts("");
}

int isSorted(int *array, int dim) {
    int sorted = 1;

    for (size_t i = 0; i < dim - 1; i++)
        sorted &= (array[i] <= array[i+1]);
    
    return sorted;
}

int main(void) {
    srand(time(NULL));

    int *array = (int *)malloc(N * sizeof(int));

    for (size_t i = 0; i < N; i++)
        array[i] = rand()%N + 1;
        
    /*
    puts("Unsorted array: ");
    printArray(array, N);
    puts("\n-------------------\n");
    puts("Sorted array: ");
    */
    quicksort(array, 0, N-1);
    //printArray(array, N);

    printf("Sorted: %d\n", isSorted(array, N));
    free(array);
}

