# Module 06: Dynamic Linking & LD_PRELOAD

This module demonstrates how `LD_PRELOAD` intercepts and hooks
shared library functions at runtime — without modifying the binary.

This is the same class of technique used in the XZ Utils backdoor
to hook `RSA_public_decrypt` in OpenSSH.

## Files

| File | Purpose |
| -------- | ------- |
| `hook.h` | Header — declares `system()` hook |
| `hook.c` | Shared library that intercepts `system()` |
| `main.c` | Target program that calls `system()` |

## How to Run

```bash
# Compile target
gcc main.c -o demo

# Compile hook as shared library
gcc -shared -fPIC hook.c -o hook.so -ldl

# Run normally
./demo

# Run with hook injected via LD_PRELOAD
LD_PRELOAD=./hook.so ./demo
```

## Key Insight

`LD_PRELOAD` forces the dynamic linker to load a shared library before
all others — any function defined in it overrides the original.

In the XZ backdoor, this mechanism was used to silently replace
`RSA_public_decrypt` so that specially crafted SSH keys could grant
unauthorized root access without touching OpenSSH source code.
