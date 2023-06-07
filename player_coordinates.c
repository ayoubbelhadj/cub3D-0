/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:44:29 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/07 10:12:49 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_x_y(void)
{
	int	i;
	int	j;

	i = -1;
	while (g_data->map[++i])
	{
		j = -1;
		while (g_data->map[i][++j])
		{
			if (g_data->map[i][j] == 'N' || g_data->map[i][j] == 'E'
				|| g_data->map[i][j] == 'S' || g_data->map[i][j] == 'W')
			{
				g_crd->px = (double)j + 0.5;
				g_crd->py = (double)i + 0.5;
			}
		}
	}
}

