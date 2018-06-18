/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:45:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/09 17:10:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static t_list	*get_buffer(int fd)
{
	static t_list	*links = NULL;
	t_list 			*ret;
	t_buff			*buffer;

	ret = links;
	while (ret)
	{
		if (ret->content_size == fd)
			return (ret);
		ret = ret->next;
	}
	buffer = ft_buffnew(BUFF_SIZE, fd);
	ret = ft_lstnew(0, fd);
	ret->content = buffer;
	ft_lstadd(&links, ret);
	return (ret);
}

static int bufffill(t_buff *buff)
{
	if (ft_buffstat(buff) > 0)
		return (ft_buffstat(buff));
    if (buff->data == NULL)
        buff->data = ft_memalloc(buff->buff_size);
    buff->available = read(buff->meta, buff->data, BUFF_SIZE);
    ft_buffreset(buff);
    return (ft_buffstat(buff));
}


int     get_next_line(int fd, char **line)
{
	t_buff	*buffer;
	t_buff	*line_buffer;
	char	*endl;

	if (fd < 0 || line == NULL || !(buffer = (t_buff *)(get_buffer(fd)->content)))
		return (-1);
	line_buffer = ft_buffnew(0, 0);
	while (bufffill(buffer))
	{	
		buffer->pointer = ft_strchr_n(buffer->pointer, '\n');
		endl = ft_strchr(buffer->pointer,'\n');
		if (endl == 0)
			endl = buffer->pointer + ft_buffstat(buffer);
		ft_buffnap(line_buffer, buffer, ((void *)endl - buffer->pointer));
		buffer->pointer = endl + (*endl == '\n');
		if (*endl == '\n')
			break ;
	}
	printf("^%s&\n", ft_strndup(line_buffer->data, line_buffer->buff_size));
	
	return (0);
}