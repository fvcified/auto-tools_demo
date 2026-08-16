#include <stdio.h>
#include "mylib.h"

int main(void) {
    mylib_hello();
    printf("[SHARED LIB] 6 + 7 = %d\n", mylib_add(6, 7));
    return 0;
}
