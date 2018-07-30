/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:25:54 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/26 17:54:07 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_top(t_map *m)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (ft_toupper(m->map[i][j]) == m->m_p)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_left(t_map *m)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < m->map_y)
		{
			if (ft_toupper(m->map[j][i]) == m->m_p)
				return (1);
			j++;
		}
		i++;
	} 
	return (0);
}

void	minialgo(t_map *m, t_piece *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!check_left(m))
	{
		while (i < p->num_pos)
		{
			p->pos[i][2] = distance((m->map_x - 1), 0, p->pos[i][0], p->pos[i][1]);
			i++;
		}
		i = 0;
		while (i < p->num_pos)
		{
			if (p->pos[i][2] < p->pos[j][2])
				j = i;
			i++;
		}
		p->place[0] = p->pos[j][0];
		p->place[1] = p->pos[j][1];
	}
	else if (!check_top(m))
	{
		while (i < p->num_pos)
		{
			p->pos[i][2] = distance(0, 0, p->pos[i][0], p->pos[i][1]);
			i++;
		}
		i = 0;
		while (i < p->num_pos)
		{
			if (p->pos[i][2] < p->pos[j][2])
				j = i;
			i++;
		}
		p->place[0] = p->pos[j][0];
		p->place[1] = p->pos[j][1];
	}
	else
	{
		m->mini = 0;
		algo(m, p);
	}
}
