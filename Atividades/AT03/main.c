#include <stdio.h>
#include "trigonometria.h"

int main(){
    float side1, side2, side3;

    printf("Sabia se 3 valores digitados podem formar um triangulo.\n");
    printf("Digite 3 valores reais: ");
    scanf("%f%f%f", &side1, &side2, &side3);

    if(isTriagle(side1, side2, side3)){
        if((side1 == side2) && (side1 == side3)){
            printf("Esses valores podem formar um triangulo equilatero.");
        }else if((side1 == side2) && (side1 != side3) || ((side2 == side3) && (side2 != side1))){
            printf("Esses valores podem formar um triangulo isosceles.");
        }else{
            printf("Esses valores podem formar um triangulo escaleno.");
        }
    }else printf("Esses valores nao podem formar um triangulo.");
}