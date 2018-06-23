/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:03:15 by mwestvig          #+#    #+#             */
/*   Updated: 2018/06/23 18:54:31 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	set_info(char **line, t_map map, t_piece piece, int fd)
{
	int i;
	int j;
	static int map_line;
	static int piece_line;

	i = 0;
	j = 0;
	map_line = 0;
	piece_line = 0;
	if (*line[0] == '$')
	{
		if (ft_strstr((const char *)*line, "p1") != NULL)
			map.player = 1;
		if (ft_strstr((const char *)*line, "p2") != NULL)
			map.player = 2;
		ft_putstr_fd("Player:", fd);
		ft_putnbr_fd(map.player, fd);
	}
	else if (*line[0] == 'P' && *line[1] == 'l')
	{
		int mx;
		int my;

		i = 0;
		mx = 0;
		my = 0;
		while (!(ft_isdigit(*line[i])))
			i++;
		while (ft_isdigit(*line[i]))
			{
				mx = mx * 10 + (*line[i] - '0');
				i++;
			}
		map.map_x = mx;
		while (!(ft_isdigit(*line[i])))
			i++;
		while (ft_isdigit(*line[i]))
			{
				my = my * 10 + (*line[i] - '0');
				i++;
			}
		map.map_y = my;
		ft_putstr_fd("Map Dimensions", fd);
		ft_putnbr_fd(map.map_x, fd);
		ft_putnbr_fd(map.map_y, fd);
	}
	else if (*line[0] == ' ' || *line[i] == '	')
	{
		return;
	}
	else if (ft_isdigit(*line[0]))
	{
		i = 0;
		j = 0;
		while(ft_isdigit(*line[i]))
			i++;
		while(*line[i] == ' ' || *line[i] == '	')
			i++;
		while(*line[i])
		{
			map.map[map_line][j] = *line[i];
			j++;
			i++;
		}
		ft_putendl_fd(map.map[map_line], fd);
		map_line++;
	}
	else if (*line[0] == 'P' && *line[1] == 'i')
	{
		int px;
		int py;

		i = 0;
		px = 0;
		py = 0;
		while (!(ft_isdigit(*line[i])))
			i++;
		while (ft_isdigit(*line[i]))
			{
				px = px * 10 + (*line[i] - '0');
				i++;
			}
		piece.piece_x = px;
		while (!(ft_isdigit(*line[i])))
			i++;
		while (ft_isdigit(*line[i]))
			{
				py = py * 10 + (*line[i] - '0');
				i++;
			}
		piece.piece_y = py;
		ft_putstr_fd("Piece Dimensions", fd);
		ft_putnbr_fd(piece.piece_x, fd);
		ft_putnbr_fd(piece.piece_y, fd);
	}
	else if (*line[0] == '.' || *line[0] == '*')
	{
		while(*line[i])
		{
			piece.piece[piece_line][j] = *line[i];
			j++;
			i++;
		}
		ft_putendl_fd(piece.piece[piece_line], fd);
		piece_line++;
	}
}
