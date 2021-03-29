#include <stdio.h>

int plus(int number1, int number2);

int main(){
    int number1, number2, result;

    printf("Informe o primeiro valor: ");
    scanf("%d", &number1);
    
    printf("informe o segundo valor: ");
    scanf("%d", &number2);

    result = plus(number1, number2);

    printf("A soma de %d e %d eh: %d", number1, number2, result);

    return 1;
}

int plus(int number1, int number2){
    return number1 + number2;
}