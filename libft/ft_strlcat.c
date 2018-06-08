/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:13:23 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/25 14:05:31 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = ft_strlen(dst);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize < dlen + 1)
		return (slen + dstsize);
	while (*src && i < dstsize - 1)
	{
		*(dst + i++) = *src++;
	}
	*(dst + i) = '\0';
	return (slen + dlen);
}
