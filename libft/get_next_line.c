/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:20 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/30 20:29:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_back_gnl(t_lines **list, char *buffer, int bytes_read)
{
	int		i;
	t_lines	*last;
	t_lines	*new;

	new = (t_lines *)malloc(sizeof(t_lines));
	if (new == NULL)
		return ;
	new->content = malloc(sizeof(*buffer) * (bytes_read + 1));
	if (new->content == NULL)
		return ;
	new->next = NULL;
	i = 0;
	while (buffer[i] && i < bytes_read)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (*list == NULL)
		*list = new;
	else
	{
		last = ft_lstlast_gnl(*list);
		last->next = new;
	}
}

static void	ft_lstclean(t_lines **list)
{
	int		i;
	int		j;
	t_lines	*last;
	t_lines	*clean;

	clean = (t_lines *)malloc(sizeof(t_lines));
	if (list == NULL || clean == NULL)
		return (ft_lstfree(clean));
	clean->next = NULL;
	last = ft_lstlast_gnl(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) *((ft_strlen(last->content) - i) + 1));
	if (clean->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	ft_lstfree(*list);
	*list = clean;
}

static void	ft_init(int fd, t_lines **list, int *bytes_read)
{
	char	*buffer;

	while (!ft_lstchr(*list, '\n') && *bytes_read != 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		*bytes_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && *bytes_read == 0) || *bytes_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*bytes_read] = '\0';
		ft_lstadd_back_gnl(list, buffer, *bytes_read);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_lines	*list[FD_SIZE];
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || (int)read(fd, &line, 0) < 0)
		return (NULL);
	bytes_read = 1;
	line = NULL;
	ft_init(fd, &list[fd], &bytes_read);
	if (list[fd] == NULL)
		return (NULL);
	ft_get_line(list[fd], &line);
	ft_lstclean(&list[fd]);
	if (*line == '\0')
	{
		ft_lstfree(list[fd]);
		list[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
