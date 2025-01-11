#include "FIFO.h"

void fifo_initialiser(Fifo* file) {
    file->debut = 0;
    file->fin = 0;
    file->taille = 0;
}

int fifo_est_vide(Fifo* file) {
    return file->taille == 0;
}

int fifo_est_pleine(Fifo* file) {
    return file->taille == MAX_SIZE;
}

int fifo_enfiler(Fifo* file, int element) {
    if (fifo_est_pleine(file)) {
        return 0;  // Impossible d'enfiler si la file est pleine
    }
    
    file->elements[file->fin] = element;
    file->fin = (file->fin + 1) % MAX_SIZE;
    file->taille++;
    
    return 1;
}

int fifo_defiler(Fifo* file, int* element) {
    if (fifo_est_vide(file)) {
        return 0;  // Impossible de défiler si la file est vide
    }
    
    *element = file->elements[file->debut];
    file->debut = (file->debut + 1) % MAX_SIZE;
    file->taille--;
    
    return 1;
}

int fifo_taille(Fifo* file) {
    return file->taille;
}