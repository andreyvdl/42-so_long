/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:10 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/08 17:19:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <string.h> //strerror
# include <stdlib.h> //exit
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_pointers {
	void	*mlx;
	void	*win;
}	t_pointers;

typedef struct s_map {
	char	*name;
	char	**map;
	int		fd;
	size_t	x_mx;
	size_t	y_mx;
	size_t	mc[3];
	size_t	exit[3];
	char	*coin;
	int		mc_count;
	int		exit_count;
	int		coin_count;
}	t_map;

typedef struct s_img {
	int		size;
	void	*wall;
	void	*soil;
	void	*exit1;
	void	*exit0;
	void	*coin;
	void	*mc_u;
	void	*mc_d;
	void	*mc_l;
	void	*mc_r;
}	t_img;

int		mapping(t_map *map);
int		free_map(t_map *map);
int		play_map(t_map *map);
int		validate_map(t_map *map);
int		check_corners(t_map *map);
void	print_error(char *local, int n);
void	free_copy(t_map *map, char **copy);
int		cp_map(t_map *map, char *line, int y);
void	validate_file(char *file, t_map *map);
void	softlocked(char **map, size_t y, size_t x);
int		locate_mc_exit_corners(t_map *map, size_t y, size_t x);

#endif