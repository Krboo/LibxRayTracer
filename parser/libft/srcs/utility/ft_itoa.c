/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:38:18 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/08 17:13:40 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absolu(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		nb_len;
	int		sign;
	char	*str;

	str = NULL;
	nb_len = ft_size_base(n, 10);
	sign = ft_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (nb_len + sign + 1));
	if (str)
	{
		str = str + sign + nb_len;
		*str = '\0';
		if (!n)
			*--str = '0';
		while (n != 0)
		{
			*--str = ft_absolu(n % 10) + '0';
			n /= 10;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
