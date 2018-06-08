/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:54:04 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/24 09:35:44 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	while (*s && IS_SPACE(*s))
		s++;
	len = ft_strlen(s) == 0 ? 0 : ft_strlen(s) - 1;
	if (len > 0)
	{
		while (IS_SPACE(s[len]))
			len--;
		len++;
	}
	if (!(ret = (char *)malloc(sizeof(*ret) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (len--)
		ret[i++] = *s++;
	return (ret);
}
