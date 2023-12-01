/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:14:45 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 12:16:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, char **map, int x, int y)
{
	return (x >= 0
		&& x < game->map->size->x
		&& y >= 0
		&& y < game->map->size->y
		&& map[y][x] != '1'
		&& map[y][x] != 'V');
}

int	ft_is_on_contour(t_game *game, int pos[2])
{
	if (pos[0] == 0 || pos[1] == 0
		|| pos[0] == (game->map->size->y - 1)
		|| pos[1] == (game->map->size->x - 1))
		return (1);
	return (0);
}
