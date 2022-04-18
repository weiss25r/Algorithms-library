#include <stdio.h>


int exponentiation(int n, int k);

int main(void) {
    printf("%d\n", exponentiation(3, 5));
}

//this function is a C trascription of the recurrence relation
int exponentiation(int n, int k) 
{
    if(k <= 1){
        return n;
    }

    else {
        int d = exponentiation(n, k/2);
        d = d*d;

        if(k%2 != 0)
            d = d*n;
        
        return d;
    }
}