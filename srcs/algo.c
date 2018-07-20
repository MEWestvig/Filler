/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:30:26 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/19 19:49:30 by mwestvig         ###   ########.fr       */
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

int		shortest_dist(t_map *m, t_piece *p, int i)
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
				dist = distance(b, a, p->pos[i][1], p->pos[i][0]);
				if (dist < shortest)
					shortest = dist;
			}
			b++;
		}
		a++;
	}
	return (shortest);
}

void	algo(t_map *m, t_piece *p)
{
	int i;
	int j;

	p->place = (int *)malloc(sizeof(int) * 2);
	i = 0;
	while (i < p->num_pos)
	{
		p->pos[i][2] = shortest_dist(m, p, i);
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
