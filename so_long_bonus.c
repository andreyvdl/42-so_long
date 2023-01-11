/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:15:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/11 16:43:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft/ft_printf.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_ptr	ptrs;
	t_img	img;

	if (ac != 2)
		print_error("argument", 22);
	validate_file(av[1], &map);
	if (validate_map(&map))
	{
		close(map.fd);
		print_error("map", 59);
	}
	if (mlx_start(&map, &ptrs, &img))
		print_error("mlx", 28);
	put_images(&map, &ptrs, &img, -1);
	gameplay(&map, &ptrs, &img);
}
