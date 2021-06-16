#include <stdio.h>
#include <stdlib.h>

int tretanacci(int value){
    if (value == 0 || value == 1 || value == 2)
        return 0;
    if (value == 3 || value == 4)
        return 1;
    
    return tretanacci(value -1) + tretanacci(value - 2) + tretanacci(value - 3) + tretanacci(value - 4);
}

int main(){
    printf("%d", tretanacci(6));
    return 0;
}