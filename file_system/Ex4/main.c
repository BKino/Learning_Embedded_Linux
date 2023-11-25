#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd, wr;
    char buff[14] = "test O_APPEND";

    fd = open("test.txt",O_RDWR | O_APPEND, 0777);
    if (fd == -1)
    {
        printf("open() file test.txt failed\n");
    }

    lseek(fd, 0, SEEK_SET);
    wr = write(fd, buff, strlen(buff));
    if (wr == -1)
    {
        printf("write() file text.txt failed\n");
    }
    close(fd);
}
    


