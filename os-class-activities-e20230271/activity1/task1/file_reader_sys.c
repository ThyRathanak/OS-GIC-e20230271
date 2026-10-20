
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];

    // 1. Open the file for reading
    int fd = open("output.txt", O_RDONLY);

    if (fd == -1) {
        const char *err = "Error opening file\n";
        write(2, err, 19);
        return 1;
    }

    // 2. Read and display until the end of the file
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // 3. Write the bytes to the terminal
        ssize_t totalWritten = 0;

        while (totalWritten < bytesRead) {
            ssize_t n = write(1, buffer + totalWritten,
                              bytesRead - totalWritten);

            if (n <= 0) {
                close(fd);
                return 1;
            }

            totalWritten += n;
        }
    }

    if (bytesRead == -1) {
        const char *err = "Error reading file\n";
        write(2, err, 19);
        close(fd);
        return 1;
    }

    // 4. Close the file
    close(fd);

    return 0;
}
