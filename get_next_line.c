/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:18:30 by fbarbera          #+#    #+#             */
/*   Updated: 2020/06/02 03:10:20 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int			ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

size_t		ft_strlen_gnl(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char		*ft_newstat_line(char *s, char **line)
{
	*line = ft_substr(s, 0, ft_strlen_gnl(s), 0);
	if (ft_strchr(s, '\n'))
		s = ft_substr(s, ft_strlen_gnl(s) + 1, ft_strlen(s), 1);
	else
	{
		free(s);
		return (NULL);
	}
	return (s);
}

int			get_next_line(int fd, char **line)
{
	static char	*s = NULL;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || (read(fd, buf, 0) < 0))
		return (-1);
	if (!(ft_strchr(s, '\n')))
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
		{
			buf[ret] = '\0';
			s = ft_strjoinn(s, buf);
			if (ft_strchr(s, '\n'))
				break ;
		}
	}
	s = ft_newstat_line(s, line);
	if (s)
		return (1);
	else
		return (0);
}
