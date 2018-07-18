/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:03:15 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/13 16:29:45 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	ft_player(t_map *map, t_piece *piece)
{
	char	*line;
	char	*p;
	int		player;

	get_next_line(0, &line);
	p = ft_strchr(line, 'p');
	p++;
	player = ft_atoi(p);
	if (player == 1)
	{
		map->m_p = 'O';
		map->e_p = 'X';
	}
	else if (player == 2)
	{
		map->m_p = 'X';
		map->e_p = 'O';
	}
	ft_strdel(&line);
}

void	ft_mapsize(t_map *map, char *line)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	map->map_x = x;
	map->map_y = y;
}

void	ft_map(t_map *map)
{
	char	*line;
	int		map_line;

	get_next_line(0, &line);
	ft_mapsize(map, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	map->map = (char **)malloc(sizeof(char *) * map->map_y + 1);
	map_line = 0;
	while (map_line < map->map_y)
	{
		get_next_line(0, &line);
		map->map[map_line] = (char *)malloc(sizeof(char) * map->map_x + 1);
		map->map[map_line] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
		map_line++;
	}
}

void	ft_piecesize(t_piece *piece, char *line)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	piece->piece_x = x;
	piece->piece_y = y;
}

void	ft_piece(t_piece *p)
{
	char	*line;
	int		piece_line;

	get_next_line(0, &line);
	ft_piecesize(p, line);
	ft_strdel(&line);
	p->piece = (char **)malloc(sizeof(char *) * p->piece_y + 1);
	piece_line = 0;
	while (piece_line < p->piece_y)
	{
		get_next_line(0, &line);
		p->piece[piece_line] = (char *)malloc(sizeof(char) * p->piece_x + 1);
		p->piece[piece_line] = ft_strdup((char const *)line);
		ft_strdel(&line);
		piece_line++;
	}
}
