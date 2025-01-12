#include "nouveau_motion.h"
#include <stdlib.h>
#include <string.h>

ProcessingParams create_default_params(int i0, int i1, int j0, int j1) {
    return (ProcessingParams) {
        .i0 = i0,
        .i1 = i1,
        .j0 = j0,
        .j1 = j1,
        .sd_threshold = DEFAULT_SD_THRESHOLD,
        .min_surface = MIN_SURFACE_SIZE,
        .max_surface = MAX_SURFACE_SIZE
    };
}

// Allocation d'une matrice 2D
static uint8_t** alloc_matrix_ui8(int height, int width) {
    uint8_t **matrix = malloc(height * sizeof(uint8_t*));
    if (!matrix) return NULL;
    
    matrix[0] = calloc(height * width, sizeof(uint8_t));
    if (!matrix[0]) {
        free(matrix);
        return NULL;
    }
    
    for (int i = 1; i < height; i++) {
        matrix[i] = matrix[0] + i * width;
    }
    return matrix;
}

static uint32_t** alloc_matrix_ui32(int height, int width) {
    uint32_t **matrix = malloc(height * sizeof(uint32_t*));
    if (!matrix) return NULL;
    
    matrix[0] = calloc(height * width, sizeof(uint32_t));
    if (!matrix[0]) {
        free(matrix);
        return NULL;
    }
    
    for (int i = 1; i < height; i++) {
        matrix[i] = matrix[0] + i * width;
    }
    return matrix;
}

ImageData* create_image_data(int width, int height) {
    ImageData *data = malloc(sizeof(ImageData));
    if (!data) return NULL;
    
    data->width = width;
    data->height = height;
    data->input = alloc_matrix_ui8(height, width);
    data->binary = alloc_matrix_ui8(height, width);
    data->labels = alloc_matrix_ui32(height, width);
    
    if (!data->input || !data->binary || !data->labels) {
        free_image_data(data);
        return NULL;
    }
    
    return data;
}

void free_image_data(ImageData *data) {
    if (!data) return;
    if (data->input) {
        free(data->input[0]);
        free(data->input);
    }
    if (data->binary) {
        free(data->binary[0]);
        free(data->binary);
    }
    if (data->labels) {
        free(data->labels[0]);
        free(data->labels);
    }
    free(data);
}

static motion_status_t apply_sigma_delta(ImageData *data, ProcessingParams *params) {
    if (!data || !params) return MOTION_NULL_INPUT;
    
    for (int i = params->i0; i < params->i1; i++) {
        for (int j = params->j0; j < params->j1; j++) {
            if (data->input[i][j] > params->sd_threshold) {
                data->binary[i][j] = 255;
            } else {
                data->binary[i][j] = 0;
            }
        }
    }
    return MOTION_OK;
}

motion_status_t process_motion_frame(ImageData *data, ProcessingParams *params) {
    if (!data || !params) return MOTION_NULL_INPUT;
    if (params->i1 <= params->i0 || params->j1 <= params->j0) {
        return MOTION_INVALID_PARAMS;
    }
    
    motion_status_t status = apply_sigma_delta(data, params);
    if (status != MOTION_OK) return status;
    
    return MOTION_OK;
}