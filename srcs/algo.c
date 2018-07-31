/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:30:26 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/31 22:38:11 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		dst(int ex, int ey, int mx, int my)
{
	int sq_diff_x;
	int sq_diff_y;
	int dist;

	sq_diff_x = (ex - mx) * (ex - mx);
	sq_diff_y = (ey - my) * (ey - my);
	dist = sq_diff_x + sq_diff_y;
	return (dist);
}

int		shortest_dist(t_map *m, t_piece *p, int i, int *pl)
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
				dist = dst(a, b, p->pos[i][pl[0]], p->pos[i][pl[1]]);
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
			if (ft_toupper(m->map[i][j]) == m->e_p && m->map_x > 40)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	algo(t_map *m, t_piece *p)
{
	int i;
	int j;
	int *pl;

	pl = (int *)malloc(sizeof(int) * 2);
	p->place = (int *)malloc(sizeof(int) * 2);
	pl[0] = 0;
	i = -1;
	j = 0;
	if (m->map_x <= 40 && m->mini == 1 && m->player == 2)
		minialgo(m, p);
	else
	{
		if (above_below(m) == 0)
			pl[0] = 3;
		pl[1] = pl[0] + 1;
		while (++i < p->num_pos)
		{
			p->pos[i][2] = shortest_dist(m, p, i, pl);
			if (p->pos[i][2] < p->pos[j][2])
				j = i;
		}
		p->place[0] = p->pos[j][0];
		p->place[1] = p->pos[j][1];
	}
}
