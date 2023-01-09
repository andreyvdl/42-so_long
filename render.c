/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:09:12 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/09 15:46:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_map *map, t_ptr *ptrs, t_img *img, size_t y)
{
	size_t	x;

	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->wall,
					x * 32, y * 32);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->coin,
					x * 32, y * 32);
			else if (map->map[y][x] == 'E' && map->coin_count != 0)
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->exit0,
					x * 32, y * 32);
			else if (map->map[y][x] == 'E' && map->coin_count == 0)
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->exit1,
					x * 32, y * 32);
			else
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->floor,
					x * 32, y * 32);
		}
	}
	put_player(map, ptrs, img);
}

void	put_player(t_map *map, t_ptr *ptrs, t_img *img)
{
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->mc_r,
		map->mc[0] * 32, map->mc[1] * 32);
}
