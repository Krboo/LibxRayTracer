/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:12:44 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/10 17:33:10 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	void	*i;
	t_list	*new;

	i = ft_memalloc(content_size);
	if (!i)
		return (NULL);
	if (content == NULL)
	{
		i = NULL;
		content_size = 0;
	}
	else
		i = ft_memcpy(i, content, content_size);
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = i;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
