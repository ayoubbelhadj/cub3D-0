/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:46:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/15 18:39:43 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if (!name_check(av[1]))
		{
			g_data.no.img = 0;
			g_data.no.img_w = 0;
			g_data.no.img_h = 0;
			g_data.no.addr = 0;
			fd = open(av[1], O_RDONLY);
			if (fd < 0)
				ft_error("ERROR!\nPath map name invalid.\n");
			g_data.map = read_map(fd);
			if (!g_data.map || !ft_strncmp(g_data.map, "", 1))
				ft_error("ERROR!!\nMap invalid.\n");
			game();
		}
	}
	return (0);
}
