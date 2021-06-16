#include <stdio.h>
#include <stdlib.h>

int recursivePlus(int n){
    if (n == 1)
        return n;
    return n + recursivePlus(n -1);
}
int main(){

    printf("%d", recursivePlus(5));
    
    return 0;
}