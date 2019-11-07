/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:27:55 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/28 14:40:07 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //testing
#include <stdlib.h>

t_point		*optimize_sharps(t_point *sharps)
{
	int min_x;
	int min_y;
	int i;

	min_x = 3;
	min_y = 3;
	i = 0;
	while (i < 4)
	{
		if (min_x > sharps[i].x)
			min_x = sharps[i].x;
		if (min_y > sharps[i].y)
			min_y = sharps[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		sharps[i].x -= min_x;
		sharps[i].y -= min_y;
		i++;
	}
	return (sharps);
}

t_point		*get_sharps(char *data)
{
	t_point		*sharps;
	int			sharp;
	int			i;

	sharp = 0;
	i = 0;
	sharps = (t_point*)malloc(sizeof(t_point) * 4);
	while (data[i])
	{
		if (data[i] == '#')
		{
			sharps[sharp].x = i % 5;
			sharps[sharp].y = i / 5;
			sharp++;
		}
		i++;
	}
	sharps = optimize_sharps(sharps);
	return (sharps);
}
