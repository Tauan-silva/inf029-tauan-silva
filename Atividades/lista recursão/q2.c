#include <stdio.h>
#include <stdlib.h>

int fibonacci(int number){
    if (number == 0)
        return number;
    else if (number == 1)
        return number;
    else if (number < 0){
        printf("Enable to calculate with negative number");
        exit(0);
    }
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main(){
    printf("%d", fibonacci(11));
    return 0;
}