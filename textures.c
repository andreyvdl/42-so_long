/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:36:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/04 14:44:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load256(t_ptr *ptrs, t_img *img)
{
	img->coin = mlx_xpm_file_to_image(ptrs->mlx, "textures/coin256.xpm",
			(void *)0, (void *)0);
	img->exit0 = mlx_xpm_file_to_image(ptrs->mlx, "textures/exitClose256.xpm",
			(void *)0, (void *)0);
	img->exit1 = mlx_xpm_file_to_image(ptrs->mlx, "textures/exitOpen256.xpm",
			(void *)0, (void *)0);
	img->floor = mlx_xpm_file_to_image(ptrs->mlx, "textures/ground256.xpm",
			(void *)0, (void *)0);
	img->mc_d = mlx_xpm_file_to_image(ptrs->mlx, "textures/mcDown256.xpm",
			(void *)0, (void *)0);
	img->mc_l = mlx_xpm_file_to_image(ptrs->mlx, "textures/mcLeft256.xpm",
			(void *)0, (void *)0);
	img->mc_r = mlx_xpm_file_to_image(ptrs->mlx, "textures/mcRight256.xpm",
			(void *)0, (void *)0);
	img->mc_u = mlx_xpm_file_to_image(ptrs->mlx, "textures/mcUp256.xpm",
			(void *)0, (void *)0);
	img->wall = mlx_xpm_file_to_image(ptrs->mlx, "textures/wall256.xpm",
			(void *)0, (void *)0);
	if (!img->coin || !img->exit0 || !img->exit1 || !img->floor || !img->mc_d
}
