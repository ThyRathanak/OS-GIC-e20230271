
/* shm-consumer.c - Reads from POSIX shared memory */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    const int SIZE = 4096;
    const char *name = "/OS-thyrathanak";

    int shm_fd = shm_open(name, O_RDONLY, 0666);

    if (shm_fd == -1) {
        perror("shm_open");
        fprintf(stderr, "Hint: Did you run the producer first?\n");
        return EXIT_FAILURE;
    }

    char *ptr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        close(shm_fd);
        return EXIT_FAILURE;
    }

    printf("Consumer: reading from shared memory '%s'\n", name);
    printf("Consumer: message = \"%s\"\n", ptr);

    munmap(ptr, SIZE);
    close(shm_fd);

    if (shm_unlink(name) == -1) {
        perror("shm_unlink");
        return EXIT_FAILURE;
    }

    printf("Consumer: shared memory unlinked.\n");

    return EXIT_SUCCESS;
}
