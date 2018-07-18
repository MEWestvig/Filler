/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:30:26 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/18 11:04:04 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	distance(int ex, int ey, int mx, int my)
{
	int sq_diff_x;
	int sq_diff_y;
	int dist;

	sq_diff_x = (ex - mx) * (ex - mx);
	sq_diff_y = (ey - my) * (ey - my);
	dist = sq_diff_x + sq_diff_y;
	return (dist);
}

int shortest_dist(t_map *m, *t_piece *p, int i)
{
	int shortest;

	while (/*map*/)
		//check distance for each enemy piece against p->piece[i]
	return (shortest);
}

int	algo(t_map *m, t_piece *p)
{
	int i;
	int j;

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
	return (j);
}
