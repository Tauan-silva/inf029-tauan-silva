#include <stdio.h>

void retornaString(char word1[31], char word2[31], char word3[31]);

int main(){
    char palavra1[31], palavra2[31], palavra3[31];

    printf("informe uma palavra: ");
    gets(palavra1);

    printf("informe outra palavra: ");
    gets(palavra2);

    printf("informe mais uma palavra: ");
    gets(palavra3);

    retornaString(palavra1, palavra2, palavra3);

    return 1;
}

void retornaString(char word1[31], char word2[31], char word3[31]){
    printf("%s.\n", word1);
    printf("%s.\n", word2);
    printf("%s.\n", word3);
}