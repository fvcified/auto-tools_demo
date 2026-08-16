#include <stdio.h>
#include <dlfcn.h>
#include "demo.h"

void stdAlgorithm(void) {
    printf("Standard fallback algorithm\n");
}

void optAlgorithm(void) {
    printf("CPU-optimized high-performance path (AVX2)\n");
}

static void (*res_greet(void))(void) {
    if (__builtin_cpu_supports("avx2")) {
        return optAlgorithm;
    }
    return stdAlgorithm;
}

void dynGreet(void) __attribute__((ifunc("res_greet")));