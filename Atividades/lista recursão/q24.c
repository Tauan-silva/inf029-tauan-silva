#include <stdio.h>
#include <stdlib.h>

int pell(int value){
    if (value == 0)
        return 0;
    if (value == 1)
        return 1;
    
    return 2 * pell(value -1) + pell(value - 2);
}

int main(){
    printf("%d", pell(9));
    return 0;
}