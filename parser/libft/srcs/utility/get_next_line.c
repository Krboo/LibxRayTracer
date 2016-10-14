/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:13:05 by qduperon          #+#    #+#             */
/*   Updated: 2016/02/08 15:12:13 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_of_line(char *tmp)
{
	int c;

	c = 0;
	while (tmp[c])
	{
		if (tmp[c] == '\n')
			return (c);
		c++;
	}
	return (c);
}

static int	fill_the_line(const int fd, char *tmp[fd], char **line)
{
	int		end;
	char	*temp;

	end = end_of_line(tmp[fd]);
	*line = ft_strsub(tmp[fd], 0, end);
	if (!(temp = (char *)malloc(sizeof(temp) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(temp, &tmp[fd][end + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], temp);
	free(temp);
	return (1);
}

static char	*strjoin_free(char *tmp, char *buff)
{
	char	*temp;

	if (!(temp = ft_strjoin(tmp, buff)))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (temp);
}

static int	fill_the_array(const int fd, char *tmp[fd])
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while (!(ft_strchr(tmp[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp[fd] = strjoin_free(tmp[fd], buff);
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tmp[MAX_FD];

	if (fd < 0 || fd == 1 || fd == 2 || fd > MAX_FD || !line || BUFF_SIZE < 0)
		return (-1);
	if (!tmp[fd] && (!(tmp[fd] = ft_strnew(2))))
		return (-1);
	if (fill_the_array(fd, &(*tmp)) < 0)
		return (-1);
	if (tmp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (fill_the_line(fd, tmp, line) < 0)
		return (-1);
	return (1);
}
