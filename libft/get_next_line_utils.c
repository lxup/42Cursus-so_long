/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:13 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 11:00:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lines	*ft_lstlast_gnl(t_lines *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_create_line(t_lines *list, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 1));
}

void	ft_get_line(t_lines *list, char **line)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	ft_create_line(list, line);
	if (*line == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break ;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

int	ft_lstchr(t_lines *stash, char c)
{
	int		i;
	t_lines	*current;

	if (stash == NULL)
		return (0);
	current = ft_lstlast_gnl(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_lstfree(t_lines *list)
{
	t_lines	*current;
	t_lines	*backup;

	current = list;
	while (current)
	{
		free(current->content);
		backup = current->next;
		free(current);
		current = backup;
	}
}
