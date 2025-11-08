#include <stdbool.h>
#include <stddef.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        printf("ERROR: NO ARGUMENTS");
        return;
    }

    char* str = argv[1];
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }

    printf("%s", str);
    return 0;
}
