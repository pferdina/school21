/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:02 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/28 15:59:22 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
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
    point   *sharps;

    i = 0;
    j = 1;
    counter = 0;
    sharps = get_sharps(data);
    while (data[i])
    {
        if (data[i] == data[i + 1] && data[i] == '#')
            counter++;
        if (data[i] == data[i + 5] && data[i] == '#')
            counter++;
        i++;
    }
    printf("%d\n", counter);
    if ((counter != 3  && counter != 4))
    {
        save_tetri(NULL);
        return (0);
    }
    else if (!save_tetri(sharps))
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