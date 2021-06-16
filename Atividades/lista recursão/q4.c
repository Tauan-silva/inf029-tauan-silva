#include <stdio.h>
#include <stdlib.h>

int plusVector(int vector[], int size){
    if (size == 0)
        return size;
    return vector[size - 1] + plusVector(vector, size -1);
}
int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d", plusVector(vetor, 8));

    return 0;
}