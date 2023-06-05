/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/05 16:36:26 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_close(int keycode)
{
	if (keycode == 17 || keycode == 53)
		exit(0);
	return (0);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	fill_map(void)
{
	char	*s;
	int		fd;
	int		i;

	fd = open("map.cub", O_RDONLY);
	i = 0;
	s = get_next_line(fd);
	while (s)
		(s = get_next_line(fd), free(s), i++);
	data->map = malloc(sizeof(char *) * i + 1);
	close(fd);
	fd = open("map.cub", O_RDONLY);
	s = get_next_line(fd);
	i = -1;
	while (s)
	{
		(data->map[++i] = ft_strdup(s), free(s));
		s = get_next_line(fd);
	}
	data->map[++i] = 0;
}

void	draw_line(int x, int y, int color)
{
	int y1;

	y1 = 320 - y/2;
	y += y1;
	printf("y0: %d ph: %d x : %d\n", y1, y, x);
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

	i = -1, y = 0;
	while (data->map[++i])
	{
		j = -1, x = 0, y += 128;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				draw_loop(&x, x + 128, y, 0x00A52A2A);
			else if (data->map[i][j] == '0')
				draw_loop(&x, x + 128, y, 0x00FFFFFF);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
				draw_loop(&x, x + 128, y, 0x00808080);
		}
	}
}

int	main(void)
{
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 640, "Hello world!");
	data->img = mlx_new_image(data->mlx, 640, 640);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	data->alpha = 60;
	fill_map();
	player_x_y();
	int x,y;
	x = y = 0;
	printf("\n------------------------\n");
	while (data->alpha >= 8.3)
	{
		printf("%f\n", data->alpha);
		y = projected_height();
		y *= cos(data->alpha * radian);
		draw_line(x++, y, 0x00A52A2A);
	}
	// projected_height();
	// draw_map_two_d();
	mlx_put_image_to_window(data->mlx,data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 0, on_close, NULL);
	mlx_loop(data->mlx);
}
