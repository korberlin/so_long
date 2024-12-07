/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:24 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/03 11:14:39 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game_map(t_game *game, t_map *map)
{
	int	i;

	i = -1;
	while (map->mapfill[++i] != NULL)
		free(map->mapfill[i]);
	free(map->mapfill);
	free(map);
	free(game);
	exit(1);
}

int	destroy_game(void *arg)
{
	t_game	*game;

	game = arg;
	mlx_destroy_image(game->mlx, game->chr->front);
	mlx_destroy_image(game->mlx, game->chr->back);
	mlx_destroy_image(game->mlx, game->chr->left);
	mlx_destroy_image(game->mlx, game->chr->right);
	free(game->chr);
	mlx_destroy_image(game->mlx, game->bg);
	mlx_destroy_image(game->mlx, game->block);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->end);
	mlx_destroy_image(game->mlx, game->open);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game_map(game, game->map);
	return (1);
}
