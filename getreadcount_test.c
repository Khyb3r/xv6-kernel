#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]) {
    char buffer[10];
    int before_count = getreadcount();
    
    for (int i = 0; i < 3; i++) {
        read(0, buffer, sizeof(buffer));
    }

    int after_count = getreadcount();
    printf(1, "Count before: %d\n", before_count);
    printf(1, "Count after: %d\n", after_count);
    exit();
}
