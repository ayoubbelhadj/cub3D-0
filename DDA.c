/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:05:08 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/09 20:48:55 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	slope(int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	float	m;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	m = dx / dy;
	return (m);
}

// void	dda(int x0, int y0, int x1, int y1)
// {
//     float	xinc;
//     float	yinc;
//     int		steps;
// 	int		i;
// 	float	x,y;

// 	if (abs(x1 - x0) > abs(y1 - y0))
// 		steps = abs(x1 - x0);
// 	else
// 		steps = abs(y1 - y0);
//     xinc = (float)abs(x1 - x0) / (float)steps;
//     yinc = (float)abs(y1 - y0) / (float)steps;
// 	i = 0;
// 	x = (float)x0;
// 	y = (float)y0;
// 	while (i <= steps)
//     {
// 		my_mlx_pixel_put(x, y, 0x0055c63f);
// 		i++;
//         x += xinc;
//         y += yinc;
//     }
// }

void dda(int x0, int y0, int x1, int y1, int color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = (float)dx / (float)steps;
    float yinc = (float)dy / (float)steps;

    float x = (float)x0;
    float y = (float)y0;

    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put((int)x, (int)y, color);
        x += xinc;
        y += yinc;
    }
}
