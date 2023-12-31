/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:18:02 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 20:06:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check_extension(t_game *game, char *map_path)
{
	int	i;

	i = ft_strlen(map_path) - 4;
	if (i < 0)
		ft_exit(game, FILE_ERR, "File extension need to be a .ber");
	if (ft_strncmp(map_path + i, FILE_EXTENSION, ft_strlen(FILE_EXTENSION)))
		ft_exit(game, FILE_ERR, "File extension need to be a .ber");
}

void	read_to_end_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		free(line);
	}
}

char	*ft_map_check_file(t_game *game)
{
	char	*buffer;
	char	*line;
	char	*tmp;

	buffer = ft_strdup("");
	if (!buffer)
		return (ft_exit(game, MEMORY_ERR, NULL));
	line = NULL;
	while (1)
	{
		tmp = buffer;
		line = get_next_line(game->map->fd);
		if (!line || !*line)
			break ;
		if (*line == '\n')
			return (free(buffer), free(line), read_to_end_file(game->map->fd),
				ft_exit(game, FILE_ERR, "Empty line"));
		buffer = ft_strjoin(tmp, line);
		if (!buffer)
			return (free(tmp), free(line), read_to_end_file(game->map->fd),
				ft_exit(game, MEMORY_ERR, NULL));
		free(tmp);
		free(line);
	}
	return (buffer);
}

void	ft_get_map(t_game *game, char *map_path)
{
	char	*buffer;

	ft_map_check_extension(game, map_path);
	game->map->fd = open(map_path, O_RDONLY);
	if (game->map->fd == -1)
		ft_exit(game, FILE_ERR, map_path);
	buffer = ft_map_check_file(game);
	game->map->items = ft_split(buffer, '\n');
	free(buffer);
	if (!game->map->items || !*game->map->items)
		ft_exit(game, MAP_ERR, "Nothing found inside the file");
	game->map->size->x = ft_strlen(game->map->items[0]);
	game->map->size->y = ft_get_matrix_size(game->map->items);
}
