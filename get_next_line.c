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

static int     create_buffer(t_buff **buff)
{
	if (!(*buff))
		*buff = ft_buffnew(BUFF_SIZE, 0);
	if (!*buff)
		return (0);
	return (1);
}

static int	maintain_buff(t_buff *buff, int fd)
{
	int avail = ft_buffstat(buff);
	if (ft_buffstat(buff) <= 0)
	{
		ft_buffreset(buff);
		avail = read(fd, buff->data, BUFF_SIZE);
		if (avail <= 0)
			buff->buff_size = 0;
		else
			buff->buff_size = avail;
		return (avail);
	}
	return (ft_buffstat(buff));
}

int     get_next_line(int fd, char **line)
{
	static t_buff	*buffer = NULL;
	int				avail;
	char			*line_end;
	t_buff			*line_buffer;
	int				bytes_handled;

	if (fd < 0 || line == NULL || !create_buffer(&buffer))
		return (-1);
	bytes_handled = 0;
	line_buffer = ft_buffnew(0,1);
	ft_buffreset(line_buffer);
	while ((avail = maintain_buff(buffer, fd)) > 0)
	{
		if (avail <= 0)
			break;
		//printf("--------------------------------------\n");
		//printf("Data currently in buffer: %i\n", avail);
		//printf("Line starts: [%i] %p\n", avail, buffer->pointer);
		line_end = ft_memchr(buffer->pointer, '\n', avail);
		if (line_end != 0)
			avail = line_end - (char *)buffer->pointer - 1;
		//printf("Line ends: [%i] %p\n", avail, line_end);
		//printf("Chars to handle: %i\n", avail);
		ft_buffnap(line_buffer, buffer, avail + (line_end != 0));
		//printf("Line: %s\n", line_buffer->data);
		buffer->pointer += avail + ((line_end != 0) * 2);
		bytes_handled += avail + ((line_end != 0) * 2);
		if (line_end != 0)
			break ;
	}
	//printf("Available after loop: %i\nBytes handled: %i\n", avail, bytes_handled);
	*line = ft_strndup(line_buffer->data, line_buffer->buff_size);
	//printf("Freeing line buffer\n");
	ft_buffdel(line_buffer);
	if (avail <= 0 && bytes_handled == 0)
	{
		//printf("Freeing file buffer\n");
		if (buffer != NULL)
			ft_buffdel(buffer);
		buffer = NULL;
		//printf("BITCH");
		return (avail);
	}
	return (1);
}