/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:34:55 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/04 19:35:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_success(int msg)
{
	if (msg == SUCCESS)
		ft_putstr_fd("GG, well this game suck so u probably loose ur time", 1);
	else if (msg == LOOSE)
		ft_putstr_fd("SHAME ON U, u die in the easiest game ever", 1);
}	

void	*ft_exit(t_game *game, int error, char *param)
{
	if (error < 0)
		ft_error(error, param);
	if (error > 0)
		ft_success(error);
	if (game)
		ft_free_game(game);
	if (error < 0)
		return (exit(EXIT_FAILURE), (void *)EXIT_FAILURE);
	return (exit(EXIT_SUCCESS), (void *)EXIT_SUCCESS);
}
