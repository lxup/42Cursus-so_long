/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:17 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/30 20:29:37 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1048576
# endif

typedef struct s_lines
{
	char			*content;
	struct s_lines	*next;
}	t_lines;

char	*get_next_line(int fd);
void	ft_lstfree(t_lines *list);

void	ft_get_line(t_lines *list, char **line);

// Utils
int		ft_lstchr(t_lines *stash, char c);
t_lines	*ft_lstlast_gnl(t_lines *lst);

#endif