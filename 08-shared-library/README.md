# Module 08: Shared Library (.so)

This module demonstrates how shared libraries work in Linux — how they are built, loaded, and linked at runtime.

This is directly relevant to XZ Utils — `liblzma` is a shared library. Understanding how `.so` files are loaded explains why the backdoor could propagate through the dependency chain into `sshd`.

## Files

| File | Purpose |
| -------- | ------- |
| `mylib.h` | Header — declares library functions |
| `mylib.c` | Shared library implementation |
| `main.c` | Program that uses the shared library |

## How to Run

```bash
# Build shared library
gcc -shared -fPIC mylib.c -o libmylib.so

# Build main linking to shared library
gcc main.c -L. -lmylib -o demo -Wl,-rpath,.

# Run
./demo
```

## Key Insight

`liblzma` (XZ Utils) is a shared library loaded by `sshd` as a dependency. The backdoor was injected into `liblzma` — so when `sshd` loaded it at startup, the malicious IFUNC resolver ran automatically before any authentication took place.
