/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 19:56:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (*(int *)ft_exit(NULL, ARGS_ERR, NULL));
	game = ft_init();
	ft_get_map(game, av[1]);
	ft_check_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	render(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, on_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (*(int *)ft_exit(game, SUCCESS, NULL));
}
