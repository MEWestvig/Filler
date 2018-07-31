/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:25:54 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/31 22:57:01 by mwestvig         ###   ########.fr       */
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

void	top_algo(t_piece *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->num_pos)
	{
		p->pos[i][2] = dst(0, 0, p->pos[i][0], p->pos[i][1]);
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

void	left_algo(t_piece *p, t_map *m)
{
	int i;
	int j;

	i = 0;
	while (i < p->num_pos)
	{
		p->pos[i][2] = dst(0, m->map_y, p->pos[i][0], p->pos[i][1]);
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

void	minialgo(t_map *m, t_piece *p)
{
	if (m->map_x <= 20)
	{
		if (!check_top(m))
			left_algo(p, m);
		else
			m->mini = 0;
	}
	else if (m->map_x <= 40)
	{
		if (!check_top(m))
			top_algo(p);
		else
			m->mini = 0;
	}
	if (m->mini == 0)
		algo(m, p);
}
