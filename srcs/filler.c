/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:34:39 by mwestvig          #+#    #+#             */
/*   Updated: 2018/08/01 00:35:00 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initiate(t_map *map, t_piece *piece)
{
	map->map_x = 0;
	map->map_y = 0;
	map->map = NULL;
	map->player = 0;
	map->mini = 1;
	piece->piece_x = 0;
	piece->piece_y = 0;
	piece->piece = NULL;
}

void	ft_print(t_piece *piece)
{
	ft_putnbr_fd(piece->place[0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(piece->place[1], 1);
	ft_putchar_fd('\n', 1);
}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;
	char	*first_line;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	initiate(map, piece);
	ft_player(map, piece);
	ft_putstr_fd("\e[1;1H\e[5J", 2);
	while (1)
	{
		ft_map(map);
		ft_piece(piece);
		if (check_positions(map, piece))
			break ;
		algo(map, piece);
		ft_print(piece);
		visual(map);
		free_map(map);
		free_piece(piece);
	}
	free(map);
	free(piece);
	return (0);
}
