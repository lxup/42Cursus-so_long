/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:41:39 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 18:49:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_render_life(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->player->life)
// 	{
// 		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
// 			game->textures->heart_full.img,
// 			INTERFACE_SIZE + 167 + (i * 15), 0);
// 		i++;
// 	}
// 	while (i < LIFE_COUNT)
// 	{
// 		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
// 			game->textures->heart_empty.img,
// 			INTERFACE_SIZE + 167 + (i * 15), 0);
// 		i++;
// 	}
// }

void	ft_render_weapon(t_game *game)
{
	char	*count;
	char	*phrase;

	count = ft_itoa(game->player->weapon_count);
	if (!count)
		ft_exit(game, MEMORY_ERR, NULL);
	phrase = ft_strjoin("Weapon : ", count);
	if (!phrase)
		ft_exit(game, MEMORY_ERR, NULL);
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, \
		10, 60, 16777215, phrase);
	free(count);
	free(phrase);
}

void	ft_render_life(t_game *game)
{
	char	*life;
	char	*phrase;

	life = ft_itoa(game->player->life);
	if (!life)
		ft_exit(game, MEMORY_ERR, NULL);
	phrase = ft_strjoin("Life : ", life);
	if (!phrase)
		ft_exit(game, MEMORY_ERR, NULL);
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, \
		10, 40, 16777215, phrase);
	free(life);
	free(phrase);
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
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr, \
		10, 20, 16777215, phrase);
	free(movements);
	free(phrase);
}

void	ft_render_interface(t_game *game)
{
	ft_render_movements(game);
	ft_render_life(game);
	ft_render_weapon(game);
}
