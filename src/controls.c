/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:21:23 by gkoksal           #+#    #+#             */
/*   Updated: 2024/04/11 13:33:53 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_open(t_game *game)
{
	int	opened;

	opened = open("./img/opened.xpm", O_RDWR);
	if (opened < 0)
	{
		close(opened);
		ft_printf("Error\nMissing an image file\n");
		free(game);
		exit(1);
	}
	close(opened);
}

void	check_img(t_game *game)
{
	int	bg;
	int	block;
	int	collect;
	int	end;

	bg = open("./img/bg.xpm", O_RDWR);
	block = open("./img/block.xpm", O_RDWR);
	collect = open("./img/collect.xpm", O_RDWR);
	end = open("./img/end.xpm", O_RDWR);
	check_open(game);
	if (bg < 0 || block < 0 || collect < 0 || end < 0)
	{
		close(bg);
		close(block);
		close(collect);
		close(end);
		ft_printf("Error\nMissing an image file\n");
		free(game);
		exit(1);
	}
	close(bg);
	close(block);
	close(collect);
	close(end);
}

void	check_chr(t_game *game)
{
	int	back;
	int	front;
	int	left;
	int	right;

	back = open("./img/back.xpm", O_RDWR);
	front = open("./img/front.xpm", O_RDWR);
	left = open("./img/left.xpm", O_RDWR);
	right = open("./img/right.xpm", O_RDWR);
	if (back < 0 || front < 0 || left < 0 || right < 0)
	{
		close(back);
		close(front);
		close(left);
		close(right);
		ft_printf("Error\nMissing an image file\n");
		free(game);
		exit(1);
	}
	close(back);
	close(front);
	close(left);
	close(right);
}

static void	check_empty_map(t_game *game, int fd)
{
	char	buff;

	if (read(fd, &buff, 1) == 0)
	{
		ft_printf("Error \nPlease provide a valid map.\n");
		free(game);
		exit(1);
	}
}

void	check_path(t_game *game, char *map)
{
	int	len;
	int	fd;

	len = 0;
	while (map[len])
		len++;
	if (map[len - 4] != '.' || map[len - 3] != 'b' || map[len - 2] != 'e'
		|| map[len - 1] != 'r')
	{
		ft_printf("Error\nIncorrect map extension (.ber)\n");
		free(game);
		exit(1);
	}
	fd = open(map, O_RDWR);
	if (fd < 0)
	{
		ft_printf("Error\nIncorrect path\n");
		close(fd);
		free(game);
		exit(1);
	}
	check_empty_map(game, fd);
	close(fd);
}
