/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/11 15:58:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	validate_file(char *file, t_map *map)
{
	int	fd;
	int	i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".ber", 4))
		print_error("filename", 53);
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0))
	{
		close(fd);
		print_error("openning", 2);
	}
	map->name = file;
	map->fd = fd;
}
