# Module 07: GOT Hooking (Global Offset Table Hooking)

This module demonstrates how the Global Offset Table (GOT) works and how it can be manipulated to redirect function calls at runtime.

## Background

When `sshd` calls `RSA_public_decrypt` from OpenSSL, it does not call it directly — it goes through the PLT and GOT:

sshd -> PLT -> GOT (address of RSA_public_decrypt) -> OpenSSL

The XZ backdoor used IFUNC (Module 04) to run early, then replaced the GOT entry of `RSA_public_decrypt` with its own function using `mprotect()` to bypass memory protection.

## Files

| File | Purpose |
| -------- | ------- |
| `got_hook.h` | Header — declares hook and original functions |
| `got_hook.c` | Demonstrates original vs hooked function |
| `main.c` | Entry point |

## How to Run

```bash
gcc got_hook.c main.c -o got_demo
./got_demo
```

## Key Insight

GOT is writable by default at startup. The backdoor used `mprotect()` to temporarily unlock memory, overwrite the GOT entry, then relock it — making the hook invisible to security scanners checking the filesystem.
