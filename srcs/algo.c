/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:30:26 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/31 13:27:55 by mwestvig         ###   ########.fr       */
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
			if (ft_toupper(m->map[i][j]) == m->e_p && m->map_x > 40)
				return (0); 
			j++;
		}
		i++;
	}
	return (1);
}

int		decide(t_map *m, t_piece *p)
{
	int i;
	int pl1;
	int pl2;

	i = 0;
	pl1 = 0;
	pl2 = 1;
	if (m->map_x * m->map_y <= 960 && m->mini == 1 && m->player == 2)
	{
		minialgo(m, p);
		return ;
	}
	if (above_below(m) == 0)
	{
		pl1 = 3;
		pl2 = 4;
	}
	while (i < p->num_pos)
	{
		p->pos[i][2] = shortest_dist(m, p, i, pl1, pl2);
		i++;
	}
}

void	algo(t_map *m, t_piece *p)
{
	int i;
	int j;
	int pl1;
	int pl2;

	p->place = (int *)malloc(sizeof(int) * 2);
	//if decide is 1 done mini, if decide is 0, do normal.
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
