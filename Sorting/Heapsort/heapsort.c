#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 4

void heapify(int *heap, int root);
void fixHeap(int *heap, int root);
void printArray(int *array, int dim);

int main(void) 
{
    int heap[MAXDIM] = {9, 12, 3, 7};
    printArray(heap, MAXDIM);

    heapify(heap, 0);

    printArray(heap, MAXDIM);
}


void heapify(int *heap, int root) 
{
    if(root < MAXDIM) {
        int leftSonIndex = 2*root + 1;
        int rightSonIndex = 2*root + 2;

        if(rightSonIndex < MAXDIM)
            heapify(heap, rightSonIndex);

        if(leftSonIndex < MAXDIM)
            heapify(heap, leftSonIndex);

        fixHeap(heap, root);
    }
}

void fixHeap(int *heap, int root) {
    int leftSonIndex = 2*root + 1;
    int rightSonIndex = 2*root + 2;

    if(rightSonIndex >= MAXDIM && leftSonIndex >= MAXDIM)
        return;
    else {
        
        int max;

        if(rightSonIndex >= MAXDIM)
            max = leftSonIndex;
        else if(leftSonIndex >= MAXDIM)
            max = rightSonIndex;
        else
            max = heap[leftSonIndex] > heap[rightSonIndex] ? leftSonIndex : rightSonIndex;

        if(heap[root] < heap[max]) {
            int tmp = heap[root];
            heap[root] = heap[max];
            heap[max] = tmp;
            fixHeap(heap, max);
        }
    }

}

void printArray(int *array, int dim) {
    puts("------");
    
    for (size_t i = 0; i < dim; i++) 
        printf("%d\t", array[i]);

    puts("\n------");
}