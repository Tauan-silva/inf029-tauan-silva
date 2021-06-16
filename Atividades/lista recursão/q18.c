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

int superFactorial(int number){

    if (number == 1)
        return number;

    return factorial(number) * superFactorial(number - 1);
}

int main(){
    printf("%d", superFactorial(4));
    return 0;
}