/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:54 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/31 17:47:10 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
#include <stdio.h> //testing
#include <stdlib.h>

int     count_tetris(tetris *list)
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

int     get_map_size(tetris *list)
{
    int counter;
    int size;

    size = 1;
    counter = count_tetris(list);
    while (size * size < (counter * 4))
        size++;
    return (size);
}

void    delete_map(char **map)
{
    return ;
}

char    **fill_map(char **map, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size)
    {
        while (j < size)
        {
            map[i][j] = '.';
            j++;
        }
        j = 0;
        i++;
    }
    return (map);
}

void    print_map(char **map, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size)
    {
        while (j < size)
        {
            printf("%c", map[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }
}

char    **generate_map(int size)
{
    char    **map;
    int     i;


    if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
        return (NULL);
    i = 0;
    map[size] = 0;
    while (i < size)
    {
        if (!(map[i] = ft_strnew(size)))
        {
            delete_map(map);
            return (NULL);
        }
        i++;
    }
    map = fill_map(map, size);
    print_map(map, size);
    return (map);
}