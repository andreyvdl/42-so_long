/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:10:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/09 15:38:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_copy(t_map *map, char **map_copy)
{
	size_t	y;

	y = -1;
	while (++y < map->y_mx)
		free(map_copy[y]);
	free(map_copy);
}

void	free_map(t_map *map)
{
	size_t	y;

	y = -1;
	while (++y < map->y_mx)
		free(map->map[y]);
	free(map->map);
}

void	free_textures(t_ptr *ptrs, t_img *img)
{
	if (img->wall)
		mlx_destroy_image(ptrs->mlx, img->wall);
	if (img->floor)
		mlx_destroy_image(ptrs->mlx, img->floor);
	if (img->exit0)
		mlx_destroy_image(ptrs->mlx, img->exit0);
	if (img->exit1)
		mlx_destroy_image(ptrs->mlx, img->exit1);
	if (img->coin)
		mlx_destroy_image(ptrs->mlx, img->coin);
	if (img->mc_r)
		mlx_destroy_image(ptrs->mlx, img->mc_r);
}
