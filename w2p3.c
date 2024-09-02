#include <stdio.h>
#include <sys/dir.h>
#include <unistd.h>
#include <stdlib.h>

void writeDetailsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char details[256];
    printf("Enter details for %s: ", filename);
    fgets(details, sizeof(details), stdin);
    fprintf(file, "%s", details);
    fclose(file);
}

int main()
{
    writeDetailsToFile("user_details.txt");
    writeDetailsToFile("friend_details.txt");
    execlp("grep", "grep", "-Fxf", "user_details.txt", "friend_details.txt", NULL);
    return 0;
}
