/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:05:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/15 16:02:13 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int all_white(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
	}
	return(1);
}

int dot_cub(char *str)
{
	if (ft_strcmp(str + (ft_strlen(str) - ft_strlen(".cub"))
		, ".cub") || open(str, O_RDWR) < 0)
	{
		printf("Error\nfile_err\n");
		return (0);
	}
	return (1);
}
