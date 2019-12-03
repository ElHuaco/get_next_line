/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:12:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/03 15:12:17 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
int					ft_strlen(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *str, int c);
char				*ft_strdup(char *str);
int					memread_update(int fd, char **mem, char **line);
int					read_update(int fd, char **mem, char *n, char **line);
void				mem_update(int fd, char **mem, char *buff);
#endif
