/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:09:23 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:15 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 || s2 || n)
	{
		while (n > 0)
		{
			if (*s1 != *s2)
			{
				if ((unsigned char)*s1 > (unsigned char)*s2)
					return (1);
				else
					return (-1);
			}
			if (*s1 == '\0')
				return (0);
			n--;
			s1++;
			s2++;
		}
	}
	return (0);
}
