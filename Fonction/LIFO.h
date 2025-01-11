#ifndef LIFO_H
#define LIFO_H

#define MAX_SIZE 100  // Taille maximale de la pile

typedef struct {
    int elements[MAX_SIZE];
    int sommet;
} Lifo;

void lifo_initialiser(Lifo* pile);
int lifo_est_vide(Lifo* pile);
int lifo_est_pleine(Lifo* pile);
int lifo_empiler(Lifo* pile, int element);
int lifo_depiler(Lifo* pile, int* element);
int lifo_taille(Lifo* pile);

#endif