/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitestx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:15:07 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/06 17:45:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compile with the flags -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
#include "minilibx-linux/mlx.h"
#include "includes/ft_printf.h"
#include "includes/gnl.h"
#include "includes/libft.h"
#include <string.h> //strerror
#include <stdlib.h> //exit
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

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

void	softlocked(char **map, size_t y, size_t x);
int		play_map(t_map *map);
int		check_corners(t_map *map);
int		locate_mc_exit_corners(t_map *map, size_t y, size_t x);
int		cp_map(t_map *map, char *line, int y);
int		mapping(t_map *map);
int		validate_map(t_map *map);
void	validate_file(char *file, t_map *map);
void	print_error(char *local, int n);
void	free_copy(t_map *map, char **copy);
int		free_map(t_map *map);

// int	deal_key(int key, t_pointers *param)
// {
// 	ft_printf("key: %d\n", key);
// 	return (1);
// }

void	print_error(char *local, int n)
{
	if (n == 22 || n == 53)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Usage: ./so_long <filename>.ber\n");
		exit(n);
	}
	else if (n == 59)
	{
		ft_printf("Error\n❌Map isn't valid. RTFM or call dev!❌\n");
		exit(59);
	}
	ft_printf("%s: %s\n", local, strerror(n));
	exit(n);
}

void	validate_file(char *file, t_map *map)
{
	int	fd;
	int	i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".ber", 4))
		print_error("filename", 53);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		print_error("openning", 2);
	}
	map->name = file;
	map->fd = fd;
}

int	validate_map(t_map *map)
{
	map->x_mx = 0;
	map->mc_count = 0;
	map->exit_count = 0;
	if (mapping(map))
		return (free_map(map));
	close(map->fd);
	if (play_map(map))
		return (free_map(map));
	return (0);
}

int	mapping(t_map *map)
{
	size_t	y;
	char	*line;

	y = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (line[0] == '\n' || cp_map(map, line, y)
			|| (ft_strlen(line) != map->x_mx && map->x_mx != 0))
		{
			free(line);
			return (1);
		}
		if (!map->x_mx)
			map->x_mx = ft_strlen(line);
		free(line);
		y++;
	}
	map->y_mx = y;
	if (locate_mc_exit_corners(map, -1, -1))
		return (1);
	return (0);
}

int	cp_map(t_map *map, char *line, int y)
{
	size_t	x;

	x = -1;
	while (line[++x] != '\n')
	{
		if (ft_strnstr("01CEP", &line[x], 5))
			map->map[y][x] = line[x];
		else
			return (1);
	}
	map->map[y][x] = 0;
	return (0);
}

int	locate_mc_exit_corners(t_map *map, size_t y, size_t x)
{
	while (++y <= map->y_mx)
	{
		while (++x <= map->x_mx)
		{
			if (map->map[y][x] == 'P')
			{
				map->mc_count++;
				map->mc[0] = y;
				map->mc[1] = x;
				map->mc[2] = 0;
			}
			else if (map->map[y][x] == 'E')
			{
				map->exit_count++;
				map->exit[0] = y;
				map->exit[1] = x;
				map->exit[2] = 0;
			}
		}
	}
	if (map->mc_count > 1 || map->exit_count > 1 || check_corners(map))
		return (1);
	return (0);
}

int	check_corners(t_map *map)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (map->map[0][++x])
		if (map->map[0][x] != '1')
			return (1);
	x = -1;
	while (map->map[map->y_mx - 1][++x])
		if (map->map[map->y_mx - 1][x] != '1')
			return (1);
	y = -1;
	while (map->map[++y])
		if (map->map[y][0] != '1' || map->map[y][map->x_mx - 1] != '1')
			return (1);
	return (0);
}

int	play_map(t_map *map)
{
	static char	**map_copy = map->map;
	size_t		y;

	y = -1;
	softlocked(map_copy, map->mc[0], map->mc[1]);
	while (++y < map->y_mx)
	{
		if (ft_strnstr(map_copy[y], "0CE", map->x_mx))
		{
			free_copy(map, map_copy);
			return (1);
		}
	}
	y = -1;
	while (++y < map->y_mx)
		free(map_copy[y]);
	free(map_copy);
	return (0);
}

void	free_copy(t_map *map, char **map_copy)
{
	size_t	y;

	y = -1;
	while (++y < map->y_mx)
		free(map_copy[y]);
	free(map_copy);
}

int	free_map(t_map *map)
{
	size_t	y;

	y = -1;
	while (++y < map->y_mx)
		free(map->map[y]);
	free(map->map);
	return (1);
}

void	softlocked(char **map, size_t y, size_t x)
{
	if (ft_strnstr("0EPC", &map[y][x], 4))
		map[y][x] = 'X';
	if (!ft_strnstr("1X", &map[y + 1][x], 2))
		softlocked(map, y + 1, x);
	else if (!ft_strnstr("1X", &map[y][x - 1], 2))
		softlocked(map, y, x - 1);
	else if (!ft_strnstr("1X", &map[y - 1][x], 2))
		softlocked(map, y - 1, x);
	else if (!ft_strnstr("1X", &map[y][x + 1], 2))
		softlocked(map, y, x + 1);
}

int	main(int ac, char **av)
{
	t_map		map;
	// t_pointers	ptrs;
	// t_img		img;

	if (ac != 2)
		print_error("argument", 22);
	validate_file(av[1], &map);
	if (validate_map(&map))
	{
		close(map.fd);
		print_error("map", 59);
	}
	ft_printf("\e[44mLoading game...🎮\e[0m\n");
	// game_start(&ptrs, &map); //256: 5x3 128: 10x6 64: 20x12 32: 40x24 16: 80x48 8: 160x96
	// mlx_put_image_to_window(ptrs.mlx, ptrs.win, ptrs.img, 400, 300);
	// mlx_loop(ptrs.mlx);
	// credits(&ptrs, &map, &img);
}
