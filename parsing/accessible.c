/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:03:32 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 23:31:17 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	accessible(void)
{
	int	fd;

	fd = open(g_parser->path_ea, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_parser->path_no, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_parser->path_so, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_parser->path_we, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
