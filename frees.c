/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:10:50 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/08 17:20:46 by adantas-         ###   ########.fr       */
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
