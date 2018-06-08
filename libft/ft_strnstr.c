/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:00:47 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/24 11:59:51 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			found;
	int			i;
	int			j;
	int			k;
	const char	*h;

	i = -1;
	found = 1;
	h = big;
	if (!ft_strlen(little))
		return ((char *)h);
	while (*(h + ++i) && i < (int)len)
	{
		j = 0;
		if (*(h + i) == *little)
		{
			k = i;
			found = 1;
			while (*(little + j) && *(h + k) && j < (int)len && k < (int)len)
				found = (*(h + k++) == *(little + j++) ? 1 : 0);
			if (found && !*(little + j))
				return ((char *)(h + i));
		}
	}
	return (NULL);
}
