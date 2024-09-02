#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t id = fork();
    
    // program 1 
    if (!id) {
        printf("Child process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());
    } else if (id > 0) {
        printf("Parent process id: %d\n", getpid());
    } else {
        printf("Error in creating child process\n");
    }

    // program 2
    if (!id) {
        printf("Child process id: %d\n", getpid());
        printf("Parent process id (from child): %d\n", getppid());
    } else if (id > 0) {
        printf("Parent process id: %d\n", getpid());
        printf("Child process id (from parent): %d\n", id);
        wait(NULL);
    } else {
        printf("Error in creating child process\n");
    }

    // program 3
    if (!id) {
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