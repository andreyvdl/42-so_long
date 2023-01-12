/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:33:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 09:37:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load256(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL256, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR256, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO256, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC256, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN256, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR256, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL256, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU256, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD256, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY256, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 256;
	return (0);
}

int	load128(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL128, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR128, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO128, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC128, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN128, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR128, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL128, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU128, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD128, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY128, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 128;
	return (0);
}

int	load64(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL64, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR64, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO64, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC64, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN64, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR64, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL64, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU64, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD64, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY64, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 64;
	return (0);
}

int	load32(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL32, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR32, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO32, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC32, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN32, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR32, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL32, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU32, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD32, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY32, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 32;
	return (0);
}

int	load16(t_ptr *ptr, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(ptr->mlx, WALL16, &img->size,
			&img->size);
	img->floor = mlx_xpm_file_to_image(ptr->mlx, FLOOR16, &img->size,
			&img->size);
	img->exit1 = mlx_xpm_file_to_image(ptr->mlx, EXITO16, &img->size,
			&img->size);
	img->exit0 = mlx_xpm_file_to_image(ptr->mlx, EXITC16, &img->size,
			&img->size);
	img->coin = mlx_xpm_file_to_image(ptr->mlx, COIN16, &img->size,
			&img->size);
	img->mc_r = mlx_xpm_file_to_image(ptr->mlx, MCR16, &img->size,
			&img->size);
	img->mc_l = mlx_xpm_file_to_image(ptr->mlx, MCL16, &img->size,
			&img->size);
	img->mc_u = mlx_xpm_file_to_image(ptr->mlx, MCU16, &img->size,
			&img->size);
	img->mc_d = mlx_xpm_file_to_image(ptr->mlx, MCD16, &img->size,
			&img->size);
	img->enemy = mlx_xpm_file_to_image(ptr->mlx, ENEMY16, &img->size,
			&img->size);
	if (!img->wall || !img->floor || !img->exit1 || !img->exit0 || !img->coin
		|| !img->mc_r || !img->mc_l || !img->mc_u || !img->mc_d || !img->enemy)
		return (1);
	img->size = 16;
	return (0);
}
