/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:11:50 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/03 15:11:53 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		memread_update(int fd, char **mem, char **line)
{
	char		*nlpos;

	if ((nlpos = ft_strchr(mem[fd], '\n')))
		return (read_update(fd, mem, nlpos, line));
	else
	{
		*line = ft_strdup(mem[fd]);
		mem[fd] = 0;
	}
	return (0);
}

int		read_update(int fd, char **mem, char *nlpos, char **line)
{
	char	*temp;

	*nlpos = '\0';
	*line = ft_strdup(mem[fd]);
	temp = ft_strdup(mem[fd] + ft_strlen(*line) + 1);
	free(mem[fd]);
	mem[fd] = temp;
	return (1);
}

void	mem_update(int fd, char **mem, char *buff)
{
	char	*temp;

	temp = ft_strjoin(mem[fd], buff);
	free(mem[fd]);
	mem[fd] = temp;
}
