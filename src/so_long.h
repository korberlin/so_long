/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:06:42 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/11 15:25:32 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <../libft/libft.h>
# include <../gnl/get_next_line.h>
# include <../printf/ft_printf.h>

# define GAME_FONT "-misc-fixed-medium-r-normal--20-200-75-75-c-100-iso10646-1"

typedef struct s_chr
{
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*current;
	int		x;
	int		y;
	int		points;
}	t_char;

typedef struct s_map
{
	char	**mapfill;
	int		height;
	int		width;
	int		player;
	int		collect;
	int		end;
	int		endx;
	int		endy;
}	t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	void	*bg;
	void	*block;
	void	*open;
	void	*collect;
	void	*end;
	int		height;
	int		width;
	t_map	*map;
	t_char	*chr;
}	t_game;

void	check_chr(t_game *game);
void	check_img(t_game *game);
void	check_path(t_game *game, char *map);
void	so_long(char *path);
t_map	*read_map(char *path, t_game *game);
void	flood_fill(t_game *game, t_map *map);
void	render_game(t_game *game);
void	render_map(t_game *game);
void	free_game_map(t_game *game, t_map *map);
int		move(int keycode, void *parameter);
int		destroy_game(void *arg);

#endif
