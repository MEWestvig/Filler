/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:39:55 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/09 17:02:19 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_pos(t_map *map, t_piece *piece)
{
}

void	set_positions(t_map *map, t_piece *piece)
{
}

void	check_positions(t_map *map, t_piece *piece)
{
	int positions;
	int i;

	i = 0;
	positions = count_pos(map, piece);
	piece->pos = (int **)malloc(sizeof(int *) * positions + 1);
	while (i < positions)
	{
		piece->pos[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	set_positions(map, piece);
}
