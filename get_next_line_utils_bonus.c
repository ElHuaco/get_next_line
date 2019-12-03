/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:49:58 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/03 11:22:36 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		memread_update(int fd, char **mem, char **line)
{
	char		*nlpos;

	if ((nlpos = ft_strchr(mem[fd], '\n')))
		return (read_update(fd, mem, nlpos, line));
	else
	{
		*line = ft_strdup(mem[fd]);
		mem[fd] = "";
	}
	return (0);
}

int		read_update(int fd, char **mem, char *nlpos, char **line)
{
	*nlpos = '\0';
	*line = ft_strdup(mem[fd]);
	mem[fd] = nlpos + 1;
	return (1);
}
