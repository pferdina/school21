/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:02 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/31 15:50:17 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //testing

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

int    check_tetri(char *data)
{
    int     counter;
    int     i;
    int     j;

    i = 0;
    j = 1;
    counter = 0;
    while (data[i])
    {
        if (data[i] == data[i + 1] && data[i] == '#')
            counter++;
        if (data[i] == data[i + 5] && data[i] == '#')
            counter++;
        i++;
    }
    if ((counter != 3  && counter != 4))
        return (0);
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