# Module 05: ELF Binary Analysis

This module demonstrates how to inspect ELF binaries to find hidden
symbols, functions, and IFUNC resolvers — the exact technique used
to investigate the XZ Utils backdoor.

## How to Run

```bash
# Compile
gcc main.c -o demo

# List all symbols in the binary
readelf -s demo

# Disassemble
objdump -d demo

# Check dynamic dependencies
ldd demo

# Check section headers
readelf -S demo
```

## Key Insight

The XZ backdoor was not visible in source code — it was injected as
a binary object file during the build process. `readelf` and `objdump`
are the tools that reveal what is actually inside a compiled binary,
regardless of what the source code says.
