/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:34:39 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/11 16:57:48 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initiate(t_map *map, t_piece *piece)
{	
	map->map_x = 0;
	map->map_y = 0;
	map->map = NULL;
	map->player = 0;
	piece->piece_x = 0;
	piece->piece_y = 0;
	piece->piece = NULL;

}

void	ft_print(t_piece *piece)
{
	ft_putnbr_fd(piece->pos[0][0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(piece->pos[0][1], 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;
	char *first_line;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	initiate(map, piece);
	ft_player(map, piece);
	while (1)
	{
		set_info(map, piece);
		if (check_positions(map, piece))
			break;
		ft_print(piece);
	}
	free(map);
	free(piece);
	return (0);
}
