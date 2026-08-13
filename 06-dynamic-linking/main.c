#include <stdio.h>
#include <stdlib.h>
#include "hook.h"

int main(void) {
    printf("Dynamic linking demo\n");
    system("echo hello from system()");
    return 0;
}