/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:18:51 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/07 08:53:35 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	player_up()
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (g_data->map[++i])
	{
		j = -1;
		while (g_data->map[i][++j])
		{
			if ((g_data->map[i][j] == 'E' || g_data->map[i][j] == 'W'
				|| g_data->map[i][j] == 'N' || g_data->map[i][j] == 'S')
				&& g_data->map[i - 1][j] && g_data->map[i - 1][j] != '1')
            {
				c = g_data->map[i][j];
				g_data->map[i][j] = '0';
				g_data->map[i - 1][j] = c;
				return (1);
			}
		}
	}
	return (1);
}

int	player_down()
{
	int		i;
	int		j;
	char	c;
	i = -1;
	while (g_data->map[++i])
	{
		j = -1;
		while (g_data->map[i][++j])
		{
			if ((g_data->map[i][j] == 'E' || g_data->map[i][j] == 'W'
				|| g_data->map[i][j] == 'N' || g_data->map[i][j] == 'S')
				&& g_data->map[i + 1][j] && g_data->map[i + 1][j] != '1')
            {
				c = g_data->map[i][j];
				g_data->map[i][j] = '0';
				g_data->map[i + 1][j] = c;
				return (1);
			}
		}
	}
	return (0);
}

int	player_left()
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (g_data->map[++i])
	{
		j = -1;
		while (g_data->map[i][++j])
		{
			if ((g_data->map[i][j] == 'E' || g_data->map[i][j] == 'W'
				|| g_data->map[i][j] == 'N' || g_data->map[i][j] == 'S')
				&& g_data->map[i][j - 1] && g_data->map[i][j - 1] != '1')
            {
				c = g_data->map[i][j];
				g_data->map[i][j] = '0';
				g_data->map[i][j - 1] = c;
				return (1);
			}
		}
	}
	return (0);
}

int	player_right()
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (g_data->map[++i])
	{
		j = -1;
		while (g_data->map[i][++j])
		{
			if ((g_data->map[i][j] == 'E' || g_data->map[i][j] == 'W'
				|| g_data->map[i][j] == 'N' || g_data->map[i][j] == 'S')
				&& g_data->map[i][j + 1] && g_data->map[i][j + 1] != '1')
            {
				c = g_data->map[i][j];
				g_data->map[i][j] = '0';
				g_data->map[i][j + 1] = c;
				return (1);
			}
		}
	}
	return (0);
}
