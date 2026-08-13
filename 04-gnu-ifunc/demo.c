#include <stdio.h>
#include "demo.h"

void standard_algorithm(void) {
    printf("[IFUNC] Executing standard fallback algorithm.\n");
}

void optimized_algorithm(void) {
    printf("[IFUNC] Executing CPU-optimized high-performance path!\n");
}

static void (*resolve_greet(void))(void) {
    return optimized_algorithm;
}

void dynamic_greet(void) __attribute__((ifunc("resolve_greet")));