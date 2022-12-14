/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitestx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:15:07 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/14 12:52:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compile with the flags -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
// int	deal_key(int key, t_pointers *param)
// {
// 	ft_printf("key: %d\n", key);
// 	return (1);
// }

#include "so_long.h"
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
	t_map		map;
	// t_pointers	ptrs;
	// t_img		img;

	if (ac != 2)
		print_error("argument", 22);
	validate_file(av[1], &map);
	if (validate_map(&map))
	{
		close(map.fd);
		print_error("map", 59);
	}
	for (size_t i = 0; i < map.y_mx; i++)
		ft_printf("%s\n", map.map[i]);
	ft_printf("\e[44mLoading game...🎮\e[0m\n");
	// game_start(&ptrs, &map); //256: 5x3 128: 10x6 64: 20x12 32: 40x24 16: 80x48 8: 160x96
	// mlx_put_image_to_window(ptrs.mlx, ptrs.win, ptrs.img, 400, 300);
	// mlx_loop(ptrs.mlx);
	// credits(&ptrs, &map, &img);
}
