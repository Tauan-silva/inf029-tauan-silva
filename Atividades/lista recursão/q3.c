#include <stdlib.h>
#include <stdio.h>

int sum, rest = 0;

int reverseNumber(int number){
    if (number){
        rest = number % 10;
        sum = sum * 10 + rest;
        reverseNumber(number / 10);
    }else 
        return sum;

    return sum;      
}

int main(){
    printf("%d", reverseNumber(123));
    return 0;
}
