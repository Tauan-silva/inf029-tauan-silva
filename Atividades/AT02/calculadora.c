#include <stdio.h>

typedef struct{
    int number1, number2, operation;
} Calculadora;

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
    Calculadora calc;

    do{
        printf("Digite o primeiro valor: ");
        scanf("%d", &calc.number1);
        printf("Digite o segundo valor: ");
        scanf("%d", &calc.number2);
        printf("Escolha uma operacao: \n [1] Soma\n [2] Subtracao\n [3] Multiplicacao\n [4] Divisao\n [0] Sair\n Opcao: ");
        scanf("%d", &calc.operation);

        switch (calc.operation){
        case 0:{
            printf("Saindo..");
            break;
        }
        case 1:{
            printf("Resultado: %d\n", plus(calc.number1, calc.number2));
            break;
        }
        case 2:{
            printf("Resultado: %d\n", minus(calc.number1, calc.number2));
            break;
        }
        case 3:{
            printf("Resultado: %d\n", times(calc.number1, calc.number2));
            break;
        }
        case 4:{
            printf("Resultado: %.2lf\n", divided(calc.number1, calc.number2));
            break;
        }
        default:
            printf("Opcao invalida!");
            calc.operation = 0;
            break;
        }

    } while (calc.operation != 0);
    
    
}
