#include <stdio.h>
#include <stdlib.h>
#include "validate.h"
#include "functions.h"

#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

void menu();

void printLine(char *caracter, int multiplier){
    for(int i = 1; i <= multiplier; i++)
        printf("%c", *caracter);
}

void clearScreen(){
    #ifdef OS_Windows
    system("cls");
    #else
    system("clear");
    #endif 
}

void header(char *phrase, char *caracter){
    printLine(caracter, 20);
    printf("%s", phrase);
    printLine(caracter, 20);
    printf("\n\n");
}

void stringToInt(char string[], int numbers[]){
    int index = 0;
    while(string[index] != '\0'){
        numbers[index] = string[index] - '0';
        index++;
    }
}
void registerStudent(){
    char dataString[10];
    int dataInt[10];

    clearScreen();
    people student;
    header(" Cadastro de aluno(a) ", "#");
    printf("Nome: ");
    setbuf(stdin, NULL);
    fgets(student.name, 31, stdin);

    if(!validateName(student)){
        printf("Nome invalido. Tente novamente pressionando qualquer tecla para continuar.");
        getchar();
        menu();
    }

    printf("Matricula: ");
    setbuf(stdin, NULL);
    fgets(student.registration, 13, stdin);

    printf("CPF (xxx.xxx.xxx-xx): ");
    setbuf(stdin, NULL);
    fgets(student.cpf, 15, stdin);
    setbuf(stdin, NULL);

    if(!validateCpf(student)){
        printf("CPF invalido. Tente novamente pressionando qualquer tecla para continuar.");
        getwchar();
        menu();
    }

    printf("Data de nascimento (dd/mm/aaaa): ");
    setbuf(stdin, NULL);
    fgets(dataString, 10, stdin);
    stringToInt(dataString, dataInt);
    
    student.birthDate.day = dataInt[0] * 10 + dataInt[1];
    student.birthDate.mounth = dataInt[3] * 10 + dataInt[4];
    student.birthDate.year = dataInt[6] * 1000 + dataInt[7] * 100 + dataInt[8] * 10 + dataInt[9];

    if(!validateDate(student)){
        printf("Data inválida. Tente novamente pressinando qualquer tecla para continuar.");
        getwchar();
        menu();
    }

}

void registerProfessor(){
    printf("professor");
}

void registerSubject(){
    printf("subject");
}

void showReports(){
    printf("Reports");
}

void menu(){
    int choice;
    clearScreen();
    printLine("*", 20);
    printf(" Projeto escola ");
    printLine("*",20);
    printf("\n\n");
    printf("Escolha uma opcao:\n\n[1] Cadastrar aluno(a)\n[2] Cadastrar professor(a)\n[3] Cadastrar Disciplica\n[4] Relatorios\n[0] Sair\nOpcao: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        registerStudent();
        break;
    case 2:
        registerProfessor();
        break;
    case 3:
        registerSubject();
        break;
    case 4:
        showReports();    
        break;
    case 0:{
        printf("Saindo..");
        exit(0);
         break;
    }
    default:
        printf("Opcao invalida.");
        break;
    }
}