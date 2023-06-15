/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:15 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 15:59:12 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	lines_number(char *str)
{
	char	*s;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDWR);
	s = get_next_line(fd);
	while (s)
	{
		++i;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**file_in_tab(char *str)
{
	int		i;
	int		fd;
	char	*line;
	char	**file;

	file = malloc(sizeof(char *) * lines_number(str) + 1);
	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	file[i] = 0;
	return (file);
}

char	**fst_part(char **tab)
{
	char	**fst_part;
	int		i;
	int		j;
	int		c;

	fst_part = malloc (sizeof(char *) * 6 + 1);
	i = -1;
	j = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			(fst_part[++j] = ft_strdup(tab[i]), c++);
		else if ((tab[i][0] == ' ' || tab[i][0] == '\t') && all_white(tab[i]))
		{
		}
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			(fst_part[++j] = ft_strdup(tab[i]), c++);
	}
	fst_part[++j] = 0;
	return (fst_part);
}

int	paths(char **lines)
{
	if (!rest_of_line(get_line(lines, "NO"), "NO"))
		return (0);
	g_parser->path_no = get_str(rest_of_line(get_line(lines, "NO"), "NO"));
	if (!rest_of_line(get_line(lines, "SO"), "SO"))
		return (0);
	g_parser->path_so = get_str(rest_of_line(get_line(lines, "SO"), "SO"));
	if (!rest_of_line(get_line(lines, "WE"), "WE"))
		return (0);
	g_parser->path_we = get_str(rest_of_line(get_line(lines, "WE"), "WE"));
	if (!rest_of_line(get_line(lines, "EA"), "EA"))
		return (0);
	g_parser->path_ea = get_str(rest_of_line(get_line(lines, "EA"), "EA"));
	return (1);
}

int	colors(char **lines)
{
	if (!rest_of_line(get_line(lines, "F"), "F"))
		return (0);
	g_parser->colorf = get_str(rest_of_line(get_line(lines, "F"), "F"));
	if (!rest_of_line(get_line(lines, "C"), "C"))
		return (0);
	g_parser->colorc = get_str(rest_of_line(get_line(lines, "C"), "C"));
	return (1);
}

int	check_lines(char *str)
{
	char	**file;
	char	**lines;
	int		i;

	file = file_in_tab(str);
	lines = fst_part(file);
	ft_free(file);
	if (!paths(lines))
		return (0);
	if (!colors(lines))
		return (0);
	ft_free(lines);
	return (1);
}
