# Module 01: Git History & Transparent Code Tracking

This module demonstrates how Git records every change made to a codebase,
enabling full auditability of who changed what and when.

This is the exact capability Andres Freund relied on when investigating
the XZ Utils backdoor — tracing suspicious commits through git log and diff.

## Run

```bash
gcc main.c -o demo
./demo
```

## Key Commands

```bash
# View full commit history
git log --oneline

# See what changed in a specific commit
git show <commit-hash>

# Compare two commits
git diff <hash-a> <hash-b>
```
