#include <stdio.h>
#include "got_hook.h"

int main(void) {
    printf("Calling original_target():\n");
    original_target();

    printf("\nIn XZ backdoor, GOT entry of RSA_public_decrypt\n");
    printf("was silently replaced with attacker function:\n");
    hook_target();

    return 0;
}
