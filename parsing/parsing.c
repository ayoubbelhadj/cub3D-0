/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:40 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 23:38:49 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	printerr(int e)
{
	printf("Error\n");
	if (e == 1)
		printf("check extension");
	else if (e == 2)
		printf("check file");
	else if (e == 3)
		printf("check colors");
	else if (e == 4)
		printf("check the paths");
}

int parsing(char *str)
{
	if (!dot_cub(str))
		return (printerr(1), 0);
	if (!check_lines(str))
		return (printerr(2), 0);
	if (!check_colors())
		return (printerr(3), 0);
	if (!accessible())
		return (printerr(4), 0);
	return (1);
}
