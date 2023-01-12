/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:09:12 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 12:03:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft/libft.h"

void	put_images(t_master *mstr, int side)
{
	char	*player_moves;

	player_moves = ft_itoa(mstr->mc_mv);
	walls_n_floors(mstr->map, mstr->ptr, mstr->img);
	coins_n_exit(mstr->map, mstr->ptr, mstr->img);
	enemies(mstr->map, mstr->ptr, mstr->img);
	put_player(mstr->map, mstr->ptr, mstr->img, side);
	mlx_string_put(mstr->ptr->mlx, mstr->ptr->win, 7, 10, 0x00000000, "MOVES ");
	mlx_string_put(mstr->ptr->mlx, mstr->ptr->win, 7 * 6, 10, 0x00000000,
		player_moves);
	free(player_moves);
}

void	walls_n_floors(t_map *map, t_ptr *ptrs, t_img *img)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->wall,
					x * img->size, y * img->size);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->floor,
					x * img->size, y * img->size);
		}
	}
}

void	coins_n_exit(t_map *map, t_ptr *ptrs, t_img *img)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->coin,
					x * img->size, y * img->size);
			else if (map->map[y][x] == 'E' && map->coin_count != 0)
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->exit0,
					x * img->size, y * img->size);
			else if (map->map[y][x] == 'E' && map->coin_count == 0)
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->exit1,
					x * img->size, y * img->size);
		}
	}
}

void	enemies(t_map *map, t_ptr *ptrs, t_img *img)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (map->map[y][x] == 'X')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->enemy,
					x * img->size, y * img->size);
		}
	}
}

void	put_player(t_map *map, t_ptr *ptrs, t_img *img, int side)
{
	if (side == 1)
		mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->mc_l,
			map->mc[1] * img->size, map->mc[0] * img->size);
	else if (side == 2)
		mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->mc_u,
			map->mc[1] * img->size, map->mc[0] * img->size);
	else if (side == 3)
		mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->mc_r,
			map->mc[1] * img->size, map->mc[0] * img->size);
	else
		mlx_put_image_to_window(ptrs->mlx, ptrs->win, img->mc_d,
			map->mc[1] * img->size, map->mc[0] * img->size);
}
