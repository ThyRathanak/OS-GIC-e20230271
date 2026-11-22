# OS Lab 4 — Linux I/O Redirection and Pipelines

## Personal Information

- **Name:** Thy Rathanak
- **Student ID:** e20230271
- **Linux account:** `gic-thy-rathanak`
- **Personal status and other word:** `paid` and `ready`

## Commands I Used

The following are the commands used to complete the core tasks. The commands are recorded for evidence only and are not an executable script.

| Stage | My command | Input received | Output produced |
|---|---|---|---|
| Select exact first field | `grep '^paid,' data/events.csv` | Original events.csv | 3 matching records: paid,3; paid,7; paid,5 |
| Extract field 2 | `grep '^paid,' data/events.csv \| cut -d, -f2` | 3 matching records | 3, 7, 5 |
| Count selected records | `grep '^paid,' data/events.csv \| wc -l` | 3 matching records | 3 |
| Save stdout and stderr separately | `cat data/missing.csv > evidence/stdout.txt 2> evidence/stderr.txt` | Missing input file | Empty stdout and an error message on stderr |
| Save exit status immediately | `echo $? > evidence/status.txt` | Exit status of the preceding cat command | Nonzero exit status |

## What My Tests Show

| Test | Expected | Observed | Mistake it would catch |
|---|---|---|---|
| Original records | 3 exact matches | 3 matching records | Matching the wrong first field |
| No match | 0 records | 0 records | Incorrect matching or assuming a missing record is an error |
| One added match plus a look-alike | 4 records | 4 records | Matching `paid-late` instead of exactly `paid` |
| Missing input | Empty stdout, diagnostic on stderr, nonzero status | Empty stdout, error message in stderr, nonzero status | Mixing stdout and stderr or ignoring command failure |

### Explain the Commands

**1. Why does the comma in `grep '^WORD,'` matter?**

The comma identifies the end of the first CSV field. For example, `grep '^paid,'` matches lines beginning with `paid,` but does not match `paid-late,`.

The `^` means the matching word must start at the beginning of the line. This helps select the exact status instead of matching similar words.

**2. Why does `wc -l` count records here, rather than add quantities?**

`wc -l` counts the number of lines received through standard input. Each matching CSV line represents one record.

For example, the matching quantities are 3, 7, and 5. The command returns 3 because there are three matching records. It does not calculate 3 + 7 + 5.

**3. Where did you use `>>`, and what would `>` do instead?**

I used `>>` when saving the second changed-input test result into `evidence/edge.txt`.

For example:

`grep '^paid,' data/changed.csv | wc -l >> evidence/edge.txt`

The `>>` operator appends new output to the existing file without deleting previous contents.

In contrast, `>` replaces the existing file contents. If I used `>` for the second test, the first test result would be lost.

**4. What does `tee` do that `>` alone does not?**

`tee` displays standard output on the terminal and saves the same output into a file.

For example:

`grep '^paid,' data/events.csv | tee evidence/selected.txt`

The output is visible on the screen and saved in `selected.txt`.

Using `>` alone saves the output into a file but does not display it on the terminal.

**5. Why must `echo $?` immediately follow the command being checked?**

`$?` stores the exit status of the most recently executed command.

If another command runs before `echo $?`, the value changes. Therefore, I must check the status immediately after the command I want to test.

Exit status 0 means success, while a nonzero status indicates a different outcome.

**6. Why can `cat missing-file | wc -l` report pipeline status 0?**

A pipeline normally returns the exit status of its last command.

In this example, `cat` fails because the input file does not exist. However, `wc -l` successfully receives the empty input and counts zero lines.

Therefore, the pipeline can return status 0 even though `cat` failed.

This demonstrates why checking individual commands and their error streams is important.

## Limits and Evidence

These commands assume simple comma-separated text without quoted commas. The `cut` command does not correctly interpret quoted CSV fields containing commas.

The saved results represent one execution of the commands. They do not prove that every future input will work or identify who executed the commands.

### Evidence Files

The following files are included in my submission:

| File | Purpose |
|---|---|
| `commands.txt` | Records the actual commands used |
| `selected.txt` | Stores the matching original records |
| `fields.txt` | Stores the extracted second fields |
| `normal.txt` | Stores the original matching-record count |
| `edge.txt` | Stores no-match and changed-input counts |
| `stdout.txt` | Stores standard output from the missing-file test |
| `stderr.txt` | Stores the missing-file diagnostic |
| `status.txt` | Stores the exit status |
| `checkpoint-selected.txt` | Stores the checkpoint matching records |
| `checkpoint.txt` | Stores the checkpoint record count |

The required submission structure is:

```text
lab4/
├── README.md
├── checkpoint.txt
└── evidence/
    ├── commands.txt
    ├── selected.txt
    ├── fields.txt
    ├── normal.txt
    ├── edge.txt
    ├── stdout.txt
    ├── stderr.txt
    ├── status.txt
    └── checkpoint-selected.txt
```

## Optional Work / AI Note

I used AI assistance to understand Linux commands, redirection, pipelines, and the purpose of the different tests.

I practiced the commands directly in the Linux terminal and checked their outputs using the `oslab` helper.

One important observation was that a pipeline can return status 0 even when an earlier command fails. Therefore, checking only the pipeline status is not always sufficient.

No additional script was required for this lab.
