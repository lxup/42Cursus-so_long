/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:34:55 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 14:05:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_exit(t_game *game, int error, char *param)
{
	if (error)
		ft_error(error, param);
	if (game)
		ft_free_game(game);
	if (error < 0)
		return (exit(EXIT_FAILURE), (void *)EXIT_FAILURE);
	return (exit(EXIT_SUCCESS), (void *)EXIT_SUCCESS);
}
