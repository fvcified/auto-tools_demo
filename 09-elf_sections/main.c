#include <stdio.h>

// .data section — initialized global variable
int initialized = 42;

// .bss section — uninitialized global variable
int uninitialized;

// .rodata section — read-only string
const char *message = "ELF sections demo";

int main(void) {
    printf("%s\n", message);
    printf(".data: %d\n", initialized);

    uninitialized = 99;
    printf(".bss: %d\n", uninitialized);

    return 0;
}
