/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:18:26 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 20:11:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_mlx(int error)
{
	if (error == MLX_INIT_ERR)
		ft_putstr_fd("Error during init of MLX", 2);
	if (error == MLX_NEW_WINDOW_ERR)
		ft_putstr_fd("Error creating new window with MLX", 2);
	if (error == SPRITE_NEW_ERR)
		ft_putstr_fd("Coulnd't find the sprite: ", 2);
}

void	ft_error(int error, char *param)
{
	ft_putstr_fd("Error:\n", 2);
	if (error == MEMORY_ERR)
		ft_putstr_fd("DAMN, no memory left on device", 2);
	if (error == ARGS_ERR)
		ft_putstr_fd("Mhh, bro...give me valid arguments, like: ", 2);
	if (error == FILE_ERR)
		ft_putstr_fd("Well, there is something wrong with this file: ", 2);
	if (error == MAP_ERR)
		ft_putstr_fd("Ur map suck bro: ", 2);
	if (error <= MLX_INIT_ERR && error >= MLX_NEW_WINDOW_ERR)
		ft_error_mlx(error);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}
