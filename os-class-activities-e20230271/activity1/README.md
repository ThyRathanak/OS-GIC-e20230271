\## Task 1: File Creator \& Reader



\### Part A Questions



\*\*1. What flags did you pass to `open()`? What does each flag mean?\*\*



I used `O\_WRONLY | O\_CREAT | O\_TRUNC`.



\- `O\_WRONLY`: Opens the file for writing only.

\- `O\_CREAT`: Creates the file if it does not exist.

\- `O\_TRUNC`: Clears the existing contents if the file already exists.

\- `|`: Combines the flags so they can be used together.



\*\*2. What is `0644` in the permission argument? What does each digit represent?\*\*



`0644` specifies the file permissions when a new file is created, subject to the process's umask.



\- `0`: Indicates octal notation.

\- `6`: The owner can read and write (`rw-`).

\- `4`: The group can read (`r--`).

\- `4`: Other users can read (`r--`).



Therefore, the permissions are `rw-r--r--`.



\*\*3. What does `fopen("output.txt", "w")` do internally that you had to do manually with `open()`?\*\*



`fopen()` opens the file for writing, creates it if it does not exist, and truncates it if it already exists. In the system-call version, I must explicitly use `open()` with `O\_WRONLY | O\_CREAT | O\_TRUNC`. The library version also creates a `FILE` stream and manages buffering.



\### Part B Questions



\*\*1. What does `read()` return? How is this different from `fgets()`?\*\*



`read()` returns the number of bytes actually read. It returns `0` at the end of the file and `-1` if an error occurs. `fgets()` returns a pointer to the buffer when it successfully reads a line or part of a line, and returns `NULL` when it reaches the end of the file without reading more data or when an error occurs.



\*\*2. Why do you need a loop when using `read()`? When does it stop?\*\*



A loop is needed because one call to `read()` may not read the entire file. The loop continues reading and displaying data until `read()` returns `0`, indicating the end of the file. If `read()` returns `-1`, an error has occurred.



