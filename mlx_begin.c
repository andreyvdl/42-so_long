/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:28:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/07 15:29:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

// Game max resolution is based on the workspaces resolution: 1280x1024
int	mlx_start(t_map *map, t_ptr *ptr, t_img *img)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (free_map(map), 1);
	if (load_textures(ptr, img))
		return (free_textures(ptr, img), free_ptrs(ptr), 1);
	img->size = 32;
	ptr->win = mlx_new_window(ptr->mlx, map->x_mx * img->size,
			map->y_mx * img->size, "EPIC GAME by adantas-");
	if (!ptr->win)
		return (free_textures(ptr, img), free_map(map), 1);
	return (0);
}

int	load_textures(t_ptr *ptr, t_img *img)
{
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR32, &img->size, &img->size);
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL32, &img->size, &img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN32, &img->size, &img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR32, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC32, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO32, &img->size,
			&img->size);
	if (!img->mc_r || !img->wall || !img->coin || !img->floor || !img->exit0
		|| !img->exit1)
		return (1);
	return (0);
}
