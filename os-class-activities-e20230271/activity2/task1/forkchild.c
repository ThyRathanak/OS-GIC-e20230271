
/* forkchild.c - Process creation with fork() and exec() */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;

    printf("Parent process (PID: %d) - creating child...\n", getpid());
    fflush(stdout);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        /* Child process */
        printf("Child process (PID: %d, Parent PID: %d)\n",
               getpid(), getppid());

        printf("Child: sleeping 30 seconds...\n");
        fflush(stdout);

        sleep(30);

        printf("Child: now executing 'ls -la'...\n");
        fflush(stdout);

        /* Replace child program with ls */
        execlp("ls", "ls", "-la", (char *)NULL);

        /* Reached only if execlp fails */
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        /* Parent process */
        int status;

        printf("Parent: waiting for child (PID: %d) to finish...\n", pid);
        fflush(stdout);

        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Parent: child exited with status %d\n",
                   WEXITSTATUS(status));
        }

        printf("Parent: done.\n");
    }

    return 0;
}
