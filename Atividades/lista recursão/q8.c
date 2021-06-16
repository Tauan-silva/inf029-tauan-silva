#include <stdio.h>
#include <stdlib.h>

int doubleFactorial(int x, int y){
    if (x == y)
        return x;
    if (x < y)
        return doubleFactorial(y, x);
    return doubleFactorial(x - y, y);
}

int main(){
    printf("%d", doubleFactorial(2, 8));
    return 0;
}