/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:02 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/25 19:37:41 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
#include <stdio.h> //testing
#include <stdlib.h>

int     count_sharps(char *data)
{
    int counter;

    counter = 0;
    while (*data)
    {
        if (*data == '#')
            counter++;
        data++;
    }
    return (counter);
}

int     check_symbols(char *data)
{
    int i;

    i = 0;
    if (count_sharps(data) != 4)
        return (0);
    while (data[i])
    {
        if (data[i] != '.' && data[i] != '#')
        {
            if (i % 5 == 4 && data[i] == '\n')
            {
                i++;
                continue ;
            }
            return (0);
        }
        i++;  
    }
    return (1);
}

point   *get_sharps(char *data)
{
    point   *sharps;
    int     sharp;
    int     i;

    sharp = 0;
    i = 0;
    sharps = (point*)malloc(sizeof(point) * 4);
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
    return (sharps);
}

int    check_tetri(char *data)
{
    int     counter;
    int     i;
    point   *sharps;

    i = 0;
    counter = 0;
    sharps = get_sharps(data);
    while (i < 4)
    {
        if ((sharps[i].x + 1 == sharps[i + 1].x && sharps[i].y == sharps[i + 1].y) || 
            (sharps[i].y + 1 == sharps[i + 1].y && sharps[i].x == sharps[i + 1].x))
            counter += 2;
        if (i == 0 && sharps[i].x + 1 == sharps [i + 3].x &&
            sharps[i].y + 1 == sharps [i + 3].y &&
            sharps[i + 1].x - 1 == sharps[i + 2].x && 
            sharps[i + 1].y + 1 == sharps[i + 2].y)
            counter += 2;
        if ((i == 0 || i == 2) && sharps[i].x - 1 == sharps[i + 1].x &&
            sharps[i].y + 1 == sharps[i + 1].y)
            counter += 2;
        i++;
    }
    printf("%d\n", counter);
    if (counter != 6  && counter != 8)
        return (0);
/*    if (!save_tetri(sharps))
        return (0); */
    return (1);
}

int    check_data(char *data)
{
    if (data[20] != 0)
    {
        if (data[20] == '\n')
            data[20] = '\0';
        else if (data[20] != '\0')
            return (0);
    }
    if (!check_symbols(data))
        return (0);
    if (!check_tetri(data))
        return (0);
    return (1);
}