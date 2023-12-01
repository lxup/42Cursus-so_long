/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:48:47 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 14:10:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

char	**ft_copy_matrix(char **matrix)
{
	char	**new_matrix;
	int		y;

	new_matrix = malloc(sizeof(char *) * (ft_get_matrix_size(matrix) + 1));
	if (!new_matrix)
		return (NULL);
	y = 0;
	while (matrix && matrix[y])
	{
		new_matrix[y] = ft_strdup(matrix[y]);
		if (!new_matrix[y])
			return (ft_free_matrix_with_indice(new_matrix, y), NULL);
		y++;
	}
	return (new_matrix);
}

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd((char *)lst->content, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

void	ft_matrixprint(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		ft_putstr_fd(matrix[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
