/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:40 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 16:07:24 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int parsing(char *str)
{
	if (!dot_cub(str))
	{
		printf("Error\n");
		printf("check extension");
		return (0);
	}
	if (!check_lines(str))
	{
		printf("Error\n");
		printf("check file");
		return (0);
	}
	if (!check_colors())
	{
		printf("Error\n");
		printf("check colors");
		return (0);
	}
	return (1);
}