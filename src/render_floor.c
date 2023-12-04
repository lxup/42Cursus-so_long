/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:49:18 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 10:54:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_floor(t_game *game, int y, int x)
{
	ft_render_sprite(game, game->textures->floor, y, x);
}
