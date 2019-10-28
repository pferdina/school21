/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:41 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/28 15:21:55 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
#include <stdio.h> //testing

void    read_data(char *file_name)
{
    int     fd;
    int     buff_size;
    char    buffer[21];

    if ((fd = open(file_name, O_RDONLY)) == -1)
    {
        ft_putendl("error");
        return ;
    }
    while ((buff_size = read(fd, buffer, 21)))
    {
        if (buff_size >= 19)
        {
            if (!check_data(buffer))
            {
                ft_putendl("error");
                break ;
            }
        }
        else
        {
            ft_putendl("error");
            break ;
        }
    }
    close(fd);
}