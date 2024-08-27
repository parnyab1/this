#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t id = fork();
    if (id == 0) {
        printf("Child process id: %d\n", getpid());
        execlp("ls", "ls", "-R", "/", NULL);
    } else if (id > 0) {
        printf("Parent process id: %d\n", getpid());
        wait(NULL);
        printf("Child process finished execution.\n");
    } else {
        printf("Error in creating child process\n");
    }
    return 0;
}
