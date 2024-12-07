/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:08:40 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/11 16:21:35 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**fill_map(t_map *map, int *x, int *y)
{
	char	**floodfill_map;
	int		i;
	int		j;

	floodfill_map = malloc(sizeof(char *) * (map->height + 1));
	floodfill_map[map->height] = NULL;
	i = -1;
	while (++i < map->height)
	{
		floodfill_map[i] = malloc(map->width + 1);
		j = -1;
		while (map->mapfill[i][++j])
		{
			if (map->mapfill[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			floodfill_map[i][j] = map->mapfill[i][j];
		}
		floodfill_map[i][j] = '\0';
	}
	return (floodfill_map);
}

static int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

static void	free2darray(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

static void	fill_algorithm(char **floodfill_map, int x, int y, int *reachables)
{
	int	height;
	int	width;

	width = ft_strlen(floodfill_map[0]);
	height = ft_strlen2d(floodfill_map);
	if (x < 0 || x >= height || y < 0 || y >= width
		|| floodfill_map[x][y] == '1' || floodfill_map[x][y] == 'v')
		return ;
	if (floodfill_map[x][y] == 'C' || floodfill_map[x][y] == 'E')
		(*reachables)++;
	floodfill_map[x][y] = 'v';
	fill_algorithm(floodfill_map, x + 1, y, reachables);
	fill_algorithm(floodfill_map, x - 1, y, reachables);
	fill_algorithm(floodfill_map, x, y + 1, reachables);
	fill_algorithm(floodfill_map, x, y - 1, reachables);
}

void	flood_fill(t_game *game, t_map *map)
{
	char	**floodfill_map;
	int		reachables;
	int		x;
	int		y;

	reachables = 0;
	x = 0;
	y = 0;
	floodfill_map = fill_map(map, &x, &y);
	fill_algorithm(floodfill_map, x, y, &reachables);
	free2darray(floodfill_map);
	if (map->collect + 1 != reachables)
	{
		ft_printf("Error \nPlease provide a valid map.\n");
		free_game_map(game, map);
		exit(1);
	}
}
