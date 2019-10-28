/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/28 15:33:07 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>

typedef struct      s_point
{
    int             x;
    int             y;
}                   point;

typedef struct      s_tetris
{
    char            name;
    struct s_tetris *next;
    point           *tetri;
}                   tetris;


void                read_data(char *file_name);
int                 check_data(char *data);
int                 count_sharps(char *data);
int                 check_symbols(char *data);
int                 check_tetri(char *data);
int                 save_tetri(point *sharps);
point               *get_sharps(char *data);
point               *optimize_sharps(point *sharps);
tetris	            *create_node(tetris *list, point *sharps, char name);
tetris	            *push_back(tetris *list, point *sharps);
void	delete_list(tetris *list);
void	print_list(tetris *list); //testing

# endif
