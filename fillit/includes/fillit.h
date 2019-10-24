/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/23 19:02:03 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>

typedef struct  s_point
{
    int         x;
    int         y;
}               point;

void    read_data(char *file_name);
int     check_data(char *data);
int     count_sharps(char *data);
int     check_symbols(char *data);
int     check_tetri(char *data);

# endif
