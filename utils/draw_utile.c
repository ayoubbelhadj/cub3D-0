/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:23:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 14:12:53 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	my_mlx_pixel_put2(int x, int y, int color)
{
	char	*dst;
	int		ofsset;

	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		ofsset = y * g_data.line_length2 + x * (g_data.bits_per_pixel2 / 8);
		dst = g_data.addr2 + ofsset;
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < g_data.x_width) && (y >= 0 && y < g_data.y_height))
	{
		dst = g_data.addr + ((y * g_data.line_length) + \
		(x * (g_data.bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

// void	my_mlx_pixel_put2(int x, int y, int color)
// {
// 	char	*dst2;

// 	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
// 	{
// 		dst2 = g_data.addr2 + ((y * g_data.line_length2) + \
// 		(x * (g_data.bits_per_pixel2 / 8)));
// 		*(unsigned int *)dst2 = color;
// 	}
// }

int	rgb(int r, int g, int b)
{
	int	rgb;

	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}

void	drawcircle(int xc, int yc, int radius)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(xc + x, yc + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	line(double dis, double ang, int color)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < dis)
	{
		x = g_data.player.x + i * cos(ang);
		y = g_data.player.y + i * sin(ang);
		my_mlx_pixel_put(x, y, color);
		i++;
	}
}
