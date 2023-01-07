/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_strct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:33:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/07 15:34:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRCT_H
# define SO_LONG_STRCT_H

typedef struct s_ptr {
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_map {
	char	*name;
	char	**map;
	int		fd;
	size_t	x_mx;
	size_t	y_mx;
	size_t	mc[2];
	size_t	exit[2];
	char	*coin;
	size_t	mc_count;
	size_t	exit_count;
	size_t	coin_count;
}	t_map;

typedef struct s_img {
	int		size;
	void	*wall;
	void	*floor;
	void	*exit1;
	void	*exit0;
	void	*coin;
	void	*mc_r;
}	t_img;

#endif