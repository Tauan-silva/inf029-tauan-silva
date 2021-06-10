#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int vetorPrincipal[TAM];

void duplicate(int *x)
{

    *x = *x * 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESS - criado com sucesso
    EXISTING_AUXILIARY_STRUCTURE - já tem estrutura na posição
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
    NO_MEMORY_SPACE - Sem espaço de memória
    INVALIDATE_SIZE - o tamanho tem inteiro maior ou igual a 1
*/
int setAuxiliaryStructure(int position, int size)
{

    //int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    //retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    //retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    //retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    //retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    //retorno = SUCESSO;

    //return retorno;

    int functionReturn = 0;
	int response, valid;
  

  valid = position;
  
  response = validPosition(valid);
	if (response == -1){
		position--;

		if (size >= 1){
			if (structure[position].assistant == NULL){
				structure[position].assistant = (int *)malloc(size * sizeof(int));
				structure[position].operator = size;
				functionReturn = SUCESS;
			}else{
				functionReturn = EXISTING_AUXILIARY_STRUCTURE;
			}	
		}else{
			functionReturn = INVALIDATE_SIZE;
		}	
	}else{
		functionReturn = INVALIDATE_POSITION;
	}
    return functionReturn;
}


/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESS - inserido com sucesso
    NO_SPACE - não tem espaço
    WHITOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int insertnumberInStructure(int position, int value)
{

  int functionReturn = 0;
  int response, valid;

  valid = position;

  response = validPosition(valid);

	if(response == -1){
		position--;
	
		if(structure[position].assistant != NULL){

			if(structure[position].numbersElements <= structure[position].operator){
				structure[position].assistant[structure[position].numbersElements] = value;
				structure[position].numbersElements++;
				functionReturn = SUCESS;
			}else{
				functionReturn = NO_SPACE;
			}
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}else{
		functionReturn = INVALIDATE_POSITION;
	}
	return functionReturn;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESS - excluido com sucesso
    VOID_AUX_STRUCTURE - estrutura vazia
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
*/
int deleteNumberOfEndStructure(int position)
{
  int functionReturn = 0;
  int response, valid;
  
  valid = position;

  response = validPosition(valid);

	if(response==-1){
		position--;
		
		if(structure[position].assistant!=NULL){

			if(structure[position].numbersElements != 0){
				structure[position].assistant[structure[position]
				.numbersElements] = structure[position].assistant[structure[position].numbersElements+1];
				structure[position].numbersElements--;
				functionReturn = SUCESS;

			}else{
				functionReturn = VOID_AUX_STRUCTURE;
			}
	
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}else{
		functionReturn = INVALIDATE_POSITION;
	}
	
	return functionReturn;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESS - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    VOID_AUX_STRUCTURE - estrutura vazia
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    ABSENT_NUMBER - Número não existe
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
*/
int deleteNumberToStructure(int position, int value)
{
   int a, b, functionReturn = 0;
   int response, valid;

  valid = position;
  response = validPosition(valid);

	if(response == -1){
		position--;

		if(structure[position].assistant!=NULL){
		 if(structure[position].numbersElements!= 0){
			for(a = 0; a < structure[position].numbersElements; a++){
			 	if(structure[position].assistant[a] == value){
					for(b = a; b < structure[position].numbersElements-1; b++){
							structure[position].assistant[b] = structure[position].assistant[b + 1];
						}
						functionReturn = SUCESS;

						structure[position].numbersElements--;
					}
					else{
						functionReturn = ABSENT_NUMBER;
					}
				}
			}
			else{
				functionReturn = VOID_AUX_STRUCTURE;
			}
		}
		else{
				functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}
	else{
		functionReturn = INVALIDATE_POSITION;
	}
	return functionReturn;
}

// se posição é um valor válido {entre 1 e 10}
int validPosition(int position)
{
    int functionReturn = 0;
    if (position < 1 || position > 10)
    {
        functionReturn = INVALIDATE_POSITION;
    }
    else
        functionReturn = SUCESS;

    return functionReturn;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESS - recuperado com sucesso os valores da estrutura na posição 'posicao'
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
*/
int getDataAuxiliaryStructure(int position, int vetorAux[])
{

    int a, functionReturn = 0;
	int response, valid;

  valid = position;

  response = validPosition(valid);

	if(response == -1){
		position--;

		if(structure[position].assistant != NULL){
		 for (a = 0; a < structure[position].numbersElements; a++){
		  vetorAux[a] = structure[position].assistant[a];
		  functionReturn = SUCESS;
			}	
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}else{
		functionReturn = INVALIDATE_POSITION;
	}	

	return functionReturn;
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESS - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
*/
int getOrderDataOfAuxiliaryStructure(int position, int vetorAux[])
{
 int index, b, functionReturn = 0, resultado;
	
	for(index = 0; index < TAM; index++){
	 if(structure[index].assistant != NULL){
	  for(b = 0; b < structure[index].numbersElements; b++){
		vetorAux[b] = structure[index].assistant[b];
		functionReturn = SUCESS;
			}
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}
	return functionReturn;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESS - recuperado com sucesso os valores da estrutura na posição 'posicao'
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
*/

void order(int vetorAux[], int position){
  int response, valid, index, index1, operator;
  
  valid = position;
  response = validPosition(valid);
 
  if (response ==-1){
 
   for(index = 0; index < structure[position].numbersElements; index++){
    for(index1 = index + 1; index1 < structure[position].numbersElements; index1++){
     if(vetorAux[index] > vetorAux[index1]){
          operator = vetorAux[index];
          vetorAux[index] = vetorAux[index1];
          vetorAux[index1] = operator;
        }
      }
	}
  }
}






int getDataOfAllAuxiliaryStructures(int vetorAux[])
{

   int index, b, functionReturn = 0, result;
	
	for(index = 0; index < TAM; index++){
 
	 if(structure[index].assistant != NULL){
	  for(b = 0; b < structure[index].numbersElements; b++){
	   vetorAux[b] = structure[index].assistant[b];
	   functionReturn = SUCESS;
	  }
			for (index = 0; index < TAM; index++){
			order(vetorAux, index);
				}
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}
	return functionReturn;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESS - recuperado com sucesso os valores da estrutura na posição 'posicao'
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
*/
int getOrderDataOfAllAuxiliaryStructures(int vetorAux[])
{
int index, b, functionReturn = 0, result;
	
	for(index = 0; index < TAM; index++){
		if(structure[index].assistant != NULL){
			for(b = 0; b < structure[index].numbersElements; b++){
				vetorAux[b] = structure[index].assistant[b];
				functionReturn = SUCESS;
			}
				for (index = 0; index < TAM; index++){
					order(vetorAux, index);
				}
		}else{
			functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
		}
	}
	return functionReturn;
}
/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESS - foi modificado corretamente o tamanho da estrutura auxiliar
    WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
    INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
    NEW_INVALIDATE_SIZE - novo tamanho não pode ser negativo
    NO_MEMORY_SPACE - erro na alocação do novo valor
*/
int changeSizeAuxiliaryStructure(int position, int newSize)
{

  int functionReturn = 0, size, response, valid;
	
  valid = position;
  response = validPosition(valid);
  
	if(response ==-1){
		position--;
		size = newSize + structure[position].operator;
		if (size >= 1){
			if(structure[position].assistant == NULL){
				functionReturn = WITHOUT_AUXILIARY_STRUCTURE;
			}else{
				structure[position].assistant = (int *)malloc(size * sizeof(int));
				structure[position].operator = size;
				functionReturn = SUCESS;
			}	
		}else{
			functionReturn = INVALIDATE_SIZE;
		}		
	}else{
		functionReturn = INVALIDATE_POSITION;
	}
	return functionReturn;
}
/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    INVALIDATE_POSITION - posição inválida
    WITHOUT_AUXILIARY_STRUCTURE - sem estrutura auxiliar
    VOID_AUX_STRUCTURE - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getCountElementsAuxiliaryStructure(int position)
{

int functionReturn = 0, response, valid;

  valid = position;
  response = validPosition(valid);
	
      if(response ==-1){
		position--;
		if(structure[position].assistant != NULL){
		 if(structure[position].numbersElements > 0){
			return structure[position].numbersElements;
		   	}else{
				functionReturn = VOID_AUX_STRUCTURE;
		 }
	}
	}else{
		functionReturn = INVALIDATE_POSITION;		
	}
	return functionReturn;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *createLinkedListWithHead()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDataLinkedList(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void deleteAllLinkedList(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void initialize()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void ends()
{
}
