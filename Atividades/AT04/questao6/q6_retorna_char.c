#include <stdio.h>

void retornaChar(char letter1, char letter2, char letter3);

int main(){
    char letra1, letra2, letra3;

    printf("informe uma letra: ");
    scanf("%c", &letra1);
    getwchar();
    printf("informe outra letra: ");
    scanf("%c", &letra2);
    getwchar();
    printf("informe mais uma letra: ");
    scanf("%c", &letra3);
    getwchar();
    retornaChar(letra1, letra2, letra3);

    return 1;
}

void retornaChar(char letter1, char letter2, char letter3){
    printf("%c.\n", letter1);
    printf("%c.\n", letter2);
    printf("%c.\n", letter3);
}