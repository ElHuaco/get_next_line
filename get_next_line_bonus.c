/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:53:32 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/03 11:22:27 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	else
		return (0);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		else
			i++;
	}
	if (c == 0 && str[i] == '\0')
		return (str + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == 0)
			return (0);
		i = -1;
		while (++i < len1)
			str[i] = s1[i];
		j = -1;
		while (++j < len2)
			str[i + j] = s2[j];
		str[i + j] = '\0';
		return (str);
	}
	else
		return (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	if (str)
	{
		dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (dest == 0)
			return (0);
		i = -1;
		while (str[++i])
			dest[i] = str[i];
		dest[i] = '\0';
		return (dest);
	}
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	int				bytes_read;
	static char		*memory[4096];
	char			buff[BUFFER_SIZE + 1];
	char			*nlpos;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (memory[fd] == 0)
		memory[fd] = "";
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		buff[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			memory[fd] = ft_strjoin(memory[fd], buff);
			if ((nlpos = ft_strchr(memory[fd], '\n')))
				return (read_update(fd, memory, nlpos, line));
		}
		else
			return (memread_update(fd, memory, line));
	}
	return (-1);
}
