#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>

void linhas(char *caractere , int quantidade); //desenha linha na tela com caractere informado.
void limpaTela();   //limpa a tela de acordo com o OS da maquina.
void cadastrarCliente();

typedef struct{
        char nome[21];
        char cpf[15];
        char sexo[1];
        char nascimento[11];
} Cliente;

int main(){
    Cliente aluno;
    cadastrarCliente(&aluno);
    printf("Nome : %s\n", aluno.nome);
    printf("CPF: %s\n", aluno.cpf);
    printf("Nascimento: %s\n", aluno.nascimento);
    printf("Sexo: %s", aluno.sexo);

    return 0;
}

void limpaTela(){
    #ifdef OS_Windows
    system("cls");
    #else
    system("clear");
    #endif 
}
void linhas(char *caractere, int quantidade){
    int i = 0;
    for(i; i < quantidade; i++){
         printf("%c", *caractere);
    }
}

void cadastrarCliente(Cliente *cliente){
    linhas("*", 20);
    printf("Cadastro cliente");
    linhas("*", 20);
    printf("\n\n");

    printf("Nome: ");
    scanf("%s", cliente -> nome);
    getwchar();

    printf("CPF: ");
    scanf("%s", cliente -> cpf);
    getwchar();

    printf("Data de nascimento: ");
    scanf("%s", cliente -> nascimento);
    getwchar();

    printf("Sexo [M] [F] : ");
    scanf("%s", cliente -> sexo);
    getwchar();
    limpaTela();
    
    linhas("*", 20);
    printf("cliente cadastrado com sucesso!");
    system("pause");
    limpaTela();
}