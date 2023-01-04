/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:28:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/04 14:42:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

// Game max resolution is based on the workspaces resolution: 1280x1024
int	mlx_start(t_map *map, t_ptr *ptr, t_img *img)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
	{
		free_map(map);
		return (1);
	}
	if (load_textures(map, ptr, img))
		return (1);
	ptr->win = mlx_new_window(ptr->mlx, map->x_mx * img->size,
			map->y_mx * img->size, "EPIC GAME by adantas-");
	if (!ptr->win)
	{
		free_textures(ptr, img);
		free_map(map);
		return (1);
	}
	return (0);
}

int	load_textures(t_map *map, t_ptr *ptr, t_img *img)
{
	if (map->x_mx < 6 && map->y_mx == 3)
	{
		img->size = 256;
		return (load256(ptr, img));
	}
	else if (map->x_mx < 11 && map->y_mx < 7)
	{
		img->size = 128;
		return (load128(ptr, img));
	}
	else if (map->x_mx < 21 && map->y_mx < 13)
	{
		img->size = 64;
		return (load64(ptr, img));
	}
	else if (map->x_mx < 41 && map->y_mx < 25)
	{
		img->size = 32;
		return (load32(ptr, img));
	}
	if (load_more_textures(map, ptr, img))
		return (0);
	return (1);
}

int	load_more_textures(t_map *map, t_ptr *ptr, t_img *img)
{
	if (map->x_mx < 81 && map->y_mx < 49)
	{
		img->size = 16;
		return (load16(ptr, img));
	}
	else if (map->x_mx < 161 && map->y_mx < 97)
	{
		img->size = 8;
		return (load8(ptr, img));
	}
	return (0);
}
