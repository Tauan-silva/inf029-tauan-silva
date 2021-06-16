#include <stdio.h>
#include <stdlib.h>

int doubleFactorial(int number){
    if (number == 1)
        return number;
    if (number % 2 != 0)
        return number * doubleFactorial(number -1);
    
    return doubleFactorial(number -1);
}

int main(){
    printf("%d", doubleFactorial(7));
    return 0;
}