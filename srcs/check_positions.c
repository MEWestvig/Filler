/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:39:55 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/20 12:41:43 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		legal_pos(t_map *m, t_piece *p, int i, int j)
{
	int count;
	int a;
	int b;

	count = 0;
	a = -1;
	while (++a < p->piece_y)
	{
		b = -1;
		while (++b < p->piece_x)
		{
			if (p->piece[a][b] == '*')
				if (a + i >= m->map_y || b + j >= m->map_x)
					return (0);
			if (p->piece[a][b] == '*')
				if (ft_toupper(m->map[i + a][j + b]) == m->m_p)
					count++;
			if (p->piece[a][b] == '*')
				if (ft_toupper(m->map[i + a][j + b]) == m->e_p)
					return (0);
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

int		count_pos(t_map *map, t_piece *piece)
{
	int num_pos;
	int i;
	int j;

	num_pos = 0;
	i = -1;
	while (++i < map->map_y)
	{
		j = -1;
		while (++j < map->map_x)
			if (legal_pos(map, piece, i, j))
				num_pos++;
	}
	return (num_pos);
}

void	set_positions(t_map *map, t_piece *piece)
{
	int i;
	int j;
	int a;

	i = 0;
	a = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			if (legal_pos(map, piece, i, j))
			{
				piece->pos[a][0] = i;
				piece->pos[a][1] = j;
				piece->pos[a][3] = i + piece->piece_x;
				piece->pos[a][4] = j + piece->piece_y;
				a++;
			}
			j++;
		}
		i++;
	}
}

int		check_positions(t_map *map, t_piece *piece)
{
	int i;

	i = 0;
	piece->num_pos = count_pos(map, piece);
	if (piece->num_pos == 0)
	{
		ft_putendl_fd("0 0", 1);
		return (1);
	}
	piece->pos = (int **)malloc(sizeof(int *) * piece->num_pos);
	while (i < piece->num_pos)
	{
		piece->pos[i] = (int *)malloc(sizeof(int) * 5);
		i++;
	}
	set_positions(map, piece);
	return (0);
}
