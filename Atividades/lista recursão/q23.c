#include <stdio.h>
#include <stdlib.h>

int padovan(int number){
    if (number <= 2)
        return 1;
    
    return padovan(number - 2) + padovan(number - 3);
}


int main(){

    printf("%d", padovan(5));

    return 0;
}