#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

int main(int argc, char *argv[])
{
    int fd; 
    struct iovec iov[3];
    struct stat myStruct;
    int x;

    #define STR_SIZE 100
    char str[STR_SIZE];
    ssize_t numRead, toRequired;

    if(argc != 2 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s file\n", argv[0]);
    }

    fd = open(argv[1], O_RDONLY);
    while(1);
    if(fd == -1) {
        errExit("open");
    }

    toRequired = 0;
    iov[0].iov_base = &myStruct;
    iov[0].iov_len = sizeof(struct stat);
    toRequired += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    toRequired += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = STR_SIZE;
    toRequired += iov[2].iov_len;

    numRead = readv(fd, iov, 3);
    if(numRead == -1) {
        errExit("readv");
    }

    if(numRead < toRequired) {
        printf("Read fewer bytes than requsted\n");
    }

    printf("total requested read %ld, bytes read: %ld \n", toRequired, numRead);

    exit(EXIT_SUCCESS);
}
