/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:57:22 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:12 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		item_in_ranges(t_tetris *list, t_point *pos, int size)
{
	if (list->tetri[0].x + pos->x < 0 || list->tetri[0].x + pos->x >= size)
		return (0);
	if (list->tetri[1].x + pos->x < 0 || list->tetri[1].x + pos->x >= size)
		return (0);
	if (list->tetri[2].x + pos->x < 0 || list->tetri[2].x + pos->x >= size)
		return (0);
	if (list->tetri[3].x + pos->x < 0 || list->tetri[3].x + pos->x >= size)
		return (0);
	if (list->tetri[0].y + pos->y < 0 || list->tetri[0].y + pos->y >= size)
		return (0);
	if (list->tetri[1].y + pos->y < 0 || list->tetri[1].y + pos->y >= size)
		return (0);
	if (list->tetri[2].y + pos->y < 0 || list->tetri[2].y + pos->y >= size)
		return (0);
	if (list->tetri[3].y + pos->y < 0 || list->tetri[3].y + pos->y >= size)
		return (0);
	return (1);
}

int		place_tetri(t_map *map, t_point *pos, t_tetris *list)
{
	if (!item_in_ranges(list, pos, map->size))
		return (0);
	if (map->map[list->tetri[0].x + pos->x][list->tetri[0].y + pos->y] != '.')
		return (0);
	if (map->map[list->tetri[1].x + pos->x][list->tetri[1].y + pos->y] != '.')
		return (0);
	if (map->map[list->tetri[2].x + pos->x][list->tetri[2].y + pos->y] != '.')
		return (0);
	if (map->map[list->tetri[3].x + pos->x][list->tetri[3].y + pos->y] != '.')
		return (0);
	map->map[list->tetri[0].x + pos->x][list->tetri[0].y + pos->y] = list->name;
	map->map[list->tetri[1].x + pos->x][list->tetri[1].y + pos->y] = list->name;
	map->map[list->tetri[2].x + pos->x][list->tetri[2].y + pos->y] = list->name;
	map->map[list->tetri[3].x + pos->x][list->tetri[3].y + pos->y] = list->name;
	return (1);
}

void	clear_last(t_map *map, t_point *pos, t_tetris *list)
{
	map->map[list->tetri[0].x + pos->x][list->tetri[0].y + pos->y] = '.';
	map->map[list->tetri[1].x + pos->x][list->tetri[1].y + pos->y] = '.';
	map->map[list->tetri[2].x + pos->x][list->tetri[2].y + pos->y] = '.';
	map->map[list->tetri[3].x + pos->x][list->tetri[3].y + pos->y] = '.';
}

int		free_n_return(t_point *point)
{
	free(point);
	return (1);
}

int		solve_map(t_map *map, t_tetris *list)
{
	t_point *pos;

	if (!list)
		return (1);
	pos = (t_point*)malloc(sizeof(t_point));
	pos->y = 0;
	while (pos->y < map->size)
	{
		pos->x = 0;
		while (pos->x < map->size)
		{
			if (place_tetri(map, pos, list))
			{
				if (solve_map(map, list->next))
					return (free_n_return(pos));
				else
					clear_last(map, pos, list);
			}
			pos->x++;
		}
		pos->y++;
	}
	free(pos);
	return (0);
}

int		get_solution(t_map *map, t_tetris *list)
{
	if (solve_map(map, list))
	{
		print_map(map);
		delete_map(map);
		return (1);
	}
	return (0);
}

void	solve(t_tetris *list)
{
	t_map	*map;
	int		size;

	map = generate_map(get_map_size(list));
	size = map->size;
	while (!get_solution(map, list))
	{
		size++;
		delete_map(map);
		map = generate_map(size);
	}
}
