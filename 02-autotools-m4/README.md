# 🛠️ Module 02: GNU Autotools & M4 Macro Automation

This module demonstrates how GNU Autotools uses M4 Macros to inspect
the system environment and generate portable `./configure` scripts.

This is the exact build system used by XZ Utils — understanding it
reveals how the backdoor was injected at the build configuration stage.

## 📁 Files

| File | Purpose |
|------|---------|
| `configure.ac` | M4 macro input — defines build requirements |
| `Makefile.am` | Automake input — defines what to build |
| `main.c` | Demo program |

## 🚀 How to Run

```bash
aclocal
autoconf
automake --add-missing
./configure
make
./autotools_demo
```

## 🔍 Key Insight

`AM_INIT_AUTOMAKE([foreign])` — the `foreign` flag bypasses GNU standard
file requirements (AUTHORS, ChangeLog, NEWS, README).
Without it, automake refuses to generate Makefile.in.
