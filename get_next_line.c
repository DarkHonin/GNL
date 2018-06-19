/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:45:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/19 15:27:23 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

t_list	*get_buffer(int fd, t_list **links)
{
	t_list 			*ret;

	ret = *links;
	while (ret)
	{
		if (ret->content_size == (size_t)fd)
			return (ret);
		ret = ret->next;
	}
	ret = ft_lstnew(0, fd);
	ret->content = ft_buffnew(BUFF_SIZE, fd);
	ret->content_size = fd;
	if (*links == NULL)
		*links = ret;
	else
		ft_lstadd(links, ret);
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
    return (buff->available);
}

static void dellink(t_list **link, t_list *links)
{
	t_list *patch_parent;

	ft_buffdel((t_buff *)(*link)->content);
	patch_parent = links;
	while (patch_parent->next && patch_parent->next != *link)
		patch_parent = patch_parent->next;
	patch_parent->next = (*link)->next;
}

int     get_next_line(int fd, char **line)
{
	static t_list	*links;
	t_list	*link;
	t_buff	*buffer;
	t_buff	*line_buffer;
	char	*endl;

	if (fd < 0 || line == NULL || !(link = get_buffer(fd, &links)))
		return (-1);
	buffer = (t_buff *)link->content;
	line_buffer = ft_buffnew(0, 0);
	while (bufffill(buffer) > 0)
	{
		buffer->pointer = ft_memchr_n(buffer->pointer, '\n', ft_buffstat(buffer));
		endl = (char *)ft_memchr(buffer->pointer,'\n',ft_buffstat(buffer));
		if (endl == 0)
			endl = buffer->pointer + ft_buffstat(buffer);
		ft_buffnap(line_buffer, buffer, ((void *)endl - buffer->pointer));
		buffer->pointer += ((void *)endl - buffer->pointer) + (*endl == '\n');
		if (*endl == '\n')
			break ;
	}
	if (line_buffer->buff_size > 0)
		*line = ft_strndup(line_buffer->data, line_buffer->buff_size);
	else
		*line = ft_strnew(0);
	ft_buffdel(line_buffer);
	if (buffer->available < 0)
	{
		dellink(&link, links);
		return (-1);
	}
	return (buffer->available > 0 || ft_strlen(*line) > 0);
}