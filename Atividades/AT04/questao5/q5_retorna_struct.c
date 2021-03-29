#include <stdio.h>

void retornaStruct(int num1, int num2, int num3, int num4);

typedef struct {
    int num1, num2, num3, num4;
} Numeros;

int main(){
    int nmr1, nmr2, nmr3, nmr4;
    Numeros nmrs;

    printf("Informe 4 valores: ");
    scanf("%d%d%d%d", &nmr1, &nmr2, &nmr3, &nmr4);

    retornaStruct(nmr1, nmr2, nmr3, nmr4);

    return 1;
}

void retornaStruct(int n1, int n2, int n3, int n4){
    Numeros numeros;

    numeros.num1 = n1;
    numeros.num2 = n2;
    numeros.num3 = n3;
    numeros.num4 = n4;
    printf("%d, ", numeros.num1);
    printf("%d, ", numeros.num2);
    printf("%d, ", numeros.num3);
    printf("%d", numeros.num4);
    
}