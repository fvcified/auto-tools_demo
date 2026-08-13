#include <stdio.h>

void secret() {
    printf("Hidden function in ELF symbol table\n");
}

int main(void) {
    printf("ELF Analysis demo\n");
    return 0;
}
