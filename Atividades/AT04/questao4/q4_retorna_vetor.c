#include <stdio.h>

void retornaVetor(int num1, int num2, int num3);

int main(){
    int n1, n2, n3;

    printf("digite um valor: ");
    scanf("%d", &n1);
    printf("digite outro valor: ");
    scanf("%d", &n2);
    printf("Digite um ultimo valor: ");
    scanf("%d", &n3);

    printf("Aqui esta seu vetor preenchido.");
    retornaVetor(n1, n2, n3);

    return 1;
}

void retornaVetor(int num1, int num2, int num3){
    int i;
    int vetor[3];
    vetor[0] = num1;
    vetor[1] = num2;
    vetor[2] = num3;

    for(i= 0; i <= 2; i++) printf("%d ", vetor[i]);
}