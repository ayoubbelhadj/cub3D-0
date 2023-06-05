/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_the_silce.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:17:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/05 15:15:16 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	wx_horizontal()
{
	int	wall_x_y[2];

	// data->xa = (128 / tan(data->alpha * radian)) * (-1);
	data->xa = 73;
	data->ya = -128;
	wall_x_y[0] = ip_x_h();
	wall_x_y[1] = ip_y_h();
	while (data->map[wall_x_y[1] / 128][wall_x_y[0] / 128] != '1')
	{
		wall_x_y[0] += data->xa;
		wall_x_y[1] += data->ya;
	}
	return (wall_x_y[0]);
}

int	wx_vertical()
{
	int	x;
	int	y;

	data->xa = 128;
	data->ya = (128 * tan(data->alpha * radian)) * -1;
	x = ip_x_v();
	y = ip_y_v();
	while (data->map[y / 128][x / 128] != '1')
	{
		x += data->xa;
		y += data->ya;
	}
	return (x);
}

int	distance_to_the_slice(void)
{
	int	PW_H;
	int	PW_V;
	int	D;
	int	abs;

	abs = data->px - wx_horizontal();
	if (abs < 0)
		abs *= -1;
	PW_H = abs / cos(data->alpha * radian);
	abs = data->px - wx_vertical();
	if (abs < 0)
		abs *= -1;
	PW_V = abs / cos(data->alpha * radian);
	D = PW_H;
	if (PW_H < PW_V)
		D = PW_H;
	else if (PW_H >= PW_V)
		D = PW_V;
	return (D);
}

int	projected_height(void)
{
	int	ph;
	int	D;

	D = distance_to_the_slice();
	ph = (int)(((float)128 / (float)D) * 545);
	data->alpha -= 0.09;
	return(ph);
}

