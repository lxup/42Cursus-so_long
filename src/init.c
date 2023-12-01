/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:24:36 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 15:39:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_char	*ft_init_player(t_game *game)
{
	t_char	*player;

	player = (t_char *)malloc(sizeof(t_char));
	if (!player)
		return (ft_exit(game, MEMORY_ERR, NULL));
	player->position = (t_vector *)malloc(sizeof(t_vector));
	if (!player->position)
		return (ft_exit(game, MEMORY_ERR, NULL));
	player->position->x = 0;
	player->position->y = 0;
	return (player);
}

t_map	*ft_init_map(t_game *game)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_exit(game, MEMORY_ERR, NULL));
	map->size = (t_vector *)malloc(sizeof(t_vector));
	if (!map->size)
		return (ft_exit(game, MEMORY_ERR, NULL));
	map->size->x = 0;
	map->size->y = 0;
	map->e_count = 0;
	map->p_count = 0;
	map->c_count = 0;
	map->items = NULL;
	return (map);
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (ft_exit(NULL, MEMORY_ERR, NULL));
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	return (game);
}

t_game	*ft_init(void)
{
	t_game	*game;

	game = ft_init_game();
	game->map = ft_init_map(game);
	game->player = ft_init_player(game);
	return (game);
}
