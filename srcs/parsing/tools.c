/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:56:07 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/17 17:54:07 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		ft_countline(char *scene)
{
	char 	*line;
	int		fd;
	int 	i;
	int 	ret;

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

char 	**ft_files(char *scene, char **file)
{
	char	*line;
	int		i;
	int 	ret;
	int 	j;
	int 	fd;

	i = ft_countline(scene);
	file = NULL;
	j = 0;
	fd = open(scene, O_RDONLY);
	if (!(file = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(file[j] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1)))
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
