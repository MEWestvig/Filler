/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:57:01 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/23 18:05:05 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	src1 = (char *)src;
	dst1 = (char *)dst;
	i = -1;
	if (src1 < dst1)
		while ((int)(--len) >= 0)
			*(dst1 + len) = *(src1 + len);
	else
		while (++i < len)
			*(dst1 + i) = *(src1 + i);
	return (dst);
}
