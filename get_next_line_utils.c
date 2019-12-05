/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:49:58 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/05 13:44:34 by aleon-ca         ###   ########.fr       */
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
		free(mem[fd]);
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

char	*ft_zalloc(int n)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * n);
	if (!result)
		return (0);
	i = -1;
	while (++i < n)
		result[i] = 0;
	return (result);
}
