/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:34:39 by mwestvig          #+#    #+#             */
/*   Updated: 2018/06/23 18:33:24 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initiate(t_map map, t_piece piece)
{	
	map.map_x = 0;
	map.map_y = 0;
	map.map = NULL;
	map.player = 0;
	piece.piece_x = 0;
	piece.piece_y = 0;
	piece.piece = NULL;
}
int	main(void)
{
	char	*line;
	int		f;
	int		h;
	t_map	map;
	t_piece	piece;

	initiate(map, piece);
	f = open("output.txt", 1);
	h = open("info.txt", 1);
	while (get_next_line(0, &line) == 1)
	{
		ft_putendl_fd(line, f);
		set_info(&line, map, piece, h);
		free(line);
	}
	ft_putendl_fd("8 2", 1);
	return (0);
}
