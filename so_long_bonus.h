/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/11 17:40:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <string.h> //strerror
# include <stdlib.h> //exit
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "so_long_def_bonus.h"
# include "so_long_strct_bonus.h"

// errors.c functions
void	print_error(char *local, int n);

// frees.c functions
void	free_map(t_map *map);
void	free_ptrs(t_ptr *ptrs);
void	free_copy(t_map *map, char **map_copy);
void	free_textures(t_ptr *ptrs, t_img *img);

// gameplay.c functions
int		mlx_exit(t_master *mstr);
int		render_update(t_master *mstr);
int		key_pressed(int keycode, t_master *mstr);
void	gameplay(t_map *map, t_ptr *ptrs, t_img *img);

// gameplay_utils.c functions
int		move_up(t_master *mstr);
int		move_down(t_master *mstr);
int		move_left(t_master *mstr);
int		move_right(t_master *mstr);

// mlx_begin.c functions
int		load_textures(t_ptr *ptr, t_img *img);
int		mlx_start(t_map *map, t_ptr *ptr, t_img *img);

// render.c functions
void	put_player(t_map *map, t_ptr *ptrs, t_img *img);
void	put_images(t_map *map, t_ptr *ptrs, t_img *img, size_t y);

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