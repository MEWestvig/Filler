/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:06:07 by mwestvig          #+#    #+#             */
/*   Updated: 2018/06/23 18:15:26 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_map
{
	int map_x;
	int map_y;
	char **map;
	int player;
}				t_map;

typedef struct	s_piece
{
	int piece_x;
	int piece_y;
	char **piece;
}				t_piece;

void	set_info(char **line, t_map map, t_piece piece, int fd);

#endif
