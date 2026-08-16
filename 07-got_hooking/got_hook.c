#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include "got_hook.h"

void original_target(void) {
    printf("[ORIGINAL] legitimate function called\n");
}

void hook_target(void) {
    printf("[HOOKED] GOT entry redirected — attacker controls execution\n");
}
