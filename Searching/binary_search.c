#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXDIM 5

//prototypes
bool binarySearchIterative(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) );
bool binarySearchRecursive(void *array, uint leftIndex, uint rightIndex, size_t elementSize, void *key, int (*cmp)(void *a, void *b) );

int compareChars(char *a, char *b);

int main(void)
{
    //simple test with chars
    char letters[MAXDIM] = {'a', 'b', 'c', 'd', 'e'};
    char element = 'k';

    printf("%d\n", binarySearchRecursive(letters, 0, MAXDIM-1, sizeof(char), &element, compareChars));
    element = 'e';
    printf("%d\n", binarySearchIterative(letters, MAXDIM, sizeof(char), &element, compareChars));
}

bool binarySearchRecursive(void *array, uint leftIndex, uint rightIndex, size_t elementSize, void *key, int (*cmp)(void *a, void *b) ) 
{
    if(array == NULL || key == NULL)
        return false;

    if(rightIndex < leftIndex)
        return false;
    
    int middle = (rightIndex + leftIndex)/2;
    void *element = array + middle*elementSize;
    
    if(cmp(key, element) == 0)
        return true;
    else if(cmp(key, element) > 0)
        return binarySearchRecursive(array, middle+1, rightIndex, elementSize, key, cmp);
    else
        return binarySearchRecursive(array, leftIndex, middle-1, elementSize, key, cmp);
}

bool binarySearchIterative(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) ){
    if(array == NULL || key == NULL)
        return true;
    
    int leftIndex = 0, rightIndex = dimension-1;

    while (leftIndex <= rightIndex)
    {
        int middle = (rightIndex+leftIndex)/2;
        void *element = array + middle*elementSize;
        
        if(cmp(key, element) == 0)
            return true;
        else if(cmp(key, element) > 0)
            leftIndex = middle+1;
        else
            rightIndex = middle-1;
    }

    return false;
}

int compareChars(char *a, char *b) {
    //int res = a - b; return res;
    return *a > *b ? 1 : (*a < *b ? -1 : 0);
}