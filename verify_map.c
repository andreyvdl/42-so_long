/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:11:57 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/12 16:58:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_map *map)
{
	map->x_mx = 0;
	map->mc_count = 0;
	map->exit_count = 0;
	if (get_map_size(map))
		return (1);
	close(map->fd);
	map->fd = open(map->name, O_RDONLY);
	file2matrix(map);
	if (map_is_closed(map))
	{
		free_map(map);
		return (1);
	}
	if (map_is_valid(map))
	{
		free_map(map);
		return (1);
	}
	if (backtracking(map))
	{
		free_map(map);
		return (1);
	}
	close(map->fd);
	return (0);
}

int	get_map_size(t_map *map)
{
	char	*line;
	size_t	y;

	y = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (map->x_mx == 0)
			map->x_mx = ft_strlen(line) - 1;
		else if (map->x_mx != ft_strlen(line) - 1 || map->x_mx <= 2)
		{
			free(line);
			return (1);
		}
		free(line);
		y++;
	}
	if (y <= 2)
		return (1);
	map->y_mx = y;
	return (0);
}

void	file2matrix(t_map *map)
{
	char	*line;
	size_t	y;
	size_t	x;

	map->map = (char **)ft_calloc(sizeof(char *), map->y_mx + 1);
	y = -1;
	while (++y <= map->y_mx)
	{
		line = get_next_line(map->fd);
		x = -1;
		map->map[y] = (char *)ft_calloc(sizeof(char), map->x_mx + 1);
		while (line[++x] != '\n')
			map->map[y][x] = line[x];
		free(line);
	}
}

int	map_is_closed(t_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y <= map->y_mx)
		if (map->map[y][0] != '1' || map->map[y][map->x_mx] != '1')
			return (1);
	x = -1;
	while (++x <= map->x_mx)
		if (map->map[0][x] != '1' || map->map[map->y_mx][x] != '1')
			return (1);
	return (0);
}

int	map_can_be_checked(t_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y <= map->y_mx)
	{
		x = -1;
		while (++x <= map->x_mx)
		{
			if (map->map[y][x] != '1' && map->map[y][x] != '0'
				&& map->map[y][x] != 'C' && map->map[y][x] != 'E'
				&& map->map[y][x] != 'P')
				return (1);
			else if (map->map[y][x] == 'C')
				map->coin_count++;
		}
	}
	if (locate_references(map, -1, -1) || map->coin_count == 0)
		return (1);
	return (0);
}
