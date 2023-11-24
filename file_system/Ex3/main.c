#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

 
int main(int argc , char *argv[]){
    struct stat file_stat;
    if (argc != 2){
        fprintf(stderr, "Usage : %s <file>\n",argv[0]);
        return 1;
    }
    if(stat(argv[1], &file_stat) == -1){
        fprintf(stderr, "Cannot read file %s : %s\n", argv[1],strerror(errno));
      return errno;

    }

printf("File Name: test.txt\n");
printf("File type:  ");
switch (file_stat.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("File Last Modification: %s", ctime(&file_stat.st_mtime));
    printf("File size: %jd bytes\n\n", file_stat.st_size);

    return 0;
}
