#include <stdio.h>

int fatorial(int number);

int main(){
    int number, result;

    printf("informe um numero: ");
    scanf("%d", &number);

    if(number < 0){
        printf("so e possivel calcular fatorial de numeros naturais.");
    }else{
        result = fatorial(number);
        printf("O fatorial de %d eh %d.", number, result);
    }

    return 1;
}

int fatorial(int number){
  
    if(number == 0){
        return 1;
    }else if(number == 1){
        return 1;
    }else{
        return number * fatorial(number-1);
    }
}