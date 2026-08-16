# Module 09: ELF Sections

This module demonstrates the key sections inside an ELF binary and their roles — the same structures manipulated by the XZ Utils backdoor.

## ELF Sections

| Section | Purpose |
| -------- | ------- |
| `.text` | Executable code |
| `.rodata` | Read-only data (string literals, constants) |
| `.data` | Initialized global variables |
| `.bss` | Uninitialized global variables |
| `.plt` | Procedure Linkage Table — gateway to external functions |
| `.got` | Global Offset Table — address book for external functions |

## Files

| File | Purpose |
| -------- | ------- |
| `main.c` | Demo showing `.data`, `.bss`, `.rodata` sections |

## How to Run

```bash
gcc main.c -o demo

# Inspect ELF sections
readelf -S demo | grep -E "\.text|\.data|\.bss|\.plt|\.got|\.rodata"

# Run
./demo
```

## Key Insight

The XZ backdoor targeted `.got` — specifically the GOT entry of `RSA_public_decrypt`. By overwriting that address using `mprotect()`, it redirected all SSH key verification to its own function without touching any file on disk.
