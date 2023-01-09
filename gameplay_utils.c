/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/09 14:34:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/ft_printf.h"

int	move_up(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == '1')
		;
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == 'C')
	{
		mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] = '0';
		mstr->map->mc[0]--;
		mstr->map->coin_count--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == '0')
	{
		mstr->map->mc[0]--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (mlx_destroy_window(mstr->ptr->mlx, mstr->ptr->win),
				ft_printf("Total moves: %d", ((int)++mstr->mc_mv)), 0);
		mstr->map->mc[0]--;
		mstr->mc_mv++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	return (0);
}

int	move_down(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == '1')
		;
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == 'C')
	{
		mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] = '0';
		mstr->map->mc[0]++;
		mstr->map->coin_count--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == '0')
	{
		mstr->map->mc[0]++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (mlx_destroy_window(mstr->ptr->mlx, mstr->ptr->win),
				ft_printf("Total moves: %d", ((int)++mstr->mc_mv)), 0);
		mstr->map->mc[0]++;
		mstr->mc_mv++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	return (0);
}

int	move_left(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == '1')
		;
	elseif (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == 'C')
	{
		mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] = '0';
		mstr->map->mc[1]--;
		mstr->map->coin_count--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == '0')
	{
		mstr->map->mc[1]--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (mlx_destroy_window(mstr->ptr->mlx, mstr->ptr->win),
				ft_printf("Total moves: %d", ((int)++mstr->mc_mv)), 0);
		mstr->map->mc[1]--;
		mstr->mc_mv++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	return (0);
}

int	move_right(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == '1')
		;
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == 'C')
	{
		mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] = '0';
		mstr->map->mc[1]++;
		mstr->map->coin_count--;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[0] + 1] == '0')
	{
		mstr->map->mc[1]++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (mlx_destroy_window(mstr->ptr->mlx, mstr->ptr->win),
				ft_printf("Total moves: %d", ((int)++mstr->mc_mv)), 0);
		mstr->map->mc[1]++;
		mstr->mc_mv++;
		ft_printf("Moves: %d", ((int)++mstr->mc_mv));
	}
	return (0);
}
