#include <stdio.h>
#include <string.h>
#include "trois_plus_grand.h"
void trois_plus_grand(int liste[], int taille, int stockage_res[]){
    if (taille < 3){
        printf("La taille de la liste est inférieure à 3\n");
        return;
    }
    int copie_liste[taille];
    memcpy(copie_liste, liste, taille * sizeof(int));
    int i, j, temp;
    for(i = 0; i < taille; i++){
        for(j = i + 1; j < taille; j++){
            if(copie_liste[i] < copie_liste[j]){
                temp = copie_liste[i];
                copie_liste[i] = copie_liste[j];
                copie_liste[j] = temp;
            }
        }
    }
    for(i = 0; i < 3; i++){
        stockage_res[i] = copie_liste[i];
    }
}