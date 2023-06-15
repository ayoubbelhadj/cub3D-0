/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:26:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 16:08:44 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int check_digitcomma(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int check_commas(char *str)
{
	int i;
	int c;

	c = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			c++;
	}
	if (c != 2)
		return (0);
	return (1);
}

int	check_length(char **str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_strlen(str[i]) < 1)
			return (0);
	}
	return (1);
}

int check_colors()
{
	int i;

	i = -1;
	if (!g_parser->colorc || !g_parser->colorf)
		return (0);
	if (!check_digitcomma(g_parser->colorc)
		|| !check_digitcomma(g_parser->colorf))
		return (0);
	if (!check_commas(g_parser->colorc)
		|| !check_commas(g_parser->colorf))
		return (0);
	g_parser->c = ft_split(g_parser->colorc, ',');
	g_parser->f = ft_split(g_parser->colorf, ',');
	if (!check_length(g_parser->f) || !check_length(g_parser->c))
		return (0);
	return (1);
}
