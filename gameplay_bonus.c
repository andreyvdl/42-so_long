/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:59:13 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:47:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	gameplay(t_master *mstr)
{
	mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1]] = '0';
	mlx_key_hook(mstr->ptr->win, key_pressed, mstr);
	mlx_hook(mstr->ptr->win, 17, 0, mlx_exit, mstr);
	mlx_loop(mstr->ptr->mlx);
}

int	key_pressed(int keycode, t_master *mstr)
{
	if (keycode == ESC)
		return (mlx_exit(mstr));
	else if (keycode == 'w' || keycode == 'z' || keycode == ARROWU)
		return (move_up(mstr));
	else if (keycode == 's' || keycode == ARROWD)
		return (move_down(mstr));
	else if (keycode == 'a' || keycode == 'q' || keycode == ARROWL)
		return (move_left(mstr));
	else if (keycode == 'd' || keycode == ARROWR)
		return (move_right(mstr));
	return (0);
}

int	mlx_exit(t_master *mstr)
{
	mlx_clear_window(mstr->ptr->mlx, mstr->ptr->win);
	mlx_destroy_window(mstr->ptr->mlx, mstr->ptr->win);
	free_map(mstr->map);
	free_textures(mstr->ptr, mstr->img);
	mlx_destroy_display(mstr->ptr->mlx);
	free(mstr->ptr->mlx);
	credits();
	exit(0);
}

int	render_update(t_master *mstr, int side)
{
	mlx_clear_window(mstr->ptr->mlx, mstr->ptr->win);
	put_images(mstr, side);
	return (0);
}
