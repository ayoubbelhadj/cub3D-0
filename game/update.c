/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:03:20 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 14:54:58 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	walkupdown(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalk * g_data.player.speedmove;
	x = g_data.player.x + cos(g_data.player.alpha) * movespeed;
	y = g_data.player.y + sin(g_data.player.alpha) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkleftright(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalkx * g_data.player.speedmove;
	y = g_data.player.y + sin(g_data.player.alpha - M_PI_2) * movespeed;
	x = g_data.player.x + cos(g_data.player.alpha - M_PI_2) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkx(void)
{
	double	movespeed;
	double	angle;
	double	x;
	double	y;

	movespeed = g_data.player.speedmove;
	if (g_data.player.dirwalk == -1)
		angle = g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 2);
	else
		angle = g_data.player.dirwalk
			* (g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 4));
	y = g_data.player.y + sin(angle) * movespeed;
	x = g_data.player.x + cos(angle) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	move(void)
{
	g_data.player.alpha += g_data.player.dirturn
		* g_data.player.speedretate;
	if (g_data.player.dirwalk != 0 && g_data.player.dirwalkx != 0)
		walkx();
	else if (g_data.player.dirwalk != 0)
		walkupdown();
	else if (g_data.player.dirwalkx != 0)
		walkleftright();
}

void	rend_img(void)
{
	resetimg();
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	rend3d();
	img3d();
	fillmap();
	drawrays();
	line(10, g_data.player.alpha, 0x000000);
	drawcircle(g_data.player.x, g_data.player.y, 3);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img2, 0, 0);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img, 0, WIN_H - (ft_tablen(g_data.cart) * CUBE));
}

int	update(void)
{
	move();
	sendrays();
	g3d();
	rend_img();
	return (0);
}
