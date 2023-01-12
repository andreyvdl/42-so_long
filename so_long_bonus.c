/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:15:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 13:27:26 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft/ft_printf.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_ptr		ptrs;
	t_img		img;
	t_master	mstr;

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
	mstr.map = &map;
	mstr.ptr = &ptrs;
	mstr.img = &img;
	mstr.mc_mv = 0;
	put_images(&mstr, -1);
	gameplay(&mstr);
}

void	credits(void)
{
	ft_printf("\t\t\e[1;34mGraphics\e[0m\n");
	ft_printf("\e[1;33mKirby Mass Attack\tJermungandr\e[0m\n");
	ft_printf("https://is.gd/6n99aG https://is.gd/5slJ67 ");
	ft_printf("https://is.gd/SShpdL\n\n");
	ft_printf("\e[1;33mKirby Dream Land 3\tAwsomeguy5\e[0m\n");
	ft_printf("https://is.gd/m7qRJe\n\n");
	ft_printf("\t\t\e[1;34mCode\e[0m\n");
	ft_printf("\e[1;33mAndrey(adantas-)\tGithub Copilot\e[0m\n\n");
	ft_printf("\e[1;37mThank you very much for playing my game\e[0m\n");
}
