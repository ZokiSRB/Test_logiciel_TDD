#ifndef FIFO_H
#define FIFO_H

#define MAX_SIZE 100  // Taille maximale de la file

typedef struct {
    int elements[MAX_SIZE];
    int debut;
    int fin;
    int taille;
} Fifo;

void fifo_initialiser(Fifo* file);
int fifo_est_vide(Fifo* file);
int fifo_est_pleine(Fifo* file);
int fifo_enfiler(Fifo* file, int element);
int fifo_defiler(Fifo* file, int* element);
int fifo_taille(Fifo* file);

#endif