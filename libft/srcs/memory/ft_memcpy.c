/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:20:28 by qduperon          #+#    #+#             */
/*   Updated: 2015/11/27 16:04:07 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	c;
	char	*str_dest;
	char	*str_src;

	c = 0;
	str_dest = (char *)dest;
	str_src = (char *)src;
	while (c < n)
	{
		str_dest[c] = str_src[c];
		c++;
	}
	return (dest);
}
