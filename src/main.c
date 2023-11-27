/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/27 19:47:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
int on_keypress(int keycode, t_game *game)
{
	printf("Pressed key: %d\\n", keycode);
	if (keycode == KEY_ESC)
		on_destroy(game);
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr  = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	main(int ac, char **av, char **envp)
{
	t_game	game;
	t_image	img;

	(void)ac, (void)av, (void)envp;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "wsh mgl !");
	if (!game.win_ptr)
		return (free(game.mlx_ptr), 1);
	img.img = mlx_new_image(game.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_xpm_file_to_image(game.mlx_ptr, av[1], &img.size.x, &img.size.y);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img, 0, 0);
	
	
	mlx_hook(game.win_ptr, KeyRelease, KeyRelease, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
 
	// Loop over the MLX pointer
	mlx_loop(game.mlx_ptr);
	
	return (0);
}