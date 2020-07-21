/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:55:17 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:01:05 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

int		cutstr(t_list *lst, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (lst->str[i] != '\0')
	{
		if (lst->str[i] == '\n')
		{
			if (!(line = ft_strjoin(line, lst->str, i)) ||
			!(temp = ft_strdup(lst->str + i + 1)))
				return (-1);
			free(lst->str);
			if (!(lst->str = ft_strdup(temp)))
				return (-1);
			free(temp);
			return (1);
		}
		i++;
	}
	if (!(line = ft_strjoin(line, lst->str, i)))
		return (-1);
	free(lst->str);
	lst->str = NULL;
	return (0);
}

int		finish(t_list **begin)
{
	t_list *tmp;

	tmp = *begin;
	while (*begin != NULL)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		if (tmp->str != NULL)
			free(tmp->str);
		free(tmp);
	}
	return (-1);
}

int		rdfile(char *str, int fd)
{
	int rd;

	rd = read(fd, str, BUFFER_SIZE);
	if (rd > 0)
		str[rd] = '\0';
	return (rd);
}

int		get_next_line(int fd, char **line)
{
	int				rd;
	char			str[BUFFER_SIZE + 1];
	static t_list	*begin;
	t_list			*lst;

	if (!line || read(fd, str, 0) < 0 || !(lst = findfd(&begin, fd)))
		return (finish(&begin));
	line[0] = ft_strdup("");
	while (1)
	{
		if (lst->str == NULL)
		{
			rd = rdfile(str, fd);
			if (rd == 0)
				return (free_fd(&begin, fd));
			if (rd == -1 || !(lst->str = ft_strdup(str)))
				return (finish(&begin));
		}
		rd = cutstr(lst, line);
		if (rd == -1)
			return (finish(&begin));
		else if (rd == 1)
			break ;
	}
	return (1);
}
