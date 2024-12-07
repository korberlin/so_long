/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:09 by gkoksal           #+#    #+#             */
/*   Updated: 2024/07/30 18:28:50 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_img(t_game *game, int w, int h)
{
	game->height = game->map->height * 32;
	game->width = game->map->width * 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height,
			"so_long");
	game->bg = mlx_xpm_file_to_image(game->mlx, "./img/bg.xpm", &w, &h);
	game->block = mlx_xpm_file_to_image(game->mlx, "./img/block.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm",
			&w, &h);
	game->end = mlx_xpm_file_to_image(game->mlx, "./img/end.xpm", &w, &h);
	game->open = mlx_xpm_file_to_image(game->mlx, "./img/opened.xpm", &w, &h);
	game->chr = ft_calloc(1, sizeof(t_char));
	game->chr->x = 0;
	game->chr->y = 0;
	game->chr->points = 0;
	game->chr->right = mlx_xpm_file_to_image(game->mlx, "./img/right.xpm",
			&w, &h);
	game->chr->left = mlx_xpm_file_to_image(game->mlx, "./img/left.xpm",
			&w, &h);
	game->chr->back = mlx_xpm_file_to_image(game->mlx, "./img/back.xpm",
			&w, &h);
	game->chr->front = mlx_xpm_file_to_image(game->mlx, "./img/front.xpm",
			&w, &h);
	game->chr->current = game->chr->front;
}

static void	print_score(t_game *game)
{
	char	*points;
	int		middle;

	middle = (game->map->width / 2) * 32;
	points = ft_itoa(game->chr->points);
	mlx_set_font(game->mlx, game->win, GAME_FONT);
	mlx_string_put(game->mlx, game->win, middle, 20, 0xFF000000, points);
	free(points);
}

static void	render_elements(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->bg, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->block, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x, y);
	else if (c == 'E')
	{
		game->map->endx = x;
		game->map->endy = y;
		if (game->map->collect > 0)
			mlx_put_image_to_window(game->mlx, game->win, game->end, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->open, x, y);
	}
	else if (c == 'P')
	{
		game->chr->x = x;
		game->chr->y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->chr->current, x, y);
	}
	print_score(game);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (game->map->mapfill[++i])
	{
		j = -1;
		x = 0;
		while (game->map->mapfill[i][++j])
		{
			render_elements(game, game->map->mapfill[i][j], x, y);
			x += 32;
		}
		y += 32;
	}
}

void	render_game(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	fill_img(game, w, h);
	render_map(game);
}
