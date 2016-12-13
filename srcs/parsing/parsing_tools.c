/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:26:13 by pmartine          #+#    #+#             */
/*   Updated: 2016/12/12 16:02:57 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

double	ft_data(char *line)
{
	return (ft_atodouble(&line));
}

void	ft_free_tab(char **tab, int c)
{
	int i;

	i = 0;
	while (i <= c)
	{
		free(tab[i]);
		i++;
	}
}

int		ft_countline(char *scene)
{
	char	*line;
	int		fd;
	int		i;
	int		ret;

	i = 0;
	fd = open(scene, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	free(line);
	if (ret == -1)
		exit(1);
	return (i);
}

char	**ft_files(char *scene, char **file)
{
	char	*line;
	int		i;
	int		ret;
	int		j;
	int		fd;

	i = ft_countline(scene);
	file = NULL;
	j = 0;
	fd = open(scene, O_RDONLY);
	if (!(file = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(file[j] = (char *)malloc(sizeof(char) * ft_strlen(line))))
			return (NULL);
		file[j] = ft_strcpy(file[j], line);
		j++;
		free(line);
	}
	close(fd);
	free(line);
	if (ret == -1)
		exit(1);
	return (file);
}
