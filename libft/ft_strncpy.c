/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:45:54 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/28 08:29:59 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s2;
	size_t	i;

	s2 = dst;
	i = -1;
	while (++i < len)
		if (*src)
			*s2++ = *src++;
		else
			while (i++ < len)
				*s2++ = '\0';
	return (dst);
}
