/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:29:50 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/03 16:32:37 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	str = malloc(sizeof(*str) * ft_strlen(s1) + 1);
	if (str)
	{
		ft_strcpy(str, s1);
		return (str);
	}
	return (NULL);
}
