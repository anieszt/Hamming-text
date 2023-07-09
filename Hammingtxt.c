#include <stdio.h>
#include "hammingtxt.h"

int main(){

    char *input_data = (char *)malloc(sizeof(char)*9);
    strcpy(input_data, "12345");
    printf("%s",txt_to_bin(input_data));



    free(input_data);
    
    return 0;
}
