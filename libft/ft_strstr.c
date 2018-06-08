/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:00:20 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/23 18:18:57 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		found;
	int		i;
	int		j;
	int		k;

	i = -1;
	found = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*(haystack + ++i) && !found)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			k = i;
			found = 1;
			while (*(needle + j))
				if (*(haystack + k++) != *(needle + j++))
					found = 0;
			if (found)
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}
