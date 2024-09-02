#include <stdio.h>
#include <sys/dir.h>
#include <unistd.h>

int main()
{
    execlp("ls", "ls", NULL);
    return 0;
}
