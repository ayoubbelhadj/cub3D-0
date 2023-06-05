/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:23:24 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/05 11:57:34 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ip_y_h()
{
	int	y;

	y = (int)(data->py) * 128 - 1;
	return (y);
}

int	ip_x_h()
{
	int	x;

	x = (int)(data->px * 128 + (data->py * 128 - ip_y_h()) / tan(data->alpha * radian));
	return (x);
}

int	ip_x_v()
{
	int	x;

	x = (int)(data->px) * 128 + 128;
	return (x);
}

int	ip_y_v()
{
	int	y;
// (int)
	y = (int)((int)data->py * 128 + (data->px * 128 - ip_x_v()) / tan(data->alpha * radian));
	return (y);
}
