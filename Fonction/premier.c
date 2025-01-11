#include "premier.h"
#include <stdio.h>

int est_premier(int nb) {
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Pas très utile pour le fichier test car on l'appele pas mais si je devais l'utiliser normalement je l'utiliserais pour vérifier si un nombre est premier
// Comme ça le programme est plus lisible et je n'ai pas de vérfication à faire moi meme
void premier(int nb_liste[]) {
    for (int i = 0; i < 5; i++) {
        if (est_premier(nb_liste[i])) {
            printf("%d est premier\n", nb_liste[i]);
        } else {
            printf("%d n'est pas premier\n", nb_liste[i]);
        }
    }
}