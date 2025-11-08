#include <stdbool.h>
#include <stddef.h>
#include <unistd.h> 
#include <stdio.h> 

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        const char msg[] = "ERROR: no arguments\n";
        (void)write(1, msg, sizeof(msg) - 1);
        return 1;
    }

    int args = argc - 1;
    char *eargs_odd[3];
    char *eargs_even[4];
    char **midArgs = NULL;

    if (args % 2 == 1) {
        int mid = 1 + (args / 2);
        eargs_odd[0] = "echo";
        eargs_odd[1] = (char *)argv[midArg];
        eargs_odd[2] = NULL;
        midArgs = eargs_odd;
    } else {
        int midArg1 = 1 + (args / 2) - 1;
        int midArg2 = mid1 + 1;        
        eargs_even[0] = "echo";
        eargs_even[1] = (char *)argv[midArg1];
        eargs_even[2] = (char *)argv[midArg2];
        eargs_even[3] = NULL;
        midArgs = eargs_even;
    }

    if (execv("/bin/echo", midArgs) == -1) {
        perror("exec");
        return 1;
    }
    return 0;
}