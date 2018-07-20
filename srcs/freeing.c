/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:17:09 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/20 11:43:50 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->map_y)
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
}

void	free_piece(t_piece *p)
{
	int i;

	i = 0;
	while (i < p->piece_y)
	{
		free(p->piece[i]);
		i++;
	}
	free(p->piece);
}
