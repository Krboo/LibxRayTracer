/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:25 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/02 15:35:05 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble(double nb, int precision)
{
	int		expo;
	int		cpt;

	expo = 1;
	cpt = 0;
	while (cpt++ < precision)
		expo *= 10;
	ft_putnbr((int)nb);
	ft_putchar('.');
	if (precision)
		ft_putnbr((int)(nb * expo) % expo);
}
