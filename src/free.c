/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:18:34 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/02 02:09:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	if (map->items)
		ft_free_matrix(map->items);
	if (map->size)
		free(map->size);
	if (map->fd > 0)
		close(map->fd);
	free(map);
}

void	ft_free_player(t_game *game)
{
	if (game->player)
	{
		if (game->player->sprite_front.img)
			mlx_destroy_image(game->mlx_ptr, game->player->sprite_front.img);
		if (game->player->sprite_back.img)
			mlx_destroy_image(game->mlx_ptr, game->player->sprite_back.img);
		if (game->player->sprite_left.img)
			mlx_destroy_image(game->mlx_ptr, game->player->sprite_left.img);
		if (game->player->sprite_right.img)
			mlx_destroy_image(game->mlx_ptr, game->player->sprite_right.img);
		free(game->player);
	}
}

void	ft_free_textures(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->wall.img)
			mlx_destroy_image(game->mlx_ptr, game->textures->wall.img);
		if (game->textures->floor.img)
			mlx_destroy_image(game->mlx_ptr, game->textures->floor.img);
		if (game->textures->coins.img)
			mlx_destroy_image(game->mlx_ptr, game->textures->coins.img);
		if (game->textures->exit_open.img)
			mlx_destroy_image(game->mlx_ptr, game->textures->exit_open.img);
		if (game->textures->exit_closed.img)
			mlx_destroy_image(game->mlx_ptr, game->textures->exit_closed.img);
		free(game->textures);
	}
}

void	ft_free_game(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	if (game->player)
		ft_free_player(game);
	if (game->textures)
		ft_free_textures(game);
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		// mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}
