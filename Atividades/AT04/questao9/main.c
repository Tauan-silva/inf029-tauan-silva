#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

#include <stdio.h>
#include "q9_cadastro_melhorado.h"

int main() {
    Cliente cliente;
    cadastrarCliente(cliente);
    return 0;
}