/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:35:22 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/14 18:36:48 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

char	*get_line(char **tab, char *str)
{
    int		i;
    int		j;
    int		b;
    char	*line;

	b = -1;
	i = -1;
	line = NULL;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == str[0])
			{
				if (!str[1] && b != 1)
					(line = ft_strdup(tab[i]), b = 1);
				else if (tab[i][j + 1]
					&& tab[i][j + 1] == str[1] && b != 1)
					(line = ft_strdup(tab[i]), b = 1);
			}
		}
	}
	return (line);
}

char	*fst_partof_line(char *line)
{
	char	*dir;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	dir = NULL;
	i = 0;
	if (line[0] == ' ' || line[0] == '\t')
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
	}
	j = i;
	while ((line[i] != ' ' && line[i] != '\t') && line[i])
		i++;
	dir = ft_substr(line, j, i - j);
	return (dir);
}

char	*get_str(char *str)
{
	char	*path;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	if (str[0] == ' ' || str[0] == '\t')
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	j = i;
	while ((str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\n') && str[i])
		i++;
	if (i == j)
		return (NULL);
	path = ft_substr(str, j, i - j);
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (NULL);
	return (path);
}

char	*rest_of_line(char *line, char *str)
{
	int		i;
	char	*rest;
	char	*d;

	if (!line)
		return (0);
	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	d = fst_partof_line(line + i);
	if (!d)
		return (NULL);
	if (ft_strcmp(d, str))
		return (NULL);
	rest = ft_substr(line, i + ft_strlen(d),
		ft_strlen(line) - i + ft_strlen(d));
	free(line);
	return (rest);
}
