#include <stdio.h>
#include "hammingtxt.h"

int main(){
    
    char a[] = "test";
    char **b =  (char **) malloc(4 * sizeof(char));;
    txt_to_bin(a, b);
    for (size_t i = 0; i <= 4; i++){
        printf("%s\n", b[i]);
    }
    
    return 0;
}