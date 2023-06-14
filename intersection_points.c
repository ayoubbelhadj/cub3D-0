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

	if (g_crd->alpha <= 360 && g_crd->alpha >= 270)
		v = -64;
	else
		v = 64;
	y = (int)(g_crd->py) * 64 + v;
	return (y);
}

int	ip_x_h()
{
	int	x;

	x = (int)(g_crd->px * 64
		+ (g_crd->py * 64 - ip_y_h()) / tan(g_crd->alpha * radian));
	return (x);
}

int	ip_x_v()
{
	int	x;
	int	v;

	if (g_crd->alpha <= 360 && g_crd->alpha >= 180)
		v = -64;
	else
		v = 64;
	x = (int)(g_crd->px) * 64 + v;
	return (x);
}

int	ip_y_v()
{
	int	y;

	y = (int)((int)g_crd->py * 64
		+ (g_crd->px * 64 - ip_x_v()) / tan(g_crd->alpha / 2 * radian));
	return (y);
}
