/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:35:18 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/11 15:25:16 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	size_t	i;
	char	*str_2;

	i = 0;
	str_2 = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		str_2[i] = ft_toupper(str[i]);
		i++;
	}
	return (str_2);
}
