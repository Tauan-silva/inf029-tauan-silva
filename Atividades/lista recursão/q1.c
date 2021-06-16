#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
    if (number == 0)
        return 1;
    else if (number < 0){
        printf("Enable to calculate negative number factorial");
        exit(0);
    }
    
    return number * factorial(number -1);
}

int main (){
    int number = 10;
    printf("%d", factorial(number));
    return 0;
}