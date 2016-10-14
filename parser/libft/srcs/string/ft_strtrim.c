/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:38:46 by qduperon          #+#    #+#             */
/*   Updated: 2015/12/08 12:00:25 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	item;
	size_t	i;
	size_t	keep;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	item = 0;
	keep = 0;
	while (s[item])
	{
		if (s[item] != ' ' && s[item] != '\t' && s[item] != '\n')
		{
			item++;
			keep = item;
		}
		else
			item++;
	}
	if (s && keep == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, (keep - i)));
}
