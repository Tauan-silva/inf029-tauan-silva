    #include <stdio.h>
    #include <stdlib.h>

    #include "EstruturaVetores.h"

    void show_log(char *str);

    void testeInserirSemNada();
    void testeCriarEstrutura();
    void testeInserirComEstrutura();
    void testeExcluir();
    void testeExcluirNumeroEspecifico();
    void testeListar();
    void testeRetornarTodosNumeros();
    void testeMudarTamanhoEstrutura();
    void testeListaEncadeada();

    int main()
    {
        inicializar();
        testeInserirSemNada();
        testeCriarEstrutura();
        testeInserirComEstrutura();
        testeExcluir();
        testeExcluirNumeroEspecifico();
        testeListar();
        testeRetornarTodosNumeros();
        testeMudarTamanhoEstrutura();
        testeListaEncadeada();
        finalizar();
    }
    int ligado = 0;
    void show_log(char *str)
    {
        if (ligado)
            printf("###%s###\n", str);
    }

    void testeInserirSemNada()
    {
        show_log("testeInserirSemNada()");
        printf("%d\n", inserirNumeroEmEstrutura(2, 2) == WITHOUT_AUXILIARY_STRUCTURE);
        printf("%d\n", inserirNumeroEmEstrutura(-2, 2) == INVALIDATE_POSITION);
        printf("%d\n", inserirNumeroEmEstrutura(0, 2) == INVALIDATE_POSITION);
        printf("%d\n", inserirNumeroEmEstrutura(11, 2) == INVALIDATE_POSITION);
    }

    void testeCriarEstrutura()
    {
        show_log("testeCriarEstrutura()");
        printf("%d\n", criarEstruturaAuxiliar(-2, 5) == INVALIDATE_POSITION);
        printf("%d\n", criarEstruturaAuxiliar(0, 5) == INVALIDATE_POSITION);
        printf("%d\n", criarEstruturaAuxiliar(11, 5) == INVALIDATE_POSITION);
        printf("%d\n", criarEstruturaAuxiliar(2, -5) == INVALIDATE_SIZE);
        printf("%d\n", criarEstruturaAuxiliar(2, 0) == INVALIDATE_SIZE);
        printf("%d\n", criarEstruturaAuxiliar(2, 3) == SUCESS);
        printf("%d\n", criarEstruturaAuxiliar(2, 6) == EXISTING_AUXILIARY_STRUCTURE);
    }
    /*
    2 [ , , ]
    */

    void testeInserirComEstrutura()
    {
        show_log("testeInserirComEstrutura()");
        //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
        printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 5) == NO_SPACE);
    }
    /*
    2 [4,-2,6]
    */
    void testeExcluir()
    {
        show_log("testeExcluir()");
        //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESS);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESS);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(0) == INVALIDATE_POSITION);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(1) == WITHOUT_AUXILIARY_STRUCTURE);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESS);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == VOID_AUX_STRUCTURE);
    }

    /*
    2 [ , , ]
    */

    void testeExcluirNumeroEspecifico()
    {
        show_log("testeExcluirNumeroEspecifico()");
        //###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
        printf("%d\n", criarEstruturaAuxiliar(9, 3) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(9, 7) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(9, 4) == SUCESS);
        printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 12) == ABSENT_NUMBER);
        printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 7) == SUCESS);
        printf("%d\n", excluirNumeroEspecificoDeEstrutura(1, 2) == WITHOUT_AUXILIARY_STRUCTURE);
    }
    /*
    9 [ 4, , ] 
    */

    void testeListar()
    {
        show_log("testeListar()");
        //###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
        printf("%d\n", inserirNumeroEmEstrutura(2, 7) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, -9) == SUCESS);

        int vet[2];

        printf("%d\n", getDadosEstruturaAuxiliar(1, vet) == WITHOUT_AUXILIARY_STRUCTURE);
        printf("%d\n", getDadosEstruturaAuxiliar(11, vet) == INVALIDATE_POSITION);
        printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESS);

        printf("%d\n", vet[0] == 7);
        printf("%d\n", vet[1] == -9);

        printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(1, vet) == WITHOUT_AUXILIARY_STRUCTURE);
        printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(11, vet) == INVALIDATE_POSITION);
        printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESS);

        printf("%d\n", vet[0] == -9);
        printf("%d\n", vet[1] == 7);

        printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESS);

        printf("%d\n", vet[0] == 7);
        printf("%d\n", vet[1] == -9);

        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESS);
        printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESS);
    }

    /*
    2 [ , , ]
    */

    void testeRetornarTodosNumeros()
    {
        show_log("testeRetornarTodosNumeros()");
        int vet1[2];
        printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet1) == VOID_ALL_AUX_STRUCTURES);

        printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == VOID_ALL_AUX_STRUCTURES);

        printf("%d\n", inserirNumeroEmEstrutura(2, 3) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 8) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 0) == SUCESS);
        /*
    2 [3,8,0]
    */

        printf("%d\n", criarEstruturaAuxiliar(5, 10) == SUCESS);

        printf("%d\n", inserirNumeroEmEstrutura(5, 1) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(5, 34) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(5, 12) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(5, 6) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(5, 27) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(5, -6) == SUCESS);
        /*
    2 [3,8,0]
    5 [1,34,12,6,27,-6, , , , ]
    */
        int vet[9];

        printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESS);

        printf("%d\n", vet[0] == 3);
        printf("%d\n", vet[1] == 8);
        printf("%d\n", vet[2] == 0);
        printf("%d\n", vet[3] == 1);
        printf("%d\n", vet[4] == 34);
        printf("%d\n", vet[5] == 12);
        printf("%d\n", vet[6] == 6);
        printf("%d\n", vet[7] == 27);
        printf("%d\n", vet[8] == -6);

        int vet2[9];

        printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESS);

        printf("%d\n", vet2[0] == -6);
        printf("%d\n", vet2[1] == 0);
        printf("%d\n", vet2[2] == 1);
        printf("%d\n", vet2[3] == 3);
        printf("%d\n", vet2[4] == 6);
        printf("%d\n", vet2[5] == 8);
        printf("%d\n", vet2[6] == 12);
        printf("%d\n", vet2[7] == 27);
        printf("%d\n", vet2[8] == 34);

        printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESS);

        printf("%d\n", vet[0] == 3);
        printf("%d\n", vet[1] == 8);
        printf("%d\n", vet[2] == 0);
        printf("%d\n", vet[3] == 1);
        printf("%d\n", vet[4] == 34);
        printf("%d\n", vet[5] == 12);
        printf("%d\n", vet[6] == 6);
        printf("%d\n", vet[7] == 27);
        printf("%d\n", vet[8] == -6);
    }
    /*
    2 [3,8,0]
    5 [1,34,12,6,27,-6, , , , ]
    */

    /*
    int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
    Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
    Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
    Rertono (int)
        SUCESS - foi modificado corretamente o tamanho da estrutura auxiliar
        WITHOUT_AUXILIARY_STRUCTURE - Não tem estrutura auxiliar
        INVALIDATE_POSITION - Posição inválida para estrutura auxiliar
        NEW_INVALIDATE_SIZE - novo tamanho não pode ser negativo
        NO_MEMORY_SPACE - erro na alocação do novo valor
    */
    void testeMudarTamanhoEstrutura()
    {
        show_log("testeMudarTamanhoEstrutura()");
        int vet[1];
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -3) == NEW_INVALIDATE_SIZE);
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -4) == NEW_INVALIDATE_SIZE);
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(11, 7) == INVALIDATE_POSITION);
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(0, 7) == INVALIDATE_POSITION);
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(1, 7) == WITHOUT_AUXILIARY_STRUCTURE);

        //modificar para tamanho de 3 para 1
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -2) == SUCESS);
        printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
        printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESS);
        printf("%d\n", vet[0] == 3);

        //modificar para tamanho de 1 para 4
        printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, 3) == SUCESS);
        printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
        printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESS);
        printf("%d\n", vet[0] == 3);

        printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESS);
        printf("%d\n", inserirNumeroEmEstrutura(2, 5) == NO_SPACE);
    }

    /*
    2 [3,4,-2,6]
    5 [1,34,12,6,27,-6, , , , ]
    */

    void testeListaEncadeada()
    {
        show_log("testeListaEncadeada()");
        int vet[10];
        No *begin = montarListaEncadeadaComCabecote();
        getDadosListaEncadeadaComCabecote(begin, vet);

        printf("%d\n", vet[0] == 3);
        printf("%d\n", vet[1] == 4);
        printf("%d\n", vet[2] == -2);
        printf("%d\n", vet[3] == 6);
        printf("%d\n", vet[4] == 1);
        printf("%d\n", vet[5] == 34);
        printf("%d\n", vet[6] == 12);
        printf("%d\n", vet[7] == 6);
        printf("%d\n", vet[8] == 27);
        printf("%d\n", vet[9] == -6);

        destruirListaEncadeadaComCabecote(&begin);

        printf("%d\n", begin == NULL);
    }
