/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 23:59:02 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/01 00:45:13 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print(t_map *m, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (m->map_x > 200)
			++i;
		if (str[i] == m->e_p)
		{
			ft_putstr_fd("\033[31m", 2);
			ft_putstr_fd("\u2588", 2);
		}
		else if (str[i] == m->m_p)
		{
			ft_putstr_fd("\033[32m", 2);
			ft_putstr_fd("\u2588", 2);
		}
		else
		{
			ft_putstr_fd("\033[0m", 2);
			ft_putstr_fd(".", 2);
		}
	}
}

void	f(char *str, t_map *m, int size)
{
	int i;

	i = 0;
	while (i < (size - m->map_x) / 2)
	{
		ft_putchar_fd(' ', 2);
		i++;
	}
	print(m, str);
}

void	visual(t_map *m)
{
	struct ttysize	ts;
	int				i;
	int				size;

	i = -1;
	ioctl(2, TIOCGWINSZ, &ts);
	ft_putstr_fd("\e[1;1H", 2);
	size = m->map_y;
	if (m->map_y > 40)
		size /= 2;
	while (++i < (ts.ts_lines - size) / 2)
		ft_putchar_fd('\n', 2);
	i = -1;
	while (++i < m->map_y)
	{
		if (m->map_y > 40)
			++i;
		f(m->map[i], m, (int)ts.ts_cols);
		ft_putstr_fd("\033[0m\n", 2);
	}
}
