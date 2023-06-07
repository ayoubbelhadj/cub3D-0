/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:23:24 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/05 19:25:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ip_y_h()
{
	int	y;
	int	v;

	// printf("y_h:direction: %d\n", g_crd->dir);
	if (g_crd->alpha >= 180 && g_crd->alpha <= 360)
		v = -1;
	else
		v = 128;
	y = (int)(g_crd->py) * 128 + v;
	// printf("y_h: %d\n", y);
	return (y);
}

int	ip_x_h()
{
	int	x;

	x = (int)(g_crd->px * 128
		+ (g_crd->py * 128 - ip_y_h()) / tan(g_crd->alpha * radian));
	// printf("x_h: %d\n", x);
	return (x);
}

int	ip_x_v()
{
	int	x;
	int	v;

	if (g_crd->alpha >= 90 && g_crd->alpha <= 270)
		v = -1;
	else
		v = 128;
	x = (int)(g_crd->px) * 128 + v;
	return (x);
}

int	ip_y_v()
{
	int	y;

	y = (int)((int)g_crd->py * 128
		+ (g_crd->px * 128 - ip_x_v()) / tan(g_crd->alpha / 2 * radian));
	return (y);
}
