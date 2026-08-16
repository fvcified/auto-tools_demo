#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "hook.h"

int system(const char *cmd) {
    printf("system() intercepted — command: %s\n", cmd);

    int (*orig_system)(const char *) = dlsym(RTLD_NEXT, "system");
    return orig_system(cmd);
}