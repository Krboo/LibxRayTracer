/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:22:29 by qduperon          #+#    #+#             */
/*   Updated: 2015/11/27 16:48:29 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;

	i = 0;
	str_dest = ((unsigned char *)dest);
	str_src = ((unsigned char *)src);
	if (str_dest > str_src)
	{
		while (i < len)
		{
			str_dest[len - 1] = str_src[len - 1];
			len--;
		}
		return (dest);
	}
	else
		while (i < len)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	return (dest);
}
