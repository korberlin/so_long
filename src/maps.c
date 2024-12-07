/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:41 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/11 15:25:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map_height(char *path, t_map *map)
{
	char	*str;
	int		fd;

	map->height = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->height++;
		free(str);
		str = NULL;
	}
	free(str);
	map->mapfill = malloc(sizeof(char *) * (map->height + 1));
	map->mapfill[map->height] = NULL;
	close(fd);
}

static void	read_map_width(char *path, t_map *map)
{
	char	*str;
	int		fd;
	int		i;
	int		j;

	i = -1;
	fd = open(path, O_RDONLY);
	while (++i < map->height)
	{
		str = get_next_line(fd);
		map->mapfill[i] = malloc(ft_strlen(str) + 1);
		j = -1;
		while (str[++j] && str[j] != '\n')
			map->mapfill[i][j] = str[j];
		map->mapfill[i][j] = '\0';
		free(str);
		str = NULL;
	}
	close(fd);
}

static int	validate_entry(t_map *map, char c, int i, int j)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '1' && c != '0')
	{
		ft_printf("Error \nPlease provide a valid map.\n");
		return (1);
	}
	if ((i == 0 || j == 0 || i == map->height -1
			|| j == map->width) && (c != '1'))
	{
		ft_printf("Error \nPlease provide a valid map.\n");
		return (1);
	}
	if (c == 'C')
		map->collect++;
	if (c == 'P')
		map->player++;
	if (c == 'E')
		map->end++;
	return (0);
}

static void	validate_map(t_map *map, t_game *game)
{
	int	i;
	int	len;
	int	j;

	map->collect = 0;
	map->player = 0;
	map->end = 0;
	len = ft_strlen(map->mapfill[0]);
	map->width = len;
	i = -1;
	while (++i < map->height)
	{
		if ((int)ft_strlen(map->mapfill[i]) != len)
		{
			ft_printf("Error \nPlease provide a valid map.\n");
			free_game_map(game, map);
			exit(1);
		}
		j = -1;
		while (map->mapfill[i][++j])
		{
			if (validate_entry(map, map->mapfill[i][j], i, j) == 1)
				free_game_map(game, map);
		}
	}
}

t_map	*read_map(char *path, t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	read_map_height(path, map);
	read_map_width(path, map);
	validate_map(map, game);
	if (map->collect == 0 || map->player != 1 || map->end != 1)
	{
		ft_printf("Error \nPlease provide a valid map.\n");
		free_game_map(game, map);
		exit(1);
	}
	flood_fill(game, map);
	return (map);
}
