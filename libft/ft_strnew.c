/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:22:14 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/28 10:04:37 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	n = (int)size;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (n-- > -1)
		*(str + i++) = '\0';
	*(str + i) = '\0';
	return (str);
}
