/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:09 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/05 13:07:53 by aoudija          ###   ########.fr       */
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


typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	double	px;
	double	py;
	char	**inter_point;
	double	alpha;
	int		xa;
	int		ya;
}				t_data;
t_data	*data;

char	*get_next_line(int fd);
void	player_x_y(void);
int		ip_y_h();
int		ip_x_h();
int		ip_x_v();
int		ip_y_v();
int		distance_to_the_slice(void);
int		projected_height(void);

#endif