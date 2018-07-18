#include <stdio.h>
#include <stdlib.h>
#include <tlpi_hdr.h>

int main()
{
    int fd; 
    char temp[] = "/tmp/hello_qeesungXXXXXX";

    fd = mkstemp(temp);
    if(fd == -1) {
        errExit("mkstemp");
    }

    printf("Generated file is %s\n", temp);

    unlink(temp);
    if(close(fd) == -1) {
        errExit("close");
    }
    exit(EXIT_SUCCESS);
}
