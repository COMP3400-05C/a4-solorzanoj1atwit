#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>      
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/wait.h> 

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        puts("ERROR: no arguments");
        return 1;
    }
    if (argc != 3) {
        puts("USAGE: ./partc <word> <File>");
        return 1;
    }

    const char *wrd = argv[1];
    const char *fl = argv[2];

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char *eargs[] = {"grep", "-s", "-q", (char *)wrd, (char *)fl, NULL};
        execv("/usr/bin/grep", eargs);
        perror("exec");
        _exit(127);
    }
    int status = 0;
    if (waitpid(pid, &status, 0) < 0) {
        perror("wait");
        return 1;
    }

    if (WIFEXITED(status)) {
        int code = WEXITSTATUS(status);
        if (code == 0) {
            printf("FOUND: %s\n", wrd);
            return 0;
        } else if (code == 1) {
            printf("NOT FOUND: %s\n", wrd);
            return 0;
        } else { 
            printf("ERROR: %s doesn't exist\n", fl);
            return 2;
        }
    }

    puts("ERROR");
    return 2;
}