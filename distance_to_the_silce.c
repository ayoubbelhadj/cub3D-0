/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_the_silce.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:17:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/10 13:33:32 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	wx_horizontal()
{
	int	x;
	int	y;
	int	xa;
	int	ya;

	xa = 64 / tan(g_crd->alpha * radian);
	if (g_crd->dir == 13)
		ya = -64;
	else
		g_crd->dir = 64;
	x = ip_x_h();
	y = ip_y_h();
	while (g_data->map[y / 64][x / 64] != '1')
	{
		x += xa;
		y += ya;
	}
	g_crd->y_h = y - ya;
	g_crd->x_h = x - xa;
	return (x - xa);
}

int	wx_vertical()
{
	int	x;
	int	y;
	int	xa;
	int	ya;
	int	v;

	if (g_crd->dir == 2)
		v = -1;
	else
		v = 1;
	xa = 64 * v;
	ya = (64 * tan(g_crd->alpha * radian)) * v;
	x = ip_x_v();
	y = ip_y_v();
	while (g_data->map[y / 64][x / 64] != '1')
	{
		x += xa;
		y += ya;
	}
	g_crd->y_v = y - ya;
	g_crd->x_v = x - xa;
	return (x - xa);
}

int	distance_to_the_slice(void)
{
	int	PW_H;
	int	PW_V;
	int	D;

	PW_H = fabs(g_crd->px - wx_horizontal()) / cos(g_crd->alpha * radian);
	PW_V = fabs(g_crd->px - wx_vertical()) / cos(g_crd->alpha * radian);
	D = PW_H;
	if (PW_H < PW_V)
	{
		D = PW_H;
		// dda(g_crd->px * 64, g_crd->py * 64, g_crd->x_h, g_crd->y_h);
	}
	else if (PW_H >= PW_V)
	{
		D = PW_V;
		// dda(g_crd->px * 64, g_crd->py * 64, g_crd->x_v, g_crd->y_v, 51fb36);
	}
	return (D);
}

int	projected_height(void)
{
	int	ph;
	int	D;

	D = distance_to_the_slice();
	// if (g_crd->alpha == 58)
	// 	g_crd->alpha = 60;
	ph = (int)(((float)64 / (float)D) * 545);
	// g_crd->alpha -= 0.09;
	return(ph);
}
