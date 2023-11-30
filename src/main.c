/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/30 22:05:59 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd((char *)lst->content, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

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

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr  = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

int main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (*(int *)ft_exit(NULL, ARGS_ERR, NULL));
	game = ft_init();
	ft_get_map(game, av[1]);
	ft_lstprint(game->map->items);
	// printf("test %s\n", (char *)game->map->content);
	// ft_check_map(av[1]);
	
	return (*(int *)ft_exit(game, SUCCESS, NULL));
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_game	game;
// 	t_image	img;

// 	(void)ac, (void)av, (void)envp;
// 	game.mlx_ptr = mlx_init();
// 	if (!game.mlx_ptr)
// 		return (1);
// 	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "wsh mgl !");
// 	if (!game.win_ptr)
// 		return (free(game.mlx_ptr), 1);
// 	// img.img = mlx_new_image(game.mlx_ptr, 1920, 1080);
// 	img.size.x = 1920;
// 	img.size.y = 1080;
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
// 	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	img.img = mlx_xpm_file_to_image(game.mlx_ptr, av[1], &img.size.x, &img.size.y);
// 	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img, 960, 540);
	
	
// 	mlx_hook(game.win_ptr, KeyRelease, KeyRelease, &on_keypress, &game);
// 	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
 
// 	// Loop over the MLX pointer
// 	mlx_loop(game.mlx_ptr);
	
// 	return (0);
// }