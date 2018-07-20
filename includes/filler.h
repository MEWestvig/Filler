/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:06:07 by mwestvig          #+#    #+#             */
/*   Updated: 2018/07/19 19:38:05 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_map
{
	int		map_x;
	int		map_y;
	char	**map;
	int		player;
	char	m_p;
	char	e_p;
}				t_map;

typedef struct	s_piece
{
	int		piece_x;
	int		piece_y;
	char	**piece;
	int		**pos;
	int		*place;
	int		num_pos;
}				t_piece;

int				check_positions(t_map *map, t_piece *piece);
void			ft_player(t_map *map, t_piece *piece);
void			ft_map(t_map *map);
void			ft_piece(t_piece *piece);
void			algo(t_map *m, t_piece *p);

#endif
