/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:03:15 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/09 12:06:17 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	ft_player(t_map *map, t_piece *piece)
{
	char	*line;
	int		player;

	get_next_line(0, &line);
	player = ft_atoi(ft_strchr(line, 'p'));
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
	while(ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while(ft_isdigit(line[i]))
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
	while(ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while(ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	piece->piece_x = x;
	piece->piece_y = y;
}

void	ft_piece(t_piece *piece)
{
	char	*line;
	int		piece_line;

	get_next_line(0, &line);
	ft_piecesize(piece, line);
	ft_strdel(&line);
	piece->piece = (char **)malloc(sizeof(char *) * piece->piece_y + 1);
	piece_line = 0;
	while (piece_line < piece->piece_y)
	{
		get_next_line(0, &line);
		piece->piece[piece_line] = (char *)malloc(sizeof(char) * piece->piece_x + 1);
		piece->piece[piece_line] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
		piece_line++;
	}
}

void	set_info(t_map *map, t_piece *piece)
{
	ft_player(map, piece);
	ft_map(map);
	ft_piece(piece);
}
