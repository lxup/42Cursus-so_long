/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:41:39 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 12:56:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_life(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->player->life)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures->heart_full.img, \
		INTERFACE_SIZE + 167 + (i * 32), 0);
		i++;
	}
	while (i < LIFE_COUNT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures->heart_empty.img, \
		INTERFACE_SIZE + (i * 15), 0);
		i++;
	}
}

void	ft_render_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->player->moves_count);
	if (!movements)
		ft_exit(game, MEMORY_ERR, NULL);
	phrase = ft_strjoin("Movements : ", movements);
	if (!phrase)
		ft_exit(game, MEMORY_ERR, NULL);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 11001101, phrase);
	free(movements);
	free(phrase);
}

void	ft_render_interface(t_game *game)
{
	ft_render_movements(game);
	ft_render_life(game);
}
