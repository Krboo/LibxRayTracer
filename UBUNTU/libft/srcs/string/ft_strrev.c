/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:49:53 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/11 15:25:40 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = ft_strlen(str);
	while (i < lenght / 2)
	{
		tmp = str[i];
		str[i] = str[lenght - i - 1];
		str[lenght - i - 1] = tmp;
		i++;
	}
	return (str);
}
