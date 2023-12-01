/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:18:26 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/01 14:05:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int error, char *param)
{
	if (error == MEMORY_ERR)
		ft_putstr_fd("DAMN, no memory left on device", 2);
	if (error == ARGS_ERR)
		ft_putstr_fd("Mhh, bro...give me valid arguments, like: ", 2);
	if (error == FILE_ERR)
		ft_putstr_fd("Well, there is something wrong with this file: ", 2);
	if (error == MAP_ERR)
		ft_putstr_fd("Ur map suck bro: ", 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}
