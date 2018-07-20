/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:30:26 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/20 13:01:29 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		distance(int ex, int ey, int mx, int my)
{
	int sq_diff_x;
	int sq_diff_y;
	int dist;

	sq_diff_x = (ex - mx) * (ex - mx);
	sq_diff_y = (ey - my) * (ey - my);
	dist = sq_diff_x + sq_diff_y;
	return (dist);
}

int		shortest_dist(t_map *m, t_piece *p, int i, int pl1, int pl2)
{
	int a;
	int b;
	int shortest;
	int dist;

	a = 0;
	shortest = 2147483647;
	while (a < m->map_y)
	{
		b = 0;
		while (b < m->map_x)
		{
			if (ft_toupper(m->map[a][b]) == m->e_p)
			{
				dist = distance(b, a, p->pos[i][pl1], p->pos[i][pl2]);
				if (dist < shortest)
					shortest = dist;
			}
			b++;
		}
		a++;
	}
	return (shortest);
}

int		above_below(t_map *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (ft_toupper(m->map[i][j]) == m->m_p)
				return (1);
			if (ft_toupper(m->map[i][j]) == m->e_p)
				return (0); 
			j++;
		}
		i++;
	}
	return (5);
}

void	algo(t_map *m, t_piece *p)
{
	int i;
	int j;
	int pl1;
	int pl2;

	p->place = (int *)malloc(sizeof(int) * 2);
	i = 0;
	if (above_below(m) == 1)
	{
		pl1 = 0;
		pl2 = 1;
	}
	else if (above_below(m) == 0)
	{
		pl1 = 3;
		pl2 = 4;
	}
	else
	{
		fprintf(stderr, "Get your shit together");
		fflush(stderr);
	}	
	while (i < p->num_pos)
	{
		p->pos[i][2] = shortest_dist(m, p, i, pl1, pl2);
		i++;
	}
	i = 0;
	j = 0;
	while (i < p->num_pos)
	{
		if (p->pos[i][2] < p->pos[j][2])
			j = i;
		i++;
	}
	p->place[0] = p->pos[j][0];
	p->place[1] = p->pos[j][1];
}
