#include <stdio.h>
#include "mylib.h"

void mylib_hello(void) {
    printf("[SHARED LIB] hello from mylib.so\n");
}

int mylib_add(int a, int b) {
    return a + b;
}
