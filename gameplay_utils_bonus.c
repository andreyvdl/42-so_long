/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 13:28:24 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft/ft_printf.h"

int	move_up(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == '1')
		return (render_update(mstr, 2));
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == 'X')
		return (ft_printf("\e[1;31mYOU DIED💀\e[0m\n"), mlx_exit(mstr), 0);
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == 'C')
	{
		mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] = '0';
		mstr->map->mc[0]--;
		mstr->map->coin_count--;
	}
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == '0')
		mstr->map->mc[0]--;
	else if (mstr->map->map[mstr->map->mc[0] - 1][mstr->map->mc[1]] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (ft_printf("\e[1;36mCongratulations🥳\nTotal moves: %d\n",
					mstr->mc_mv + 1), mlx_exit(mstr), 0);
		mstr->map->mc[0]--;
	}
	mstr->mc_mv++;
	return (render_update(mstr, 2));
}

int	move_down(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == '1')
		return (render_update(mstr, 4));
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == 'X')
		return (ft_printf("\e[1;31mYOU DIED💀\e[0m\n"), mlx_exit(mstr), 0);
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == 'C')
	{
		mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] = '0';
		mstr->map->mc[0]++;
		mstr->map->coin_count--;
	}
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == '0')
		mstr->map->mc[0]++;
	else if (mstr->map->map[mstr->map->mc[0] + 1][mstr->map->mc[1]] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (ft_printf("\e[1;36mCongratulations🥳\nTotal moves: %d\n",
					mstr->mc_mv + 1), mlx_exit(mstr), 0);
		mstr->map->mc[0]++;
	}
	mstr->mc_mv++;
	return (render_update(mstr, 4));
}

int	move_left(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == '1')
		return (render_update(mstr, 1));
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == 'X')
		return (ft_printf("\e[1;31mYOU DIED💀\e[0m\n"), mlx_exit(mstr), 0);
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == 'C')
	{
		mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] = '0';
		mstr->map->mc[1]--;
		mstr->map->coin_count--;
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == '0')
		mstr->map->mc[1]--;
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] - 1] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (ft_printf("\e[1;36mCongratulations🥳\nTotal moves: %d\n",
					mstr->mc_mv + 1), mlx_exit(mstr), 0);
		mstr->map->mc[1]--;
	}
	mstr->mc_mv++;
	return (render_update(mstr, 1));
}

int	move_right(t_master *mstr)
{
	if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == '1')
		return (render_update(mstr, 3));
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == 'X')
		return (ft_printf("\e[1;31mYOU DIED💀\e[0m\n"), mlx_exit(mstr), 0);
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == 'C')
	{
		mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] = '0';
		mstr->map->mc[1]++;
		mstr->map->coin_count--;
	}
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == '0')
		mstr->map->mc[1]++;
	else if (mstr->map->map[mstr->map->mc[0]][mstr->map->mc[1] + 1] == 'E')
	{
		if (mstr->map->coin_count == 0)
			return (ft_printf("\e[1;36mCongratulations🥳\nTotal moves: %d\n",
					mstr->mc_mv + 1), mlx_exit(mstr), 0);
		mstr->map->mc[1]++;
	}
	mstr->mc_mv++;
	return (render_update(mstr, 3));
}
