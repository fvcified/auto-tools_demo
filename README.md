# Low-Level Linux Mechanics & Dual-Use Tools

This repository contains practical experiment modules exploring Linux build systems, linkers, and low-level function dispatch mechanics.

Inspired by **[Andres Freund's](https://github.com/anarazel)** discovery of a 500ms latency anomaly during the XZ Utils supply chain incident (CVE-2024-3094).

---

## Modules

| Module | Topic |
| -------- | ------- |
| `01-git-history/` | Transparent code tracking via Git |
| `02-autotools-m4/` | M4 Macros & Autotools build automation |
| `03-gnu-linker/` | Manual linking with GNU Linker (`ld`) |
| `04-gnu-ifunc/` | Dynamic function dispatch via GNU IFUNC |
| `05-elf-analysis/` | ELF binary inspection with `readelf` & `objdump` |

---

## Concepts Explored

- **Dual-Use Technology**: How performance tools (`IFUNC`, build macros) work in legitimate workflows vs. exploitation mechanics.
- **Build-Time Mechanics**: Source -> preprocessor -> compiler -> linker -> execution.
- **Supply Chain Awareness**: Understanding what happens beneath `./configure && make`.

---

## Key Findings

- `ld` directly requires manual `_start` entry point — `gcc` wraps this automatically via `crt1.o`, `crti.o`, `crtn.o`.
- GNU IFUNC resolves function dispatch at runtime based on CPU capabilities.
- Autotools `AM_INIT_AUTOMAKE([foreign])` flag bypasses GNU standard file requirements (`AUTHORS`, `ChangeLog`, etc).

---

> *"System security is measured not only by code quality, but also by acute attention to low-level operational details."*
