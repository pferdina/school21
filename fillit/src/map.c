/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:54 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/05 20:40:22 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //testing
#include <stdlib.h>

int		count_tetris(t_tetris *list)
{
	int counter;

	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

int		get_map_size(t_tetris *list)
{
	int counter;
	int size;

	size = 1;
	counter = count_tetris(list);
	while (size * size < (counter * 4))
		size++;
	return (size);
}

void	delete_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map);
	return ;
}

t_map	*fill_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			map->map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void	print_map(t_map *map) // testing
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			printf("%c", map->map[j][i]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

t_map	*generate_map(int size)
{
	t_map	*field;
	int		i;

	if (!(field = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	field->size = size;
	if (!(field->map = (char**)malloc(sizeof(char*) * (size + 1))))
	{
		free(field);
		return (NULL);
	}
	i = 0;
	field->map[size] = 0;
	while (i < size)
	{
		if (!(field->map[i] = ft_strnew(size)))
		{
			delete_map(field);
			return (NULL);
		}
		i++;
	}
	field = fill_map(field);
   // print_map(field); //testing
	return (field);
}
