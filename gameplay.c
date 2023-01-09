/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:59:13 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/09 15:27:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gameplay(t_map *map, t_ptr *ptrs, t_img *img)
{
	t_master	mstr;

	mstr.mc_mv = 0;
	mstr.map = map;
	mstr.ptr = ptrs;
	mstr.img = img;
	mlx_key_hook(ptrs->win, key_pressed, &mstr);
	mlx_loop_hook(ptrs->mlx, render_update, &mstr);
	mlx_loop(ptrs->mlx);
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
	exit(0);
}

int	render_update(t_master *mstr)
{
	if (mstr->mc_mv == 1)
	{
		mlx_clear_window(mstr->ptr->mlx, mstr->ptr->win);
		put_images(mstr->map, mstr->ptr, mstr->img, -1);
	}
	return (0);
}