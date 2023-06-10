/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/10 14:40:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_close(int keycode)
{
	if (keycode == 17)
	{
	}
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = g_data->addr + (y * g_data->line_length + x * (g_data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	fill_map(void)
{
	char	*s;
	int		fd;
	int		i;

	fd = open("maps/map.cub", O_RDONLY);
	i = 0;
	s = get_next_line(fd);
	while (s)
		(s = get_next_line(fd), free(s), i++);
	g_data->map = malloc(sizeof(char *) * i + 1);
	close(fd);
	fd = open("maps/map.cub", O_RDONLY);
	s = get_next_line(fd);
	i = -1;
	while (s)
	{
		(g_data->map[++i] = ft_strdup(s), free(s));
		s = get_next_line(fd);
	}
	g_data->map[++i] = 0;
}

void	draw_line(int x, int y, int color)
{
	int y1;

	// y1 = y - 64;
	y1 = 448 - y / 2;
	y += y1;
	while (y1 < y)
	{
		my_mlx_pixel_put(x, y1, color);
		y1++;
	}
}

void	draw_loop(int *x, int x_max, int y, int color)
{
	while (*x < x_max)
	{
		draw_line(*x, y, color);
		(*x)++;
	}
}

void	draw_map_two_d()
{
	int	i;
	int	j;
	int	x;
	int	y;

	mlx_clear_window(g_data->mlx, g_data->win);
	i = -1, y = 0;
	while (g_data->map[++i])
	{
		j = -1, x = 0, y += 64;
		while (g_data->map[i][++j])
		{
			if (g_data->map[i][j] == '1')
				draw_loop(&x, x + 64, y, 0x00A52A2A);
			else if (g_data->map[i][j] == '0')
				draw_loop(&x, x + 64, y, 0x00FFFFFF);
			else if (g_data->map[i][j] == 'N' || g_data->map[i][j] == 'E'
				|| g_data->map[i][j] == 'S' || g_data->map[i][j] == 'W')
				draw_loop(&x, x + 64, y, 0x00808080);
		}
	}
	player_x_y();
	send_rays();
	// send_ray();
	mlx_put_image_to_window(g_data->mlx,g_data->win, g_data->img, 0, 0);
}

int	hook(void *ptr)
{
	(void)ptr;
	draw_map_two_d();
	projected_height();
	return (0);
}

int	key_press(int keycode,void *ptr)
{
	(void)ptr;
	if (keycode == 53)
		exit (0);
	if (keycode == 126)
		player_up();
	else if (keycode == 125)
		player_down();
	else if (keycode == 123)
		player_left();
	else if (keycode == 124)
		player_right();
	if (keycode == 0)
	{
		g_crd->alpha--;
		if (g_crd->alpha  == 0)
			g_crd->alpha = 360;
	}
	else if (keycode == 2)
	{
		g_crd->alpha += 3;
		if (g_crd->alpha == 360)
			g_crd->alpha = 0;
	}
	player_x_y();
	send_rays();
	mlx_put_image_to_window(g_data->mlx,g_data->win, g_data->img, 0, 0);
	printf("alpha %f\n", g_crd->alpha);
	draw_map_two_d();
	return (0);
}

int	main(void)
{
	int d , x , b, j , y, c;
	g_data = malloc(sizeof(t_data));
	g_crd = malloc(sizeof(t_crd));
	g_dir = malloc(sizeof(t_dir));
	g_data->mlx = mlx_init();
	g_data->win = mlx_new_window(g_data->mlx, 1200, 1200, "Hello world!");
	g_data->img = mlx_new_image(g_data->mlx, 1200, 1200);
	g_data->addr = mlx_get_data_addr(g_data->img, &g_data->bits_per_pixel, &g_data->line_length,
								&g_data->endian);
	g_crd->alpha = 360;
	printf("-----------\n");
	fill_map();
	player_x_y();
	send_rays();
	// draw_map_two_d();
	mlx_hook(g_data->win, 2, 0, key_press, NULL);
	mlx_hook(g_data->win, 17, 0, on_close, NULL);
	mlx_put_image_to_window(g_data->mlx,g_data->win, g_data->img, 0, 0);
	mlx_loop(g_data->mlx);
}
