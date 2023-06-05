/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/04 17:44:33 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_read(int fd, char *buffer, char *t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			if (t)
			{
				free(t);
				t = NULL;
			}
			return (NULL);
		}
		buffer[i] = 0;
		t = ft_strjoin_frees1(t, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[0] == 0)
	{
		free(t);
		t = NULL;
		return (NULL);
	}
	return (t);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = 0;
	return (line);
}

char	*remove_line(char *str)
{
	int		i;
	char	*store;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	store = ft_substr(str, i + i, ft_strlen(str) - i);
	// free(str);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*t;
	char		*line;

	buffer = malloc(1 + 1);
	t = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t);
	t = remove_line(t);
	return (line);
}
