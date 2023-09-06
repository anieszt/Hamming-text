#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *zero_fill(char *bin){

    int binL = strlen(bin);
    if (binL >= 8) return bin;
    strrev(bin);
    for(int i = 8 - binL; i<9; i++){
        strcat(bin, "0");       
    }
    bin[9]='\0';
    return strrev(bin);
}

char *int_to_bin(int L){
    char *bin = (char *) malloc(sizeof(char)*33);
    int i = 0;
    while(L > 0){
        bin[i++] = L%2 + '0';
        L /= 2;
    }
    bin[i] = '\0';
    strrev(bin);
    return bin;
}

void txt_to_bin(char *txt_input, char **bin_input){
        int txtL = strlen(txt_input);
        int *ascii_input = (int *) malloc(txtL * sizeof(int));

        
        for(int i=0; i<txtL; i++){
            ascii_input[i] = (int)txt_input[i];
            bin_input[i] = malloc(9 * sizeof(char));
            for(int j=0; j<10; j++){ 
                bin_input[i]= zero_fill(int_to_bin(ascii_input[i]));
            }
        }   
    }

char *char_to_bin(char ch){
        char *bin = (char *) malloc(9 * sizeof(char));
        strcpy(bin,int_to_bin(toascii(ch)));
        bin[9]='\0';
        return bin;    
    }

int bin_to_int(char *bin) {
    int n = 0;
    for (int i = 0; i < strlen(bin); i++) {
        n = n * 2 + (bin[i] - '0');
    }
    return n;
}

char bin_to_char(char *bin){
        char ch = (char) bin_to_int(bin);
        return ch;
}

void *parity_bits(char *bin) { //calculates parity bitsfor 1 char, outputs a string of those parity bits
    char *parity = (char *)malloc(5 * sizeof(char));

    //parity bits
    parity[0] = ((bin[0] - '0') ^ (bin[1] - '0') ^ (bin[3] - '0')) + '0';
    parity[1] = ((bin[0] - '0') ^ (bin[2] - '0') ^ (bin[3] - '0')) + '0';
    parity[2] = ((bin[1] - '0') ^ (bin[2] - '0') ^ (bin[3] - '0')) + '0';

    //even parity
    int even_parity = (bin[0] - '0') + (bin[1] - '0') + (bin[2] - '0') + (bin[3] - '0') +
                      (bin[4] - '0') + (bin[5] - '0') + (bin[6] - '0');

    parity[3] = (even_parity % 2) + '0';
    parity[4] = '\0';

    return parity;
}

char *hamm_enc(char *bin){ //inputs binary of 1 char and outputs hamming code of 1 char

    char *code = (char *)malloc(14 * sizeof(char));
    strcpy(code, strcat(parity_bits(bin), bin));

    code[13] = '\0';
    
    return code;
}


    char *hamm_dec(char *hamm){ //returns output string decoded

    
    
    return NULL;
    }
/*
    void check_txt(char *txt_input *hamm){ //loops output possibilities text
    }

    void check_bin(char *bin /*hamm){ //loops output possibilities binary
    }

    int compare(char *str){
        
        return p; //p: probabilty
    }
*/