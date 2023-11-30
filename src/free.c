/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:18:34 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/30 22:07:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[0] && matrix[0][i])
	{
		free(matrix[0][i]);
		i++;
	}
	if (matrix && matrix[0])
		free(matrix[0]);
	matrix = NULL;
}

void	ft_free_map(t_map *map)
{
	if (map->items)
		ft_lstclear(&map->items, free);
	if (map->size)
		free(map->size);
	free(map);
}
// void	ft_free_map(t_map *map)
// {
// 	if (map->items)
// 		ft_free_matrix(&map->items);
// 	if (map->size)
// 		free(map->size);
// 	free(map);
// }

void	ft_free_player(t_char *player)
{
	if (player->position)
		free(player->position);
	free(player);
}

void	ft_free_game(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	if (game->player)
		ft_free_player(game->player);
		// ft_lstclear(&game->map, free);
	free(game);
}