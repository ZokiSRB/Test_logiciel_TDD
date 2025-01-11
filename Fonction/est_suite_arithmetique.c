#include "est_suite_arithmetique.h"
#include <stdio.h>

int est_suite_arithmetique(int liste[], int taille) {
    if (taille <= 1) {
        return 1;
    }
    
    int diff = liste[1] - liste[0];
    for (int i = 1; i < taille - 1; i++) {
        if (liste[i + 1] - liste[i] != diff) {
            return 0;
        }
    }
    return 1;
}