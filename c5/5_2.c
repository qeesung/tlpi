#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

int main()
{
    // open the file
    int fd = open("./test_file", O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR) ;
    if(fd == -1) {
        errExit("open");
    }

    // get the current offset
    off_t currentOffset = lseek(fd, 0, SEEK_CUR);
    if(currentOffset == -1) {
        errExit("lseek current offset");
    }
    printf("current offset is %ld\n", (long)currentOffset);

    // set the offset to the header
    off_t newOffset = lseek(fd, 0, SEEK_SET);
    if(newOffset == -1) {
            errExit("lseek new offset");
    }

    // write some thing to the buffer;
    char buffer[] = "Hello World";
    ssize_t numToWrite = sizeof(buffer)/sizeof(buffer[0]);
    ssize_t numWrited = write(fd, buffer, numToWrite);
    if(numWrited == -1) {
        errExit("write");
    }

    currentOffset = lseek(fd, 0, SEEK_CUR);
    if(currentOffset == -1) {
        errExit("lseek current offset");
    }
    printf("current offset is %ld\n", (long)currentOffset);

    if(numWrited != numToWrite) {
        printf("can not wirte all data！");
    }

    if(close(fd) == -1) {
        errExit("clsoe");
    }
    return 0;
}
