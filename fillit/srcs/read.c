/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:41 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/31 15:50:17 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
#include <stdio.h> //testing

tetris  *read_data(char *file_name)
{
    int     fd;
    int     buff_size;
    char    buffer[21];
    tetris  *list;
    point   *sharps;

    if ((fd = open(file_name, O_RDONLY)) == -1)
    {
        ft_putendl("error");
        return NULL;
    }
    list = NULL;
    while ((buff_size = read(fd, buffer, 21)))
    {
        if (buff_size < 19 || !check_data(&buffer[0]))
        {
            ft_putendl("error");
            break ;
        }
        sharps = get_sharps(buffer);
        list = save_tetri(sharps, list);
    }
    close(fd);
    return (list);
}