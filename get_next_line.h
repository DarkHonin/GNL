/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 06:33:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/24 09:40:05 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 	255

# include "libft.h"

int		get_next_line(const int fd, char **line);
t_list	*get_buffer(int fd, t_list **links);
void	dellink(t_list **link, t_list **links);

#endif
