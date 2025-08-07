#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char *argv[]) {
    char buffer[5];
    int fd;
    int before_count = getreadcount();

    // Open an existing file (like README or any file in the filesystem)
    fd = open("README", O_RDONLY);
    if (fd < 0) {
        printf(1, "Failed to open README\n");
        exit();
    }

    // Read 3 times from the same file
    for (int i = 0; i < 3; i++) {
        read(fd, buffer, sizeof(buffer));
    }

    close(fd);

    int after_count = getreadcount();
    printf(1, "Count before: %d\n", before_count);
    printf(1, "Count after: %d\n", after_count);
    exit();
}
