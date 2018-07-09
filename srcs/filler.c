/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:34:39 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/09 12:05:39 by mwestvig         ###   ########.fr       */
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
int	main(void)
{
	int		f;
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	initiate(map, piece);
	set_info(map, piece);
	f = 0;
	while (f < map->map_y)
	{
		fprintf(stderr, "%s\n", map->map[f]);
		fflush(stderr);
		f++;
	}
	free(map);
	free(piece);
	return (0);
}
