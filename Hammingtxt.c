#include <stdio.h>
#include "hammingtxt.h"


int main() {

    //-------------------------------------------arrays setting and errors-----------------------------------------
    char a[500];

    if (fgets(a, sizeof(a), stdin) == NULL) {
        perror("txt input mem error");
        return 1;
    }

    size_t len = strlen(a); //remove line returns
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
        len--;
    }

    char **b = (char **)malloc(len * sizeof(char *));

    if (b == NULL) {
        perror("txttobin elements mem error");
        return 1;
    }

    for (size_t i = 0; i < len; i++) {
        b[i] = (char *)malloc((strlen(a) + 1) * sizeof(char));
        if (b[i] == NULL) {
            perror("txttobin output mem error");
            for (size_t j = 0; j < i; j++) {
                free(b[j]);
            }
            free(b);
            return 1;
        }
    }

    char *parity = (char *)malloc(5 * sizeof(char));

    if (parity == NULL) {
        perror("parity mem error");
        for (size_t i = 0; i < len; i++) {
            free(b[i]);
        }
        free(b);
        return 1;
    }

    
//-------------------------------------------------test-----------------------------------------------------
    txt_to_bin(a, b);

    for (size_t i = 0; i < len; i++) {
        strcpy(parity, parity_bits(b[i]));
        printf("%c %s %s   %s\n", bin_to_char(b[i]), b[i], parity, hamm_enc(b[i]));
    }

    for (size_t i = 0; i < len; i++) {
        free(b[i]);
    }

    free(b);
    free(parity);
    return 0;
}