/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:05:24 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/03 14:14:26 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit (1);
	check_img(game);
	check_chr(game);
	check_path(game, path);
	game->map = read_map(path, game);
	render_game(game);
	mlx_hook(game->win, 2, (1L << 0), move, game);
	mlx_hook(game->win, 17, 0, destroy_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
	{
		ft_printf("Error\nThis game only takes one argument.\n");
		return (1);
	}
}
