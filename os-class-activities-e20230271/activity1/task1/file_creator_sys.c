
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *text = "Hello from Operating Systems class!\n";
    const char *msg = "File created successfully!\n";

    // 1. Create the file or clear existing content
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        const char *err = "Error opening file\n";
        write(2, err, strlen(err));
        return 1;
    }

    // 2. Write text into the file
    if (write(fd, text, strlen(text)) == -1) {
        const char *err = "Error writing file\n";
        write(2, err, strlen(err));
        close(fd);
        return 1;
    }

    // 3. Close the file
    if (close(fd) == -1) {
        const char *err = "Error closing file\n";
        write(2, err, strlen(err));
        return 1;
    }

    // 4. Print confirmation to the terminal
    write(1, msg, strlen(msg));

    return 0;
}
