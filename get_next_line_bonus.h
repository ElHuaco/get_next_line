/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:11:46 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/12/04 12:11:47 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifdef BUFFER_SIZE
#  define B_S BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
int					ft_strlen(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *str, int c);
char				*ft_strdup(char *str);
int					memread_update(int fd, char **mem, char **line, char *buf);
int					read_update(int fd, char **mem, char *n, char **line);
void				mem_update(int fd, char **mem, char *buff);
char				*ft_zalloc(int n);
#endif
