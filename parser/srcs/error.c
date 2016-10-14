/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:41:09 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/14 15:24:57 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

void		ft_error(void)
{
	ft_putendl("Wrong usage !");
	ft_putendl("Usage: ");
	ft_putendl("./RTv1 <scene>");
	exit(0);
}

void		ft_exit(char *s)
{
	ft_putendl(s);
	exit(0);
}
