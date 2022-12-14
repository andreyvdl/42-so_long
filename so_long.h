/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:10 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/14 12:53:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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
	void	*soil;
	void	*exit1;
	void	*exit0;
	void	*coin;
	void	*mc_u;
	void	*mc_d;
	void	*mc_l;
	void	*mc_r;
}	t_img;

// error.c functions
void	print_error(char *local, int n);

// frees.c functions
void	free_map(t_map *map);
void	free_copy(t_map *map, char **map_copy);

// verify_file.c functions
void	validate_file(char *file, t_map *map);

// verify_map.c functions
void	file2matrix(t_map *map);
int		validate_map(t_map *map);
int		get_map_size(t_map *map);
int		map_is_valid(t_map *map);
int		map_is_closed(t_map *map);

// verify_map_utils.c functions
int		backtracking(t_map *map);
void	flowage(char **map, size_t y, size_t x);
int		locate_references(t_map *map, size_t y, size_t x);

#endif