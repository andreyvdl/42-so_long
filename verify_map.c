/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:11:57 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/10 17:34:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/libft.h"
#include "includes/gnl.h"
#include "includes/ft_printf.h"

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
		y++;
		if (map->x_mx == 0)
			map->x_mx = ft_strlen(line) - 1;
		else if ((map->x_mx != ft_strlen(line) - 1
				&& line[ft_strlen(line)] == '\n') || (map->x_mx <= 2
				|| map->x_mx > 40))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	if (y <= 2 || (map->x_mx <= 3 && y <= 3) || y > 24)
		return (1);
	map->y_mx = y;
	return (0);
}

void	file2matrix(t_map *map)
{
	char	line[1];
	size_t	y;
	size_t	x;

	map->map = (char **)ft_calloc(sizeof(char *), map->y_mx + 1);
	y = -1;
	while (++y < map->y_mx)
	{
		x = 0;
		map->map[y] = (char *)ft_calloc(sizeof(char), map->x_mx + 1);
		while (x < map->x_mx)
		{
			read(map->fd, line, 1);
			map->map[y][x] = line[0];
			x++;
		}
		read(map->fd, line, 1);
	}
}

int	map_is_closed(t_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->y_mx)
		if (map->map[y][0] != '1' || map->map[y][map->x_mx - 1] != '1')
			return (1);
	x = -1;
	while (++x < map->x_mx)
		if (map->map[0][x] != '1' || map->map[map->y_mx - 1][x] != '1')
			return (1);
	return (0);
}

int	map_is_valid(t_map *map)
{
	size_t	y;
	size_t	x;

	map->coin_count = 0;
	y = -1;
	while (++y < map->y_mx)
	{
		x = -1;
		while (++x < map->x_mx)
		{
			if (!ft_strchr("01CEP", map->map[y][x]))
				return (1);
			else if (map->map[y][x] == 'C')
				map->coin_count++;
		}
	}
	if (map->coin_count == 0 || locate_references(map, -1, -1))
		return (1);
	return (0);
}
