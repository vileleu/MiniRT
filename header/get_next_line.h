/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:03:21 by vileleu           #+#    #+#             */
/*   Updated: 2019/11/25 15:23:22 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
char			**ft_strjoin(char **s1, char *s2, int i);
char			*ft_strdup(const char *s1);
t_list			*findfd(t_list **begin, int fd);
int				free_fd(t_list **begin, int fd);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
