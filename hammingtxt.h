#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

char **txt_to_bin(char *txt_input){
        int txtL = strlen(txt_input);
        int *ascii_input = (int *) malloc(txtL * sizeof(int));
        char **bin_input= (char **) malloc(txtL * sizeof(char));

        for(int i=0; i<txtL; i++){
            ascii_input[i] = (int)txt_input[i];
            bin_input[i] = malloc(9 * sizeof(char));
            for(int j=0; j<10; j++){ 
                bin_input[i]= int_to_bin(ascii_input[i]);
            }
            printf("%s", bin_input[i]);
        }
        
        return bin_input;    
    }




//free()
/*
    char *bin_to_txt(char *bin){

        return txt_output;
    }


    int hamm(){ //returns output string and errors positions as accurately as possible
        return 0;
    }

    void check_txt(char *txt_input /*hamm){ //loops output possibilities text
    }

    void check_bin(char *bin /*hamm){ //loops output possibilities binary
    }

    int compare(char *str){
        
        return p; //p: probabilty
    }
*/