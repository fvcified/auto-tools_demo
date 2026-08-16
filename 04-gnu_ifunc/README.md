# Module 04: GNU IFUNC — Dynamic Function Dispatch

This module demonstrates how GNU Indirect Functions (IFUNC) resolve
function calls at runtime based on CPU capabilities.

This is one of the core mechanisms abused in the XZ Utils backdoor —
IFUNC resolvers can silently redirect function calls at load time.

## Files

| File | Purpose |
| -------- | ------- |
| `demo.h` | Header — declares all functions |
| `demo.c` | IFUNC implementation and resolver |
| `main.c` | Entry point — calls `dynGreet()` |

## How to Run

```bash
gcc demo.c main.c -o ifunc_demo
./ifunc_demo
```

## Key Insight

The resolver `res_greet()` runs **once at load time** before `main()` is called.
It checks CPU flags using `__builtin_cpu_supports("avx2")` — a legitimate
performance pattern used in glibc itself (e.g. `memcpy`, `strlen`).

In the XZ backdoor, the same mechanism ran a resolver that checked for a
**specific RSA key structure** instead of CPU flags — silently redirecting
`RSA_public_decrypt` to the attacker's function before any SSH authentication occurred.
