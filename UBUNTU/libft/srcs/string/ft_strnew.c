/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:12:13 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/02 15:51:28 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
