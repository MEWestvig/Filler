/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:39:55 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/10 11:48:08 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		legal_pos(t_map *map, t_piece *piece, int i, int j)
{
}

int		count_pos(t_map *map, t_piece *piece)
{
	int num_pos;
	int i;
	int j;

	num_pos = 0;
	i = 0;
	j = 0;
	while (i++ < map->map_y)
		while (j++ < map->map_x)
			if (legal_pos(map, piece, i, j))
				num_pos++;
	return (num_pos);
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
