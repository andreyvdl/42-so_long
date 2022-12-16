/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:28:08 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/16 16:34:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_start(t_map *map, t_ptr *ptr, t_img *img)
{
	if (load_textures(map, ptr, img))
		return (1);
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free_textures(map, ptr, img);
		return (1);
	}
	map->win = mlx_new_window(map->mlx, map->x_mx * img->size,
			map->y_mx * img->size, "EPIC GAME by adantas-");
	if (!map->win)
	{
		free_textures(map, ptr, img);
		return (1);
	}
	return (0);
}

int	load_textures(t_map *map, t_ptr *ptr, t_img *img)
{
	if (map->x_mx < 6 && map->y_mx == 3)
	{
		img->size = 256;
		return (load256(map, ptr, img), 0);
	}
	else if (map->x_mx < 11 && map->y_mx < 7)
	{
		img->size = 128;
		return (load128(map, ptr, img), 0);
	}
	else if (map->x_mx < 21 && map->y_mx < 13)
	{
		img->size = 64;
		return (load64(map, ptr, img), 0);
	}
	else if (map->x_mx < 41 && map->y_mx < 25)
	{
		img->size = 32;
		return (load32(map, ptr, img), 0);
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
		return (load16(map, ptr, img), 1);
	}
	else if (map->x_mx < 161 && map->y_mx < 97)
	{
		img->size = 8;
		return (load8(map, ptr, img), 1);
	}
	return (0);
}
