/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:25:54 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/26 11:56:00 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	//if map00 (less than 260) go left and then to top corner.
	//prioritise getting to the left side and then start aiming for 0,0
	if (!check_left(m))
	{
		//move towards left
	}
	else if (!check_top(m))
	{
		//move towards 0,0
	}
	else
	{
		//move towards the enemy.
	}
}
