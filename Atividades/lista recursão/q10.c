#include <stdio.h>
#include <stdlib.h>

int countDigit(int numberToObserve, int number){
    if (numberToObserve == 0)
        return numberToObserve;
    return countDigit(numberToObserve / 10, number) + (numberToObserve % 10 == number);
}
int main(){
    printf("%d", countDigit(1213141, 1));
    return 0;
}