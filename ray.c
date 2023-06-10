/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:58:23 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/10 14:34:41 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	send_rays(void)
{
	int		x;
	int		y;
	int		i;
	int		j;
	double	temp_angle;
	int	d;
	int	b;

	mlx_clear_window(g_data->mlx,g_data->win);
	mlx_destroy_image(g_data->mlx,g_data->img);
	g_data->img = mlx_new_image(g_data->mlx, 1200, 1200);
		g_data->addr = mlx_get_data_addr(g_data->img, &g_data->bits_per_pixel, &g_data->line_length,
									&g_data->endian);
	float c = 64 / 554;
	if (g_crd->alpha < 30)
		temp_angle = (330 + g_crd->alpha);
	else
		temp_angle = (g_crd->alpha - 30);
	double t = temp_angle + 60;
	x = y = 0;
	j = 1;
	while (temp_angle <= t)
	{
		x = g_crd->px * 64, y = g_crd->py * 64;
		i = 1;
		while (g_data->map[y / 64][x / 64] != '1')
		{
			x = cos(temp_angle * radian) * i + g_crd->px * 64 ;
			y = sin(temp_angle * radian) * i + g_crd->py * 64 ;
			i++;
		}
		d = sqrt((x - g_crd->px * 64) * (x - g_crd->px * 64)
			+ ((y - g_crd->py * 64) * (y - g_crd->py * 64)));
		d = (64 * 200) / d;
		draw_line(j, d, 0x00808080);
		j++;
		// dda(g_crd->px * 64, g_crd->py * 64, x, y,  0x0055c63f);
		temp_angle+=0.09;
	}
	printf("j:%d x:%d y:%d\n", j, x, y);
	mlx_put_image_to_window(g_data->mlx,g_data->win, g_data->img, 0, 0);
	// √((x2 – x1)² + (y2 – y1)²)
	return (1);
}

void	send_ray(void)
{
	int	x;
	int	y;
	int	i;
	int xp;
	int yp;
	int	j;

	j = 0; 
	x = g_crd->px * 64, y = g_crd->py * 64;
	i = 1;
	// xp = cos(g_crd- >alpha * radian) * 40 + g_crd->px * 64 ;
	// yp = sin(g_crd->alpha * radian) * 40 + g_crd->py * 64 ;
	while (g_data->map[y / 64][x / 64] != '1')
	{
		if (!j && g_data->map[y / 64][x / 64] != 'E')
		{
			xp = x;
			yp = y;
			j = 1;
		}
		x = cos(g_crd->alpha * radian) * i + g_crd->px * 64 ;
		y = sin(g_crd->alpha * radian) * i + g_crd->py * 64 ;
		i++;
	}
	// printf("char:%c\n %d %d\n", g_data->map[yp / 64][xp / 64],
	// 	xp, yp);
	dda(g_crd->px * 64, g_crd->py * 64, x, y, 0x009f00ff);
}
