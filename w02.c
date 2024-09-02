#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

void writeDetailsToFile(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error in opening file\n");
    }

    char name[256];
    char age[10];
    char rollNo[10];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter age: ");
    fgets(age, sizeof(age), stdin);
    printf("Enter roll number: ");
    fgets(rollNo, sizeof(rollNo), stdin);

    fprintf(file, "Name: %s", name);
    fprintf(file, "Age: %s", age);
    fprintf(file, "Roll Number: %s", rollNo);
    fclose(file);
}

int main() {
    // program 1
    DIR *d;
    struct dirent *dir;
    const char *path = ".";
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        printf("Error in opening directory\n");
    }

    // program 2
    execlp("ls", "ls", NULL);

    // program 3
    writeDetailsToFile("usr.txt");
    writeDetailsToFile("frnd.txt");
    pid_t pid = fork();
    if (!pid) {
        execlp("grep", "grep", "-f", "usr.txt", "frnd.txt", NULL);
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        printf("Error in creating child process\n");
    }
    return 0;
}