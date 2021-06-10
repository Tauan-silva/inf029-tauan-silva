#include <stdio.h>
#include "entities.h"
#include "functions.h"

#define MAX_DAY_FEBRUARY 29

int validateCpf(people person){
    int index = 0;
    int operation1 = 0;
    int operation2 = 0;
    int weight2 = 0;
    int weight1 = 1;
    int checker1, checker2;
    int numCpf[15];

    while(person.cpf[index] != '\0'){
            numCpf[index] = person.cpf[index] - '0';
            index++;
    }

    for(int index = 0; index < 11; index++){
        if(numCpf[index] >= 0){
            operation1 += numCpf[index] * weight1;
            weight1++;
        }
    }

    checker1 = operation1 % 11 == 10 ? 0 : operation1 % 11;
    operation2 = checker1 * 9;
    
    for(int index = 0; index < 11; index++){
        if(numCpf[index] >= 0){
            operation2 += numCpf[index] * weight2;
            weight2++;
        }
    }

    checker2 = operation2 % 11 == 10 ? 0 : operation2 % 11;
	
    if((checker1 == numCpf[12]) && (checker2 == numCpf[13])) return 1;
    else return 0;
}

int validateGender(people person){
    if(
        ((person.gender != 'F') || (person.gender != 'f')) && 
        ((person.gender != 'M') || (person.gender != 'm')) && 
        ((person.gender != 'O') || (person.gender != '0'))
    ) 
        return 0;
    else 
        return 1;
}

int validateName(people person){
    int isNegative = 0;
    int count = 0;
    int nameInt[147]; 

    /*O tamanho do vetor foi definido levando em conta o maior nome registrado no Brasil
    segundo este site https://www.origemdosobrenome.com.br/os-maiores-nomes-e-sobrenomes-do-brasil/
    */

   //Calcula o tamanho da string e popula o vetor com valores dos caracteres em inteiros
    while(person.name[count] != '\0'){ 
        nameInt[count] = person.name[count] - '0';
        count++;
    }

    //Se o vetor estiver algum numero negativo, ou numeros menores iguais a 9, significa que foi digitado caracteres diferentes de letras.
    for(int index = 0; index <= count; index++){
        if((nameInt[index] < 0) || (nameInt[index] <= 9)){
            isNegative = 1;
            break;
        }
    }

    if(isNegative || (count > 147)) return 1;
    else return 0;
}

int validateDate(people person){
    if(person.birthDate.year % 4 == 0){
        if(person.birthDate.mounth == 2){
            if(person.birthDate.day > MAX_DAY_FEBRUARY){
                return 1;
            }else return 0;
        }
    }else if (person.birthDate.day > 31)
        return 1;
        else if (person.birthDate.mounth > 12)
            return 1;
        else return 0;

}