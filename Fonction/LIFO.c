#include "LIFO.h"

void lifo_initialiser(Lifo* pile) {
    pile->sommet = -1;
}

int lifo_est_vide(Lifo* pile) {
    return pile->sommet == -1;
}

int lifo_est_pleine(Lifo* pile) {
    return pile->sommet == MAX_SIZE - 1;
}

int lifo_empiler(Lifo* pile, int element) {
    if (lifo_est_pleine(pile)) {
        return 0;  // Impossible d'empiler si la pile est pleine
    }
    
    pile->sommet++;
    pile->elements[pile->sommet] = element;
    return 1;
}

int lifo_depiler(Lifo* pile, int* element) {
    if (lifo_est_vide(pile)) {
        return 0;  // Impossible de dépiler si la pile est vide
    }
    
    *element = pile->elements[pile->sommet];
    pile->sommet--;
    return 1;
}

int lifo_taille(Lifo* pile) {
    return pile->sommet + 1;
}