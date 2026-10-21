# OS Lab 1 Submission

**Student Name:** Thy Rathanak  
**Student ID:** e20230271  
**Ubuntu username on the server:** gic-thy-rathanak

**My values (`oslab values lab1`):** file1 = pencil, file2 = bridge, count = 3

## Task 1: Operating System Identification

Describe the operating system and kernel information shown by the commands. Explain which number is the kernel version and which is the Ubuntu distribution version.

## Task 2: Essential Linux File and Directory Commands

I practiced creating, copying, renaming, and deleting files using Linux commands. Describe what happened during these operations and what the final `ls` command showed.

## Task 3: Package Management Using APT

I installed Midnight Commander (`mc`) and checked its executable and configuration directory.

- After `apt-get remove mc`, the configuration directory `/etc/mc` still existed.
- After `apt-get purge mc`, the configuration directory `/etc/mc` was removed.

This showed that `remove` removes the package but generally keeps system configuration files, while `purge` also removes package configuration files.

**Evidence:** See `images/image3`.

## Task 4: Programs vs Processes

Describe how you started a program in the background and found its process using the process-listing commands. Explain that a program is a file containing instructions, while a process is a running instance of a program. Describe what you observed before, during, and after it ran.

## Task 5: Multitasking

Describe what happened when multiple `sleep` processes ran at the same time. Record the number of `sleep` lines shown by `ps` from your actual result.

Explain that multiple processes can make progress concurrently, but the output of `ps` alone does not prove exactly how CPU time was shared.

**Evidence:** See `images/task5.png`.

## Task 6: Virtualization and Hypervisor Detection

State whether the command outputs indicated a virtual machine or physical hardware. Explain which command output supports your conclusion.

**Evidence:** See `images/task6.png`.

## My Prediction: Confirmed or Corrected

For each answer recorded by `oslab predict lab1`, state whether your prediction was **confirmed** or **corrected** and briefly explain the evidence. Include the third prediction about `apt-get remove`, using your Task 3 observation.

## Plus / Challenge (only if completed)

Describe any optional challenge you completed and the result. If you did not complete one, you can leave this section out.

## AI Note (optional)

An AI tool suggested comparing `apt-get remove` with `apt-get purge`. I checked this suggestion by observing whether `/etc/mc` existed after each command.
