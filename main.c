#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test", O_RDONLY);
    int count = 0;
    char *line;
    while (get_next_line(fd, &line) > 0)
    {
        //printf("[%i] >> ^%s&\n",fd, line);
        //printf("OK: %i\n",(ft_strcmp("oiuytrew", line)));
        count++;
    }
}