/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:24:36 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 11:47:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_game *game)
{
	game->player = malloc(sizeof(t_char));
	if (!game->player)
		ft_exit(game, MEMORY_ERR, NULL);
	game->player->sprite_front.img = NULL;
	game->player->sprite_back.img = NULL;
	game->player->sprite_left.img = NULL;
	game->player->sprite_right.img = NULL;
	game->player->direction = 1;
	game->player->position.x = 0;
	game->player->position.y = 0;
	game->player->moves_count = 0;
	game->player->life = LIFE_COUNT;
}

void	ft_init_textures(t_game *game)
{
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game->textures)
		ft_exit(game, MEMORY_ERR, NULL);
	game->textures->wall.img = NULL;
	game->textures->floor.img = NULL;
	game->textures->coins.img = NULL;
	game->textures->exit_open.img = NULL;
	game->textures->exit_closed.img = NULL;
	game->textures->heart_full.img = NULL;
	game->textures->heart_empty.img = NULL;
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
	map->fd = 0;
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
	game->player = NULL;
	game->textures = NULL;
	game->moves[0][0] = -1;
	game->moves[0][1] = 0;
	game->moves[1][0] = 1;
	game->moves[1][1] = 0;
	game->moves[2][0] = 0;
	game->moves[2][1] = -1;
	game->moves[3][0] = 0;
	game->moves[3][1] = 1;
	return (game);
}

t_game	*ft_init(void)
{
	t_game	*game;

	game = ft_init_game();
	game->map = ft_init_map(game);
	ft_init_player(game);
	ft_init_textures(game);
	return (game);
}
