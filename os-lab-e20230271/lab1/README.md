# OS Lab 1 Submission

**Student Name:** Thy Rathanak  
**Student ID:** e20230271  
**Ubuntu username on the server:** gic-thy-rathanak

**My values (`oslab values lab1`):** `file1 = pencil`, `file2 = bridge`, `count = 3`

## Task 1: Operating System Identification

I used Linux commands to check the operating system and kernel information.

- **Kernel version:** `7.0.0-38-generic`
- **Ubuntu distribution version:** `26.04.1 LTS`
- **Ubuntu release:** `26.04`
- **Codename:** `resolute`

The kernel version identifies the Linux kernel running on the system. The Ubuntu distribution version identifies the Ubuntu operating system release. They are different because Ubuntu is a Linux distribution that uses the Linux kernel.

## Task 2: Essential Linux File and Directory Commands

I practiced creating, copying, renaming, and deleting files using Linux commands. I used commands such as `touch`, `cp`, `mv`, `rm`, `mkdir`, and `ls`.

I created files and directories, copied a file, renamed a file, and removed files when they were no longer needed. The `ls` command displayed the remaining files in the directory.

My final directory listing included:

- `bridge_renamed.txt`
- `pencil.txt`
- `task2`
- `task2_file.txt`

This activity helped me understand how to manage files and directories from the Linux terminal.

## Task 3: Package Management Using APT

I installed Midnight Commander (`mc`) and checked its executable and configuration directory.

After running `apt-get remove mc`, the configuration directory `/etc/mc` still existed. After running `apt-get purge mc`, the configuration directory `/etc/mc` was removed.

This demonstrated the difference between the two commands:

- `apt-get remove mc` removes the package but generally keeps its system configuration files.
- `apt-get purge mc` removes the package and its associated package configuration files.

Therefore, `purge` performs more complete cleanup than `remove` for package configuration.

**Evidence:** See `images/image3`.

## Task 4: Programs vs Processes

I started a program in the background and used process-listing commands such as `ps` to look for its running process.

A **program** is a file containing instructions that a computer can execute. A **process** is an instance of a program that is currently running.

Before starting the program, its process was not shown in the process listing. While it was running, `ps` showed the corresponding `sleep` process. After the process finished, it no longer appeared in the process listing.

This activity helped me understand that a program is stored on disk, whereas a process represents its execution.

## Task 5: Multitasking

I explored multitasking by running `sleep` processes and checking them with `ps`.

In my recorded result, `ps` showed **1 line containing a `sleep` process**. Although my assigned value was `count = 3`, the recorded output showed only one `sleep` process, so I should not claim that all three were running at the same time.

Multiple independent processes can make progress concurrently. On a multicore processor, some processes may execute simultaneously, while on a single core, the operating system can switch between processes. However, the output of `ps` alone does not prove exactly how CPU time was shared.

**Evidence:** See `images/task5.png`.

## Task 6: Virtualization and Hypervisor Detection

The command outputs indicated that my Ubuntu environment was running inside a **KVM virtual machine**, rather than directly on physical hardware.

The evidence included:

- `systemd-detect-virt` returned `kvm`.
- The hypervisor information showed `Hypervisor vendor: KVM`.
- `uname -r` showed the kernel version `7.0.0-38-generic`.
- `hostname` showed `i4gic-os`.

The `kvm` result and the hypervisor vendor information support the conclusion that the environment was virtualized. The kernel version and hostname provide additional system information but do not independently prove virtualization.

**Evidence:** See `images/task6.png`.

## My Prediction: Confirmed or Corrected

I used `oslab predict lab1` to record my predictions and compare them with the actual observations.

1. **First prediction:** [Write your original prediction.]  
   **Result:** [Confirmed or corrected.] The actual command output showed [briefly describe the evidence].

2. **Second prediction:** [Write your original prediction.]  
   **Result:** [Confirmed or corrected.] The actual command output showed [briefly describe the evidence].

3. **Third prediction — `apt-get remove`:** [Write your original prediction.]  
   **Result:** [Confirmed or corrected.] My Task 3 observation showed that `/etc/mc` still existed after `apt-get remove mc` and was removed after `apt-get purge mc`. Therefore, if I predicted that `remove` would leave the configuration directory, my prediction was confirmed. If I predicted that `remove` would delete it, my prediction was corrected.

## AI Note (Optional)

An AI tool suggested comparing `apt-get remove` with `apt-get purge`. I verified this suggestion by checking whether `/etc/mc` existed after each command. My observations confirmed that `remove` kept the configuration directory in this experiment, while `purge` removed it.
