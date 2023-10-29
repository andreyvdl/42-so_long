/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/29 00:22:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <string.h> //strerror
# include <stdlib.h> //exit
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "so_long_def_bonus.h"
# include "so_long_strct_bonus.h"

// errors_bonus.c function
void	print_error(char *local, int n);

// frees_bonus.c functions
void	free_map(t_map *map);
void	free_copy(t_map *map, char **map_copy);
void	free_textures(t_ptr *ptrs, t_img *img);

// gameplay_bonus.c functions
void	gameplay(t_master *mstr);
int		mlx_exit(t_master *mstr);
int		render_update(t_master *mstr, int side);
int		key_pressed(int keycode, t_master *mstr);

// gameplay_utils_bonus.c functions
int		move_up(t_master *mstr);
int		move_down(t_master *mstr);
int		move_left(t_master *mstr);
int		move_right(t_master *mstr);

// load_textures_bonus.c functions
int		load64(t_ptr *ptr, t_img *img);
int		load32(t_ptr *ptr, t_img *img);
int		load16(t_ptr *ptr, t_img *img);
int		load128(t_ptr *ptr, t_img *img);
int		load256(t_ptr *ptr, t_img *img);

// mlx_begin_bonus.c functions
int		load8(t_ptr *ptr, t_img *img);
int		mlx_start(t_map *map, t_ptr *ptr, t_img *img);
int		load_textures(t_ptr *ptr, t_img *img, t_map *map);

// render_bonus.c functions
void	put_images(t_master *mstr, int side);
void	enemies(t_map *map, t_ptr *ptrs, t_img *img);
void	coins_n_exit(t_map *map, t_ptr *ptrs, t_img *img);
void	walls_n_floors(t_map *map, t_ptr *ptrs, t_img *img);
void	put_player(t_map *map, t_ptr *ptrs, t_img *img, int side);

// so_long_bonus.c functions
void	credits(void);

// verify_file_bonus.c functions
void	validate_file(char *file, t_map *map);

// verify_map_bonus.c functions
void	file2matrix(t_map *map);
int		validate_map(t_map *map);
int		get_map_size(t_map *map);
int		map_is_valid(t_map *map);
int		map_is_closed(t_map *map);

// verify_map_utils_bonus.c functions
int		backtracking(t_map *map);
void	flowage(char **map, size_t y, size_t x);
int		locate_references(t_map *map, size_t y, size_t x);

#endif
