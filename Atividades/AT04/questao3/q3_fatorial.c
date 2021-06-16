#include <stdio.h>

int factorial(int number);

int main(){
    int number, result;

    printf("informe um numero: ");
    scanf("%d", &number);

    if(number < 0){
        printf("so e possivel calcular fatorial de numeros naturais.");
    }else{
        result = factorial(number);
        printf("O fatorial de %d eh %d.", number, result);
    }

    return 1;
}

int factorial(int number){
  
    if(number == 0){
        return 1;
    }else if(number == 1){
        return 1;
    }else{
        return number * factorial(number-1);
    }
}