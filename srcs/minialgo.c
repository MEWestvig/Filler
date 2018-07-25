/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:25:54 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/25 14:33:05 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_top(t_map *m)
{
	//loop through first 2 rows until it hits one of my pieces and return, or return 0. 
	return (0);
}

int		check_left(t_map *m)
{
	//loop through first 2 columns until it hits one of my pieces and return, or return 0. 
	return (0);
}

void	minialgo(t_map *m, t_piece *p)
{
	if (m->up_left == 1)
	{
		if (!check_top(m))
			//do mini algo stuff
		else
			//do normal algo
	}
	if (m->up_left == -1)
	{
		if (!check_left(m))
			//do mini algo stuff
		else
			//do normal algo
	}
	m->up_left *= -1;
}
