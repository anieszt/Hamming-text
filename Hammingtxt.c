#include <stdio.h>
#include "hammingtxt.h"


int main() {
    char a[500];

    if (fgets(a, sizeof(a), stdin) == NULL) {
        perror("Error reading input");
        return 1;
    }

    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
        len--;
    }

    char **b = (char **)malloc(len * sizeof(char *));

    if (b == NULL) {
        perror("Memory allocation for b failed");
        return 1;
    }

    for (size_t i = 0; i < len; i++) {
        b[i] = (char *)malloc((strlen(a) + 1) * sizeof(char));
        if (b[i] == NULL) {
            perror("Memory allocation for b[i] failed");
            for (size_t j = 0; j < i; j++) {
                free(b[j]);
            }
            free(b);
            return 1;
        }
    }

    char *parity = (char *)malloc(5 * sizeof(char));

    if (parity == NULL) {
        perror("Memory allocation for parity failed");
        for (size_t i = 0; i < len; i++) {
            free(b[i]);
        }
        free(b);
        return 1;
    }

    txt_to_bin(a, b);

    for (size_t i = 0; i < len; i++) {
        strcpy(parity, parity_bits(b[i]));
        printf("%c %s %s\n", bin_to_char(b[i]), b[i], parity);
    }

    for (size_t i = 0; i < len; i++) {
        free(b[i]);
    }

    free(b);
    free(parity);
    return 0;
}








/*int main(){
    
    char a[500];
    fgets(a, sizeof(a), stdin);

    char **b =  (char **) malloc(strlen(a) * sizeof(char *));

    if (b == NULL) {
        perror("Memory allocation for b failed");
        return 1;
    }

    char *parity = (char *) malloc(5 * sizeof(char));

        if (parity == NULL) {
        perror("Memory allocation for parity failed");
        free(b);
        return 1; 
    }

    txt_to_bin(a, b);
    for (size_t i = 0; i <= strlen(a); i++){
        strcpy(parity, parity_bits(b[i]) );
        printf("%c %s %s\n", bin_to_char(b[i]), b[i], parity);
    }

    for (size_t i = 0; i < strlen(a); i++) {
        free(b[i]); 
    }

    free(b);
    free(parity);
    return 0;
}*/