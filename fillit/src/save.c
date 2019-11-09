/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:40:10 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:11 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*create_node(t_tetris *list, t_point *sharps, char name)
{
	list = (t_tetris *)malloc(sizeof(t_tetris));
	list->name = name;
	list->next = NULL;
	list->tetri = sharps;
	return (list);
}

void	delete_list(t_tetris *list)
{
	t_tetris	*to_del;

	while (list)
	{
		to_del = list;
		list = list->next;
		free(to_del->tetri);
		free(to_del);
		to_del = NULL;
	}
}

t_tetris	*push_back(t_tetris *list, t_point *sharps)
{
	t_tetris	*begin;
	char		name;
	
	begin = list;
	if (list && sharps)
	{
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

t_tetris	*save_tetri(t_point *sharps, t_tetris *list)
{
	if (!sharps)
		delete_list(list);
	else if (!list)
	{
		if (!(list = create_node(list, sharps, 'A')))
			delete_list(list);
	}
	else if (!(list = push_back(list, sharps)))
		delete_list(list);
	return (list);
}
