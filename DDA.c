/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:05:08 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/07 14:18:35 by aoudija          ###   ########.fr       */
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
// int x0, int y0, int x1, int y1
void	dda(int X0, int Y0, int X1, int Y1)
{
	int dx = X1 - X0;
    int dy = Y1 - Y0;
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put(X, Y, 0x0055c63f);; // put pixel at (X,Y)
        X += Xinc;
        Y += Yinc;
    }
}
