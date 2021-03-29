#ifndef Q9_CADASTRO_MELHORADO_H_INCLUDED
#define Q9_CADASTRO_MELHORADO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;
typedef struct {
   char nome[50];
        char cpf[15];
        char sexo;
        Data nascimento;
} Cliente;

int validarNome(Cliente cliente);
int validarCpf(Cliente cliente);
int validarSexo(Cliente cliente);
int validarNascimento(Cliente cliente, char *dataString);
void limpaTela();
void linhas(char *caractere, int quantidade);
void cadastrarCliente(Cliente cliente);

#endif