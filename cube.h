/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:09 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/07 09:10:16 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"

# define radian 0.01745329251994329576


typedef struct	s_g_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
}				t_data;
t_data	*g_data;

typedef struct s_crd
{
	double	px;
	double	py;
	double	alpha;
	int		dir;
	int		x_h;
	int		y_h;
	int		x_v;
	int		y_v;
}				t_crd;
t_crd	*g_crd;

char	*get_next_line(int fd);
void	player_x_y(void);
int		ip_y_h();
int		ip_x_h();
int		ip_x_v();
int		ip_y_v();
int		distance_to_the_slice(void);
int		projected_height(void);
void	draw_line(int x, int y, int color);
void	my_mlx_pixel_put(int x, int y, int color);
void	dda(int X0, int Y0, int X1, int Y1);
int		player_up();
int		player_down();
int		player_left();
int		player_right();

#endif