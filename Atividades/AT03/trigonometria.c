#include <stdio.h>

int isTriagle(float side1, float side2, float side3){
    if((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) return 1;
    else return 0;
}
