#include "nouveau_motion.h"
#include <stdlib.h>

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