#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test", O_RDONLY);
    int fd2 = open("test", O_RDONLY);
    int count = 0;
    char *line;
    printf("%i >> \n", fd);
    int x = 0;
    while (get_next_line(fd, &line) > 0 && x < 220)
    {
        printf("[%i][%i]\t^%s&\n", fd, x, line);
        get_next_line(fd2, &line);
        printf("[%i][%i] ^%s&\n", fd2, x, line);
        free(line);
        x++;
    }
}