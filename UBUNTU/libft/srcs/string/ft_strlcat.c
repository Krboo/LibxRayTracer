/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:08:26 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 17:18:24 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t c;
	size_t result;

	i = 0;
	c = 0;
	result = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != 0 && i < size)
		i++;
	if ((size - i) == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[c] != 0)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = 0;
	return (result);
}
