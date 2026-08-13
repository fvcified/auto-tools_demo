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

The resolver function `res_greet()` runs at load time and returns
a pointer to either `stdAlgorithm` or `optAlgorithm`.

In production code, the resolver checks CPU flags (e.g. AVX2, SSE4)
to pick the fastest implementation. In the XZ backdoor, this same
mechanism was used to silently hook `RSA_public_decrypt` in OpenSSH.
