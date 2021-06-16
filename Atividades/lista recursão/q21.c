#include <stdio.h>
#include <stdlib.h>

int tribonacci(int number){
    if (number == 0 || number == 1)
        return 0;
    if (number == 2)
        return 1;
    
    return tribonacci(number -1) + tribonacci(number - 2) + tribonacci(number - 3);
}

int main(){

    printf("%d", tribonacci(8));

    return 0;

}