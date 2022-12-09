/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:11:57 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/09 15:52:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_map *map)
{
	map->x_mx = 0;
	map->mc_count = 0;
	map->exit_count = 0;
	get_map_size(map);
	close(map->fd);
	map->fd = open(map->name, O_RDONLY);
	file2matrix(map)
	close(map->fd);
	else if (map_is_valid(map))
	{
		free_map(map);
		return (1);
	}
	return (0);
}

void	get_map_size(t_map *map)
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
			map->x_mx = ft_strlen(line);
		else if (map->x_mx != ft_strlen(line) || map->x_mx <= 2)
		{
			free(line);
			free_map(map);
			print_error("map_size", 59);
		}
		free(line);
		y++;
	}
	map->y_mx = y;
}

void	file2matrix(t_map *map)
{
	char	*line;
	size_t	y;

	map->map = (char **)ft_calloc(sizeof(char *) * map->y_mx + 1,
			map->x_mx + 1);
	y = -1;
	while (y <= map->y_mx)
	{
		line = get_next_line(map->fd);
		map->map[++y] = line;
		free(line);
	}
}
