/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:59:20 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 17:29:26 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i > 0 && (char)c != s[i])
		i--;
	if (s[i] == (char)c)
		return ((char *)s + i);
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
