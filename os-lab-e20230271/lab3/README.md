# Lab 3 — Wildcards, Hard Links and Symbolic Links: Individual Report

- **Student name/ID:** Thy Rathanak / e20230271
- **Ubuntu username:** `gic-thy-rathanak`
- **My values (`oslab values lab3`):** name = `maple`, tag = `backup`, v1 = `803`, v2 = `863`
- **Files:** `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | `version 803` | `version 803` | `maple.txt` |
| After the rename, before the repair | `version 803` | Error: No such file or directory | `maple.txt` |
| After a new file took the old name | `version 803` | `version 863` | `maple.txt` |
| After my repair | `version 803` | `version 803` | `maple-backup.txt` |

**My repair (the two commands I wrote):**

```bash
rm maple-soft.txt
ln -s maple-backup.txt maple-soft.txt
```

## Explanation

A hard link and a symbolic link work differently in Linux. A hard link points to the same inode as the original file, so after renaming `maple.txt` to `maple-backup.txt`, the hard link still accesses the original data, which is `version 803`. A symbolic link stores the filename `maple.txt`, not the file's inode. When I created a new `maple.txt` containing `version 863`, the symbolic link followed that filename and displayed the new content. After repairing the symbolic link to point to `maple-backup.txt`, it displayed `version 803` again. The inode numbers in `evidence/replacement.txt` demonstrate that the hard link and renamed original share an inode, while the new file has a different inode.

## What My Tests Do Not Prove

The `cat` command only shows the contents of a file; it does not show whether two filenames refer to the same inode. I need `ls -li` to compare inode numbers and prove that hard links refer to the same underlying file.

## Plus / Challenge (only if you did them)

**Wildcard patterns:**

- `[12]` matches `maple1.txt` and `maple2.txt`.
- `[!1]*` matches filenames that do not start with `1`.

**Hard-link challenge:**

- Creating a hard link increases the number of links to the inode.
- Removing one filename does not delete the data while another hard link still exists.
- The data is removed after the last hard link is deleted.

## AI Note (optional)

AI suggested that a relative symbolic-link target is resolved from the directory containing the symbolic link. I checked this using `readlink` and `cat` after repairing my symbolic link.
