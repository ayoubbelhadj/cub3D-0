/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_no.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:35:22 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/14 17:04:05 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

char	*line_dir(char **tab, char *dir)
{
    int		i;
    int		j;
    int		b;
    char	*str;

	b = -1;
	i = -1;
	str = NULL;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == dir[0] && b == -1)
			{
				b = 0;
				if (tab[i][j + 1] && tab[i][j + 1] == dir[1])
					str = ft_strdup(tab[i]), b = 1;
			}
		}
	}
	return (str);
}
char	*dir(char *str)
{
	char	*dir;
	int		i;
	int		j;

	dir = NULL;
	i = 0;
	if (str[0] == ' ' || str[0] == '\t')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	j = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
		i++;
	dir = ft_substr(str, j, i);
	return (dir);
}

char	*path(char *str)
{
	char	*path;
	int		i;
	int		j;

	path = NULL;
	i = 0;
	if (str[0] == ' ' || str[0] == '\t')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	while (str[i] != ' ' && str[i] != '\t' && str[i])
		i++;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	j = i;
	while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i])
		i++;
	if (j == i)
		return (NULL);
	path = ft_substr(str, j, i - j);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (NULL);
		i++;
	}
	return (path);
}

int	check_no(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	line = ft_strdup(str + i);
	free(str);
	// printf("$%s$", line);
	// printf("direction:|%s|\n", dir(line));
	printf("path:|%s|", path(line));
	return (1);
}
