#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test2", O_RDONLY);
    int fd2 = open("test", O_RDONLY);
    int count = 0;
    char *line;
    printf("%i >> \n", fd);
    get_next_line(fd, &line);
    get_next_line(fd2, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd2, &line);
}