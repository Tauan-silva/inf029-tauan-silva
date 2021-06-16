#include <stdio.h>
#include <stdlib.h>

 int printEven(int n){
    if (n % 2 != 0){
        printf("The number should be even");
        exit(0);
    }
    if (n == 0)
        return n;
   return printf("%d ", printEven(n - 2));
}
int main(){
    printf("%d", printEven(8));
    return 0;
}