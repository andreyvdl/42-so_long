/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:20 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/11 17:39:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft/libft.h"

int	locate_references(t_map *map, size_t y, size_t x)
{
	while (++y < map->y_mx)
	{
		while (++x < map->x_mx)
		{
			if (map->map[y][x] == 'P')
			{
				map->mc[0] = y;
				map->mc[1] = x;
				map->mc_count++;
			}
			else if (map->map[y][x] == 'E')
				map->exit_count++;
		}
		x = -1;
	}
	if (map->mc_count != 1 || map->exit_count != 1)
		return (1);
	return (0);
}

int	backtracking(t_map *map)
{
	char	**copy;
	size_t	y;
	size_t	x;

	copy = (char **)ft_calloc(map->y_mx + 1, sizeof(char *));
	y = -1;
	while (++y < map->y_mx)
		copy[y] = ft_strdup(map->map[y]);
	flowage(copy, map->mc[0], map->mc[1]);
	y = -1;
	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (ft_strchr("EC", copy[y][x]))
			{
				free_copy(map, copy);
				return (1);
			}
		}
	}
	free_copy(map, copy);
	return (0);
}

void	flowage(char **map, size_t y, size_t x)
{
	map[y][x] = 'X';
	if (!ft_strchr("1X", map[y][x + 1]))
		flowage(map, y, x + 1);
	if (!ft_strchr("1X", map[y][x - 1]))
		flowage(map, y, x - 1);
	if (!ft_strchr("1X", map[y + 1][x]))
		flowage(map, y + 1, x);
	if (!ft_strchr("1X", map[y - 1][x]))
		flowage(map, y - 1, x);
}
