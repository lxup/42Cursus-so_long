/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 16:41:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_game *game)
{
	printf("Pressed key: %d\\n", keycode);
	if (keycode == KEY_ESC)
		return (*(int *)ft_exit(game, SUCCESS, NULL));
		// on_destroy(game);
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	return (img);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (*(int *)ft_exit(NULL, ARGS_ERR, NULL));
	game = ft_init();
	ft_get_map(game, av[1]);
	ft_check_map(game);
	ft_init_mlx(game);
	// ft_matrixprint(game->map->items);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, on_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (*(int *)ft_exit(game, SUCCESS, NULL));
}
