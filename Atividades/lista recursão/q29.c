#include <stdio.h>
#include <stdlib.h>

int h(int m, int n){

    if (n == 1)
        return m + 1;
    if (m == 1)
        return n + 1;

    return h(m, n -1) + h(m - 1, n);
}

int main(){
    printf("%d", h(6, 4));
    return 0;
}