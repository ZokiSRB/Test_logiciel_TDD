// nouveau_motion.h
#ifndef MOTION_PROCESSING_H
#define MOTION_PROCESSING_H

#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_SD_THRESHOLD 2
#define MIN_SURFACE_SIZE 50
#define MAX_SURFACE_SIZE 100000
#define MAX_ROIS_FIRST_PASS 65536

// Structure pour les paramètres de traitement
typedef struct {
    int i0, i1, j0, j1;    // Dimensions
    int sd_threshold;       // Seuil sigma-delta
    int min_surface;        // Surface minimale
    int max_surface;        // Surface maximale
} ProcessingParams;

// Déclaration de la fonction de création des paramètres
ProcessingParams create_default_params(int i0, int i1, int j0, int j1);

// Structure pour les données d'image
typedef struct {
    uint8_t **input;        // Image d'entrée
    uint8_t **binary;       // Résultat binaire
    uint32_t **labels;      // Étiquettes
    int width, height;      // Dimensions
} ImageData;

// Codes d'erreur
typedef enum {
    MOTION_OK,
    MOTION_NULL_INPUT,
    MOTION_INVALID_PARAMS,
    MOTION_PROCESSING_ERROR
} motion_status_t;

// Fonctions principales
ImageData* create_image_data(int width, int height);
void free_image_data(ImageData *data);
motion_status_t process_motion_frame(ImageData *data, ProcessingParams *params);
#endif