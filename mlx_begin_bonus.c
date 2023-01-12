/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:28:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 14:27:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mlx_start(t_map *map, t_ptr *ptr, t_img *img)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (free_map(map), 1);
	if (load_textures(ptr, img, map))
		return (free_textures(ptr, img), mlx_destroy_display(ptr->mlx),
			free_map(map), 1);
	ptr->win = mlx_new_window(ptr->mlx, map->x_mx * img->size,
			map->y_mx * img->size,
			"The sprites of this game adapt to the window size");
	if (!ptr->win)
		return (free_textures(ptr, img), mlx_destroy_display(ptr->mlx),
			free_map(map), 1);
	return (0);
}

int	load_textures(t_ptr *ptr, t_img *img, t_map *map)
{
	if (map->x_mx < 6 && map->y_mx == 4)
		return (load256(ptr, img));
	else if (map->x_mx < 11 && map->y_mx < 9)
		return (load128(ptr, img));
	else if (map->x_mx < 21 && map->y_mx < 17)
		return (load64(ptr, img));
	else if (map->x_mx < 41 && map->y_mx < 33)
		return (load32(ptr, img));
	else if (map->x_mx < 81 && map->y_mx < 65)
		return (load16(ptr, img));
	else
		return (load8(ptr, img));
}

int	load8(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL8, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR8, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO8, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC8, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN8, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR8, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL8, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU8, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD8, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY8, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 8;
	return (0);
}
