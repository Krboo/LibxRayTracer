/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:18:11 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 15:57:49 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	str_s1 = (unsigned char *)s1;
	str_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str_s1 != *str_s2)
			return ((unsigned char)*str_s1 - (unsigned char)*str_s2);
		str_s1++;
		str_s2++;
	}
	return (0);
}
