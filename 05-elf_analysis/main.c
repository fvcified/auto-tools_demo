#include <stdio.h>

// Intentionally uncalled — inspect via: readelf -s demo | grep secret
// Demonstrates that symbols remain in ELF even if never executed
void secret() {
    printf("Hidden function in ELF symbol table\n");
}

int main(void) {
    printf("ELF Analysis demo\n");
    return 0;
}