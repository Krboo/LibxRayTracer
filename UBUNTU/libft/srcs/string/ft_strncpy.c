/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:52:12 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 17:05:39 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	ft_memset(dest, '\0', n);
	while (src[i] && n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (dest);
}
