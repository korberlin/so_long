/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:08:59 by gkoksal           #+#    #+#             */
/*   Updated: 2024/03/27 14:11:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rotate_chr(t_game *game, int keycode)
{
	if (keycode == 115)
		game->chr->current = game->chr->front;
	if (keycode == 119)
		game->chr->current = game->chr->back;
	if (keycode == 100)
		game->chr->current = game->chr->right;
	if (keycode == 97)
		game->chr->current = game->chr->left;
}

static void	move_chr(t_game *game, int key, int x, int y)
{
	if (game->map->collect == 0 && game->map->mapfill[y / 32][x / 32] == 'E')
	{
		game->chr->points++;
		ft_printf("You have moved %d times\n", game->chr->points);
		ft_printf("Win\n");
		destroy_game(game);
	}
	if (game->map->mapfill[y / 32][x / 32] != '1'
		&& game->map->mapfill[y / 32][x / 32] != 'E')
	{
		rotate_chr(game, key);
		if (game->map->mapfill[y / 32][x / 32] == 'C')
			game->map->collect--;
		game->map->mapfill[y / 32][x / 32] = 'P';
		game->map->mapfill[game->chr->y / 32][game->chr->x / 32] = '0';
		game->chr->points++;
		ft_printf("You have moved %d times\n", game->chr->points);
	}
}

int	move(int keycode, void *parameter)
{
	t_game	*game;

	game = parameter;
	mlx_clear_window(game->mlx, game->win);
	if (keycode == 119)
		move_chr(game, keycode, game->chr->x, game->chr->y -32);
	if (keycode == 115)
		move_chr(game, keycode, game->chr->x, game->chr->y +32);
	if (keycode == 100)
		move_chr(game, keycode, game->chr->x +32, game->chr->y);
	if (keycode == 97)
		move_chr(game, keycode, game->chr->x -32, game->chr->y);
	if (keycode == 65307)
		destroy_game(game);
	render_map(game);
	return (keycode);
}
