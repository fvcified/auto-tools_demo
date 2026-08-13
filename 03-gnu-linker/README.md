# Module 03: GNU Linker (`ld`)

This module demonstrates how the GNU Linker (`ld`) combines separate
object files into a single executable binary.

## Files

| File | Purpose |
| -------- | ------- |
| `function.h` | Header — declares `greet()` |
| `function.c` | Implementation of `greet()` |
| `main.c` | Entry point — calls `greet()` |

## How to Run

```bash
# Compile each file into object files
gcc -c function.c -o function.o
gcc -c main.c -o main.o

# Link manually using ld
ld function.o main.o -o result --dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc

# Run
./result
```

## Key Insight

`gcc main.c function.c -o result` does compile + link in one step automatically.
Here we separate the two stages explicitly to show that `ld` is its own process
that combines `.o` object files into an executable.

`ld` directly requires a `_start` entry point — `gcc` supplies this automatically
via `crt1.o`, `crti.o`, `crtn.o`. Without it, `ld` throws a warning and the
binary segfaults after execution.
