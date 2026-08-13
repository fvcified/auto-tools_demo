#include <stdio.h>
#include "demo.h"

void stdAlgorithm(void) {
    printf("Standard fallback algorithm\n");
}

void optAlgorithm(void) {
    printf("CPU-optimized high-performance path\n");
}

static void (*res_greet(void))(void) {
    return optAlgorithm;
}

void dyngreet(void) __attribute__((ifunc("res_greet")));