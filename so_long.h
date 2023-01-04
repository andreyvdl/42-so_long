/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/04 15:06:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COIN8 "textures/coin8.xpm"
# define WALL8 "textures/wall8.xpm"
# define MCU8 "textures/kirbyU8.xpm"
# define MCD8 "textures/kirbyD8.xpm"
# define MCL8 "textures/kirbyL8.xpm"
# define MCR8 "textures/kirbyR8.xpm"
# define FLOOR8 "textures/ground8.xpm"
# define EXITO8 "textures/exitOpen8.xpm"
# define EXITC8 "textures/exitClose8.xpm"

# define COIN16 "textures/coin16.xpm"
# define WALL16 "textures/wall16.xpm"
# define MCU16 "textures/kirbyU16.xpm"
# define MCD16 "textures/kirbyD16.xpm"
# define MCL16 "textures/kirbyL16.xpm"
# define MCR16 "textures/kirbyR16.xpm"
# define FLOOR16 "textures/ground16.xpm"
# define EXITO16 "textures/exitOpen16.xpm"
# define EXITC16 "textures/exitClose16.xpm"

# define COIN32 "textures/coin32.xpm"
# define WALL32 "textures/wall32.xpm"
# define MCU32 "textures/kirbyU32.xpm"
# define MCD32 "textures/kirbyD32.xpm"
# define MCL32 "textures/kirbyL32.xpm"
# define MCR32 "textures/kirbyR32.xpm"
# define FLOOR32 "textures/ground32.xpm"
# define EXITO32 "textures/exitOpen32.xpm"
# define EXITC32 "textures/exitClose32.xpm"

# define COIN64 "textures/coin64.xpm"
# define WALL64 "textures/wall64.xpm"
# define MCU64 "textures/kirbyU64.xpm"
# define MCD64 "textures/kirbyD64.xpm"
# define MCL64 "textures/kirbyL64.xpm"
# define MCR64 "textures/kirbyR64.xpm"
# define FLOOR64 "textures/ground64.xpm"
# define EXITO64 "textures/exitOpen64.xpm"
# define EXITC64 "textures/exitClose64.xpm"

# define COIN128 "textures/coin128.xpm"
# define WALL128 "textures/wall128.xpm"
# define MCU128 "textures/kirbyU128.xpm"
# define MCD128 "textures/kirbyD128.xpm"
# define MCL128 "textures/kirbyL128.xpm"
# define MCR128 "textures/kirbyR128.xpm"
# define FLOOR128 "textures/ground128.xpm"
# define EXITO128 "textures/exitOpen128.xpm"
# define EXITC128 "textures/exitClose128.xpm"

# define COIN256 "textures/coin256.xpm"
# define WALL256 "textures/wall256.xpm"
# define MCU256 "textures/kirbyU256.xpm"
# define MCD256 "textures/kirbyD256.xpm"
# define MCL256 "textures/kirbyL256.xpm"
# define MCR256 "textures/kirbyR256.xpm"
# define FLOOR256 "textures/ground256.xpm"
# define EXITO256 "textures/exitOpen256.xpm"
# define EXITC256 "textures/exitClose256.xpm"

# include <mlx.h>
# include <string.h> //strerror
# include <stdlib.h> //exit
# include <unistd.h>
# include <fcntl.h>
# include <math.h>


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

//mlx_begin.c functions


#endif