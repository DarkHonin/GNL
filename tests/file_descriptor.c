#include <get_next_line.h>
#include <libtest.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
int main(void)
{
    int fd3 = open("simple", O_RDONLY);
    char *line = NULL;
    while(get_next_line(fd3, &line) > 0)
    {
        ft_putendl(line);
        if(line != NULL)
            free(line);
        line = NULL;
    }
/*
    while(1)
    {


    }


    ft_putendl("=========================================");

    t_list *links = NULL;
    t_list *link;
    t_list *link2;
    t_list *link3;

    char *simple[3] = {
        "This is a simple file that should have things inside of it",
        "line a new line",
        "that isnt verry long but should work"
    };
    char *single = "thisvisq";
    int resp[4] = {
        1,
        1,
        1,
        0
    };
    char *line = NULL;
    int response;
    int fd1 = open("simple", O_RDONLY);
    int fd2 = open("empty", O_RDONLY);
    int fd3 = open("test2", O_RDONLY);

    link = get_buffer(fd1, &links);
    link2 = get_buffer(fd2, &links);
    link3 = get_buffer(fd3, &links);
    t_list *link4 = get_buffer(0, &links);
    t_list *link5 = get_buffer(1, &links);
    dellink(&link4, &links);
    dellink(&link5, &links);
    test("Comparing file descriptors #1: ", MK_T_INT(link->content_size), MK_T_INT(fd1));
    test("Comparing file descriptors #1: ", MK_T_INT(((t_buff *)link->content)->meta), MK_T_INT(fd1));
    test("Comparing file descriptors #2: ", MK_T_INT(link2->content_size), MK_T_INT(fd2));
    test("Comparing file descriptors #3: ", MK_T_INT(link3->content_size), MK_T_INT(fd3));

    int index = 0;

    while((response = get_next_line(fd1, &line)))
    {
        ft_putnbr(index);
        ft_putstr("Got >> ");
        ft_putendl(line);
        test("Attempted to read simple: ", MK_T_INT(response), MK_T_INT(resp[index]));
        test("Checking returned line: ", MK_T_PNTR(line, ft_strlen(line)), MK_T_PNTR(simple[index], ft_strlen(simple[index])));
        if (line != NULL)
            free(line);
        index++;
    }
    ft_putendl("Loop finished");
    fd1 = open("simple", O_RDONLY);
    test("last response to read simple: ", MK_T_INT(response), MK_T_INT(resp[index]));

    response = get_next_line(fd2, &line);
    test("response to read empty: ", MK_T_INT(response), MK_T_INT(resp[index]));
    if(line != NULL)
        free(line);
    line = NULL;
    while((response = get_next_line(fd3, &line)))
    {
        test("response to read single: ", MK_T_INT(response), MK_T_INT(resp[0]));
        test("Checking returned line: ", MK_T_PNTR(line, ft_strlen(line)), MK_T_PNTR(single, ft_strlen(single)));
        if (line != NULL)
            free(line);
    }
    test("response to read single: ", MK_T_INT(response), MK_T_INT(resp[3]));
*/
}