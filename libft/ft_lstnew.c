/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:20:12 by mwestvig          #+#    #+#             */
/*   Updated: 2018/05/24 16:05:05 by mwestvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if (!(newlink = (t_list *)malloc(sizeof(*newlink))))
		return (NULL);
	if (!content)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	else
	{
		if (!(newlink->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	newlink->next = NULL;
	return (newlink);
}
