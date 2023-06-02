/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/13 12:21:17 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map;
	int		count;
	void	*wall;
	void	*exit;
	void	*pickle;
	void	*rick;
	void	*morty;
	void	*floor;
	void	*exit_t;
	void	*exit_f;
}	t_data;

void	fill(t_data data, char c, void *img_ptr);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcat(char *dst, char *src, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(char *str);
int		heightt(char *path);
void	*floor_img(void *mlx);
void	*pickle_img(void *mlx);
void	*hole_img(void *mlx);
void	*wall_img(void *mlx);
void	*rick_img(void *mlx);
char	*ft_strjoin(char *s1, char *s2);
int		player_up(char *map, int count);
int		player_down(char *map, int count);
int		player_left(char *map, int count);
int		player_right(char *map, int count);
int		playerb_up(t_data *data, int count);
int		playerb_down(t_data *data, int count);
int		playerb_left(t_data *data, int count);
int		playerb_right(t_data *data, int count);
void	mapping(t_data data);
int		key_press(int keycode, t_data *data);
int		pickle_exist(char *map);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		on_close(int keycode);
int		check_items(char *map);
int		check_bitems(char *map);
int		is_rectangular(char *path);
int		chekck_walls(char *path);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*morty_img(void *mlx);
void	*hole_img2(void *mlx);
void	*hole_img3(void *mlx);
void	mapping_bonus(t_data data);
int		key_press_bonus(int keycode, t_data *data);
int		morty_exist(char *map);
void	evil_morty(t_data *data);
int		frame(t_data *data);
char	*ft_itoa(int n);
int		is_playable(char *map);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
void	*ft_free(char **table);
int		player_j(char **s);
int		player_i(char **s);
void	filler(t_data *data);

#endif