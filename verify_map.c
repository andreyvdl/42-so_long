/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:11:57 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/08 17:22:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_map *map)
{
	map->x_mx = 0;
	map->mc_count = 0;
	map->exit_count = 0;
	if (mapping(map))
	{
		free_map(map);
		return (1);
	}
	close(map->fd);
	else if (play_map(map))
	{
		free_map(map);
		return (1);
	}
	return (0);
}

int	mapping(t_map *map)
{
	size_t	y;
	char	*line;

	y = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (line[0] == '\n' || cp_map(map, line, y)
			|| (ft_strlen(line) != map->x_mx && map->x_mx != 0))
		{
			free(line);
			return (1);
		}
		if (!map->x_mx)
			map->x_mx = ft_strlen(line);
		free(line);
		y++;
	}
	map->y_mx = y;
	if (locate_mc_exit_corners(map, -1, -1))
		return (1);
	return (0);
}

int	cp_map(t_map *map, char *line, int y)
{
	size_t	x;

	x = -1;
	while (line[++x] != '\n')
	{
		if (ft_strnstr("01CEP", &line[x], 5))
			map->map[y][x] = line[x];
		else
			return (1);
	}
	map->map[y][x] = 0;
	return (0);
}

int	locate_mc_exit_corners(t_map *map, size_t y, size_t x)
{
	while (++y <= map->y_mx)
	{
		while (++x <= map->x_mx)
		{
			if (map->map[y][x] == 'P')
			{
				map->mc_count++;
				map->mc[0] = y;
				map->mc[1] = x;
				map->mc[2] = 0;
			}
			else if (map->map[y][x] == 'E')
			{
				map->exit_count++;
				map->exit[0] = y;
				map->exit[1] = x;
				map->exit[2] = 0;
			}
		}
	}
	if (map->mc_count > 1 || map->exit_count > 1 || check_corners(map))
		return (1);
	return (0);
}

int	check_corners(t_map *map)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (map->map[0][++x])
		if (map->map[0][x] != '1')
			return (1);
	x = -1;
	while (map->map[map->y_mx - 1][++x])
		if (map->map[map->y_mx - 1][x] != '1')
			return (1);
	y = -1;
	while (map->map[++y])
		if (map->map[y][0] != '1' || map->map[y][map->x_mx - 1] != '1')
			return (1);
	return (0);
}

int	play_map(t_map *map)
{
	static char	**map_copy = copy_matrix(map->map, map->y_mx, map->x_mx);
	size_t		y;

	y = -1;
	softlocked(map_copy, map->mc[0], map->mc[1]);
	while (++y < map->y_mx)
	{
		if (ft_strnstr(map_copy[y], "C", map->x_mx)
			|| ft_strnstr(map_copy[y], "C", map->x_mx))
		{
			y = -1;
			while (++y < map->y_mx)
				free(map_copy[y]);
			free(map_copy);
			free_copy(map, map_copy);
			return (1);
		}
	}
	y = -1;
	while (++y < map->y_mx)
		free(map_copy[y]);
	free(map_copy);
	return (0);
}

char	**copy_matrix(char **matrix, size_t maxy, size_t maxx)
{
	size_t	y;
	char	**new_matrix;

	y = -1;
	new_matrix = (char **)ft_calloc(maxy, maxx +);
	while (++y < maxy)
		new_matrix[y] = ft_strdup(matrix[y][x])
}

void	softlocked(char **map, size_t y, size_t x)
{
	map[y][x] = 'X';
	if (map[y + 1][x] != 'X' || map[y + 1][x] != '1')
		softlocked(map, y + 1, x);
	if (map[y][x - 1] != 'X' || map[y][x - 1] != '1')
		softlocked(map, y, x - 1);
	if (map[y - 1][x] != 'X' || map[y - 1][x] != '1')
		softlocked(map, y - 1, x);
	if (map[y][x + 1] != 'X' || map[y][x + 1] != '1')
		softlocked(map, y, x + 1);
}
