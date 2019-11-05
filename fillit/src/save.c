/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:40:10 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/05 17:38:30 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //testing
#include <stdlib.h>

void	print_list(tetris *list) //tesing
{
	while (list)
	{
		printf("%c - NAME\n%d %d\n%d %d\n%d %d\n%d %d\nx y\n%p next\n", list->name, list->tetri[0].x, list->tetri[0].y,
		list->tetri[1].x, list->tetri[1].y, list->tetri[2].x, list->tetri[2].y, list->tetri[3].x, list->tetri[3].y, list->next);
		list = list->next;
	}
}

tetris	*create_node(tetris *list, point *sharps, char name)
{
		list = (tetris *)malloc(sizeof(tetris));
		list->name = name;
		list->next = NULL;
		list->tetri = sharps;
	return (list);
}

void	delete_list(tetris *list)
{
	tetris	*to_del;

	to_del = list;
	while (list)
	{
		list = list->next;
		free(to_del->tetri);
		free(to_del);
		to_del = list;
	}
}

tetris	*push_back(tetris *list, point *sharps)
{
	tetris	*begin;
	char	name;

	if (list && sharps)
	{
		begin = list;
		name = list->name;
		while (list->next)
		{
			list = list->next;
			name++;
		}
		name++;
		list->next = create_node(list->next, sharps, name);	
	}
	else
		delete_list(list);
	list = begin;
	return (list);
}

tetris	*save_tetri(point *sharps, tetris *list)
{
	if (!sharps)
		delete_list(list);
	else if (!list)
	{
		if (!(list = create_node(list, sharps, 'A')))
			delete_list(list);
	}
	else
		if (!(list = push_back(list, sharps)))
			delete_list(list);
	print_list(list); //testing
	return (list);
}
