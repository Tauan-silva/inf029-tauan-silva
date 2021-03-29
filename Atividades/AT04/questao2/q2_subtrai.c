#include <stdio.h>

int minus(int number1, int number2, int number3);

int main(){
    int number1, number2, number3, result;

    printf("Informe o primeiro valor: ");
    scanf("%d", &number1);
    
    printf("informe o segundo valor: ");
    scanf("%d", &number2);

    printf("Informe o terceiro valor: ");
    scanf("%d", &number3);

    result = minus(number1, number2, number3);

    printf("A subtracao de %d e %d e %d eh: %d", number1, number2, number3, result);

    return 1;
}

int minus(int number1, int number2, int number3){
    return number1 - number2 - number3;
}