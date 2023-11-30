/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:33:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/30 22:07:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, FILE_ERR, map_path);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break;
		ft_lstadd_back(&game->map->items, ft_lstnew(line)); // CHECK LEAK WITH LSTNEW
	}
	if (!game->map->items)
		ft_exit(game, MAP_ERR, "Nothing found inside the file");
	game->map->size->x = ft_strlen((char *)game->map->items->content);
	game->map->size->y = ft_lstsize(game->map->items);
	ft_check_map(game);
}

int	ft_is_on_contour(t_game *game, int pos[2])
{
	if (pos[0] == 0 || pos[1] == 0
		|| pos[0] == (game->map->size->y - 1)
		|| pos[1] == (game->map->size->x - 1))
		return (1);
	return (0);
}

/* ********************************MAP CHECKER******************************* */
void	ft_check_map_elem(t_game *game, char c, int pos[2])
{
	if (ft_is_on_contour(game, pos) && c != '1')
				ft_exit(game, MAP_ERR, "Well, ur map suck bro...not only wall in border");
	if (c == 'E')
		game->map->e_count++;
	else if (c == 'P')
	{
		game->player->position->y = pos[0];
		game->player->position->x = pos[1];
		game->map->p_count++;
	}
	else if (c == 'C')
		game->map->c_count++;
	else if (c != '1' && c != '0')
		ft_exit(game, MAP_ERR, "Invalid character, use only E, P, C, 1, 0");
}

int	is_valid_move(t_game *game, int x, int y)
{
	return (x >= 0 && x < game->map->size->x && y >= 0 && y < game->map->size->y);
}

int	ft_check_map_solvability(t_game *game, int x, int y)
{
	(void)game, (void)x, (void)y;
	return (1);
}

void	ft_check_map(t_game *game)
{
	int			pos[2];
	t_list		*current;

	pos[0] = 0; // POS Y
	current = game->map->items;
	while (current)
	{
		pos[1] = 0;
		while(((char *)current->content)[pos[1]])
		{
			ft_check_map_elem(game, ((char *)current->content)[pos[1]], pos);
			pos[1]++;
		}
		if (pos[1] != game->map->size->x)
			ft_exit(game, MAP_ERR, "All row need to have the same size.");
		current = current->next;
		pos[0]++;
	}
	if (game->map->e_count != 1 || game->map->p_count != 1 || game->map->c_count < 1)
		ft_exit(game, MAP_ERR, "Invalid map settings number.");
	if (!ft_check_map_solvability(game, 0, 0))
		ft_exit(game, MAP_ERR, "Cannot solve the map.");
}
/* ********************************MAP CHECKER******************************* */
