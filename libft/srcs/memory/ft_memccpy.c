/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:52:57 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/08 16:38:43 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if ((unsigned char)c == str_dest[i])
			return ((void *)&str_dest[i + 1]);
		i++;
	}
	return (NULL);
}
