    #ifndef TRABALHO2_ESTRUTURAVETORES_H
    #define TRABALHO2_ESTRUTURAVETORES_H

    // enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
    // as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
    // as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
    // constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
    enum { VOID_ALL_AUX_STRUCTURES = -11, NEW_INVALIDATE_SIZE, ABSENT_NUMBER,
           VOID_AUX_STRUCTURE, INVALIDATE_SIZE, NO_MEMORY_SPACE, INVALIDATE_POSITION,
           EXISTING_AUXILIARY_STRUCTURE, WITHOUT_AUXILIARY_STRUCTURE, NO_SPACE, SUCESS};
   #define TAM 10  

     typedef struct{
         
	int *assistant;
    int numbersElements;
    int operator;	
    }mainStruct;

    mainStruct structure[TAM];
    
     typedef struct reg {
        int content;
        struct reg *prox;
    } No;

    int criarEstruturaAuxiliar(int posicao, int tamanho);
    int inserirNumeroEmEstrutura(int posicao, int valor);
    int excluirNumeroDoFinaldaEstrutura(int posicao);
    int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
    int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
    int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
    int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
    int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
    int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
    int getQuantidadeElementosEstruturaAuxiliar(int posicao);
    No *montarListaEncadeadaComCabecote();
    void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
    void destruirListaEncadeadaComCabecote(No **inicio);

    void inicializar();
    void finalizar();
    void dobrar(int *x);

    #endif  // TRABALHO2_ESTRUTURAVETORES_H
