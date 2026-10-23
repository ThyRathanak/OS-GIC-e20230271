# Lab 2 — Linux Navigation and File Management: Individual Report

- **Student name/ID:** Thy Rathanak / e20230271
- **Ubuntu username:** `gic-thy-rathanak`
- **My values (`oslab values lab2`):** file1 = tax summary.txt, file2 = travel claims.txt, owner = Legal, 
reader = Engineering, third = Marketing
- **Files:** `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| **Step** | **My command** | **Current folder when I ran it** |
|---|---|---|
| Move the first file (relative destination) | `mv 'incoming/[first filename]' reports/` | `TechCorp/Engineering/drafts/` |
| Move the second file (absolute paths) | `mv '[second file path]' '[absolute reports path]/'` | `[folder where I ran the command]` |
| Read the report from my reader department (relative path) | `cat '[relative path to report]'` | `TechCorp/[reader department]/` |
| The path error I made on purpose, and its message | `cat 'reports/tax summary.txt'` — `No such file or directory` | `TechCorp/[reader department]/` |
| The relative path that fixed it | `[working relative path recorded in evidence/paths.txt]` | `TechCorp/[reader department]/` |

## Explanation

A correct file name can still give “No such file or directory” when the command starts from a different current directory than expected. Linux resolves a relative path from the current directory, so the path must correctly describe how to reach the file from that location. The `mv` command moves a file to another location, while `cp` creates a copy and keeps the original file. In this lab, I moved the report files into `reports/` and copied them into `TechCorp/Legal/` to check that the copies contained the same data.

## What My Tests Do Not Prove

The `ls` command shows file names and directory contents, but it does not prove that two files contain identical data. The `cmp` command can compare two files byte by byte; no output means the files are identical.

## Plus / Challenge (only if you did them)

I attempted the path-navigation checkpoint and saved its result in `evidence/checkpoint.txt`. I will include any one-command move, `..` count, or wildcard answers here only if I completed those optional challenges.

## AI Note (optional)

An AI tool suggested checking the submission directory and evidence files. I tested the lab with `oslab check lab2`, which reported that all six milestones passed.
