#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
        char nome[50];
        char cpf[15];
        char sexo;
        Data nascimento;
} Cliente;

void limpaTela(){
    #ifdef OS_Windows
    system("cls");
    #else
    system("clear");
    #endif 
}

void linhas(char *caractere, int quantidade){
    int i = 0;
    for(i; i < quantidade; i++) printf("%c", *caractere); 
}

int validarNome(Cliente cliente){
    int contador = 0;
    while(cliente.nome[contador] != '\0') contador++;
    return contador;
}

int validarCpf(Cliente cliente){
    int index = 0;
    int soma1 = 0;
    int soma2 = 0;
    int peso2 = 0;
    int peso1 = 1;
    int verificador1, verificador2;
    int numCpf[15];

    while(cliente.cpf[index] != '\0'){
            numCpf[index] = cliente.cpf[index] - '0';
            index++;
    }

    for(int index = 0; index < 12; index++){
        if(numCpf[index] >= 0){
            soma1 += numCpf[index] * peso1;
            peso1++;
        }
    }

    verificador1 = soma1 % 11 == 10 ? 0 : soma1 % 11;
    soma2 = verificador1 * 9;
    
    for(int index = 0; index < 12; index++){
        if(numCpf[index] >= 0){
            soma2 += numCpf[index] * peso2;
            peso2++;
        }
    }

    verificador2 = soma2 % 11 == 10 ? 0 : soma2 % 11;

    if((verificador1 == numCpf[12]) && (verificador2 == numCpf[13])) return 1;
    else return 0;
}

int validarNascimento(Cliente cliente, char *dataString){
    int dataInt[11];
    int index = 0;

    //convertendo caracteres em inteiros
    while(dataString[index] != '\0'){
        if((dataString[index] - '0') >= 0){
            dataInt[index] = dataString[index] - '0';
            index++;
        }else if((dataString[index] - '0' < 0) || index > 9){
            dataInt[index] = -1;
            index++;
        }
    }
    //Aqui esperar-se que as posições 2 e 5 do vetor de inteiros, sejam numeros menores que 0
    //o que resultariam em caracteres diferentes de numeros.

    if((dataInt[2] >= 0) || (dataInt[5] >= 0))
        return 0; //sendo invalido retorna 0
    else{
        cliente.nascimento.dia = dataInt[0] * 10 + dataInt[1];
        cliente.nascimento.mes = dataInt[3] * 10 + dataInt[4];
        cliente.nascimento.ano = (dataInt[6] * 1000) + (dataInt[7] * 100) + (dataInt[8] * 10 + dataInt[9]);

        if((cliente.nascimento.dia > 31) || (cliente.nascimento.mes > 12) || (cliente.nascimento.ano > 2021))
            return 0; //sendo invalido retorna 0
        else return 1; //
    }
    

}
void cadastrarCliente(Cliente cliente){
    char *data[11];

    linhas("*", 20);
    printf("Cadastro cliente");
    linhas("*", 20);
    printf("\n\n");

    printf("Nome: ");
    fgets(cliente.nome, 50, stdin);
    if(validarNome(cliente) > 20){
        printf("O nome deve conter ate 20 caracteres. Por favor reinicie seu programa.");
        exit(0);
    
    printf("CPF: ");
    scanf("%s", cliente.cpf);
    if(!validarCpf(cliente)){
        printf("CPF invalido. Por favor verifique seus dados e reinicie seu programa.");
        exit(0);
        
    getwchar();

    printf("Data de nascimento (dd/mm/aaaa): ");
    fgets(*data, 11, stdin);
    setbuf(stdin, NULL);
    if(!validarNascimento){
        printf("Data de nascimento inválida.  Por favor verifique sua digitação e reinicie seu programa.");
        exit(0);
    }

            /*
    printf("Sexo [M] [F] : ");
    scanf("%s", cliente.sexo);
    getwchar();

    linhas("*", 20);
    limpaTela();
    printf("cliente cadastrado com sucesso!");
    system("pause");
    limpaTela();
            */
        }
    }  
}