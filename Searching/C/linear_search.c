#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXDIM 100

//these functions works with primitive types only (otherwise, a comparison function must be defined)

//prototypes
bool linearSearchIterative(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) );
bool linearSearchRecursive(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) );

//comparison functions
int compareChars(char *a, char *b);
int compareIntegers(long *a, long *b); 

int main(void)
{
    char letters[MAXDIM] = {'a', 'b', 'c', 'd', 'e'};
    char element = 'k';
    printf("%d\n", linearSearchIterative(letters, MAXDIM, sizeof(char), &element, compareChars));
    
    element = 'e';
    printf("%d\n", linearSearchRecursive(letters, MAXDIM, sizeof(char), &element, compareChars));
}

bool linearSearchIterative(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) ) {
    
    if(array == NULL || key == NULL)
        return false;
    
    for(int i = 0; i < dimension; i++) {
        void *element = array + i*elementSize;
        
        if(cmp(key, element) == 0)
            return true;
    }
    return false;
}

bool linearSearchRecursive(void *array, uint dimension, size_t elementSize, void *key, int (*cmp)(void *a, void *b) ) {
    
    if(array == NULL || key == NULL)
        return false;
    else if(dimension == 0)
        return false;
    else if(cmp(array + (dimension-1)*elementSize, key) == 0)
        return true;
    else return linearSearchRecursive(array, dimension-1, elementSize, key, cmp);
}

int compareChars(char *a, char *b) {
    //int res = a - b; return res;
    return *a > *b ? 1 : (*a < *b ? -1 : 0);
}