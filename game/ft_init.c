/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:18:06 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/15 23:40:57 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	imgs_init(void)
{
	g_data.img = mlx_new_image(g_data.mlx, g_data.x_width, g_data.y_height);
	g_data.addr = mlx_get_data_addr(g_data.img, &g_data.bits_per_pixel,
			&g_data.line_length, &g_data.endian);
	g_data.img2 = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.addr2 = mlx_get_data_addr(g_data.img2, &g_data.bits_per_pixel2,
			&g_data.line_length2, &g_data.endian2);
}

void	win_init(void)
{
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, WIN_W, WIN_H, "CUB3D");
}

void	wall_init(void)
{
	g_data.no.img = mlx_xpm_file_to_image(g_data.mlx, "xpmfile/NO1.xpm", \
	&g_data.no.img_w, &g_data.no.img_h);
	g_data.no.addr = (unsigned int *)mlx_get_data_addr(g_data.no.img,
			&g_data.no.bits_per_pixel, &g_data.no.line_length,
			&g_data.no.endian);
	g_data.so.img = mlx_xpm_file_to_image(g_data.mlx, "xpmfile/SO1.xpm", \
	&g_data.so.img_w, &g_data.so.img_h);
	g_data.so.addr = (unsigned int *)mlx_get_data_addr(g_data.so.img,
			&g_data.so.bits_per_pixel, &g_data.so.line_length,
			&g_data.so.endian);
	g_data.ea.img = mlx_xpm_file_to_image(g_data.mlx, "xpmfile/EA1.xpm", \
	&g_data.ea.img_w, &g_data.ea.img_h);
	g_data.ea.addr = (unsigned int *)mlx_get_data_addr(g_data.ea.img,
			&g_data.ea.bits_per_pixel, &g_data.ea.line_length,
			&g_data.ea.endian);
	g_data.we.img = mlx_xpm_file_to_image(g_data.mlx, "xpmfile/WE1.xpm", \
	&g_data.we.img_w, &g_data.we.img_h);
	g_data.we.addr = (unsigned int *)mlx_get_data_addr(g_data.we.img,
			&g_data.we.bits_per_pixel, &g_data.we.line_length,
			&g_data.we.endian);
}

void	init(void)
{
	g_data.cart = split_map(g_data.map);
	if (!g_data.cart)
	{
		free_cart(g_data.cart);
		ft_error("ERROR!!\nMap invalid.\n");
	}
	g_data.viewangle = 60 * (M_PI / 180);
	g_data.player.alpha = M_PI / 2;
	g_data.player.speedretate = SPEED_R * (M_PI / 180);
	g_data.player.speedretate_m = M_SPEED_R * (M_PI / 180);
	g_data.player.speedmove = (CUBE * SPEED_M) / 20 ;
	g_data.player.dirturn = 0;
	g_data.player.dirwalk = 0;
	g_data.rad = M_PI / 180;
	position();
	g_data.x_width = ft_strlen(g_data.cart[0]) * CUBE;
	g_data.y_height = ft_tablen(g_data.cart) * CUBE;
	g_data.nbr_rays = WIN_W;
	g_data.ray = ft_calloc(sizeof(t_ray), g_data.nbr_rays + 1);
	g_data.g3d = ft_calloc(sizeof(t_ray), g_data.nbr_rays + 1);
	win_init();
	imgs_init();
	wall_init();
}

void	resetimg(void)
{
	mlx_destroy_image(g_data.mlx, g_data.img);
	mlx_destroy_image(g_data.mlx, g_data.img2);
	g_data.img2 = NULL;
	g_data.img = mlx_new_image(g_data.mlx, g_data.x_width, g_data.y_height);
	g_data.addr = mlx_get_data_addr(g_data.img, &g_data.bits_per_pixel,
			&g_data.line_length, &g_data.endian);
	g_data.img2 = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.addr2 = mlx_get_data_addr(g_data.img2, &g_data.bits_per_pixel2,
			&g_data.line_length2, &g_data.endian2);
}
