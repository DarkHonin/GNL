/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:45:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/30 14:34:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_list	*get_buffer(int fd, t_list **links)
{
	t_list	*ret;

	ret = *links;
	while (ret)
	{
		if (ret->next == *links)
		{
			ret = NULL;
			break ;
		}
		if (((t_buff *)ret->content)->meta == fd)
			return (ret);
		ret = ret->next;
	}
	ret = ft_lstnew(NULL, 0);
	ret->content = ft_buffnew(BUFF_SIZE, fd);
	ret->content_size = fd;
	ft_lstadd(links, ret);
	return (ret);
}

static int		bufffill(t_buff *buff)
{
	if (ft_buffstat(buff) > 0 && ft_buffstat(buff) < BUFF_SIZE)
		return (ft_buffstat(buff));
	if (buff->data == NULL)
		buff->data = ft_memalloc(buff->buff_size);
	ft_bzero(buff->data, BUFF_SIZE);
	buff->available = read(buff->meta, buff->data, BUFF_SIZE);
	ft_buffreset(buff);
	return (buff->available);
}

static void		dellink(t_list **link, t_list **links)
{
	t_list *last;
	t_list *current;

	current = *links;
	last = NULL;
	while (current)
	{
		if (current == *link)
			break ;
		last = current;
		current = current->next;
	}
	if ((*link) != *links)
	{
		last->next = (*link)->next;
	}
	else
		*links = NULL;
	ft_buffdel((*link)->content);
	free(*link);
	*link = NULL;
}

static int		slice_line(t_buff *line_buffer,
			t_list **links, t_list *link, char **line)
{
	int data_read;

	data_read = ((t_buff *)link->content)->available;
	if (line_buffer->data != NULL && *((char *)line_buffer->data))
	{
		*line = ft_strnew(line_buffer->buff_size);
		ft_memcpy(*line, line_buffer->data, line_buffer->buff_size);
	}
	else
		*line = ft_strnew(0);
	ft_buffdel(line_buffer);
	if (data_read <= 0)
		dellink(&link, links);
	if (data_read < 0)
		return (-1);
	return (data_read || (**line));
}

int				get_next_line(int fd, char **line)
{
	static t_list	*links = NULL;
	t_list			*link;
	t_buff			*bu;
	t_buff			*lb;
	char			*endl;

	if (fd < 0 || line == NULL || !(link = get_buffer(fd, &links)))
		return (-1);
	bu = (t_buff *)link->content;
	lb = ft_buffnew(0, 0);
	while (bufffill(bu) > 0)
	{
		endl = (char *)ft_memchr(bu->pointer, '\n', ft_buffstat(bu));
		if (endl == 0)
			endl = bu->pointer + ft_buffstat(bu);
		ft_buffnap(lb, bu, ((void *)endl - bu->pointer));
		bu->pointer += ((void *)endl - bu->pointer) + (*endl == '\n');
		if (*endl == '\n')
			break ;
	}
	return (slice_line(lb, &links, link, line));
}
