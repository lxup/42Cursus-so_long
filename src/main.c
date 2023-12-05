/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 15:02:31 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_window_close(t_game *game)
{
	return (*(int *)ft_exit(game, LEAVE, NULL));
}

void	hook_register(t_game *game)
{
	if (ft_strncmp(OS, "linux", 5) == 0)
	{
		mlx_hook(game->win.win_ptr, 17, 0, on_window_close, game);
		mlx_hook(game->win.win_ptr, 2, 1L << 0, on_keypress, game);
	}
	else if (ft_strncmp(OS, "macos", 5) == 0)
	{
		mlx_hook(game->win.win_ptr, 17, 1L << 0, on_window_close, game);
		mlx_hook(game->win.win_ptr, 2, 0, on_keypress, game);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (*(int *)ft_exit(NULL, ARGS_ERR, "./so_long ./map_path"));
	game = ft_init();
	ft_get_map(game, av[1]);
	ft_check_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	hook_register(game);
	if (ft_strncmp(OS, "linux", 5) == 0)
	{
		render(game);
	}
	else if (ft_strncmp(OS, "macos", 5) == 0)
	{
		mlx_loop_hook(game->win.mlx_ptr, render, game);
	}
	mlx_loop(game->win.mlx_ptr);
	return (*(int *)ft_exit(game, SUCCESS, NULL));
}
