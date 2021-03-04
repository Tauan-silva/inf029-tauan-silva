#include <stdio.h>


int plus(int number1, int number2){
    int result;
    result = number1 + number2;
    return result;
}

int minus(int number1, int number2){
    int result;
    result = number1 - number2;
    return result;
}

int times(int number1, int number2){
    int result;
    result = number1 * number2;
    return result;
}

double divided(int number1, int number2){
    double result;
    if(number2 == 0) printf("Não é possível fazer uma divisão pelo número 0.");
    else result = number1 / number2;
    
    return result;
    

}

int main(){
    int number1, number2, operation;

    do{
        printf("Digite o primeiro valor: ");
        scanf("%d", &number1);
        printf("Digite o segundo valor: ");
        scanf("%d", &number2);
        printf("Escolha uma operação: \n [1] Soma\n [2] Subtração\n [3] Multiplicação\n [4] Divisão\n [0] Sair\n Opção: ");
        scanf("%d", &operation);

        switch (operation){
        case 0:{
            printf("Saindo..");
            break;
        }
        case 1:{
            printf("Resultado: %d\n", plus(number1, number2));
            break;
        }
        case 2:{
            printf("Resultado: %d\n", minus(number1, number2));
            break;
        }
        case 3:{
            printf("Resultado: %d\n", times(number1, number2));
            break;
        }
        case 4:{
            printf("Resultado: %.2lf\n", divided(number1, number2));
            break;
        }
        default:
            printf("Opção inválida!");
            break;
        }

    } while (operation != 0);
    
    
}
