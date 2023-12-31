/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:48:47 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 19:56:44 by lquehec          ###   ########.fr       */
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

	if (!matrix)
		return (NULL);
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
	new_matrix[y] = NULL;
	return (new_matrix);
}

void	ft_free_matrix_with_indice(char **matrix, int i)
{
	while (i > 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
