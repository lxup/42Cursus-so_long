/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:18:03 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 16:32:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_exit(game, MLX_INIT_ERR, NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (game->win_ptr == NULL)
		ft_exit(game, MLX_NEW_WINDOW_ERR, NULL);
}
// game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	