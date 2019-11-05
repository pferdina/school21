/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/05 19:22:50 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct      s_map
{
    int             size;
    char            **map;
}                   map;

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

tetris              *read_data(char *file_name);
int                 check_data(char *data);
int                 count_sharps(char *data);
int                 check_symbols(char *data);
int                 check_tetri(char *data);
tetris              *save_tetri(point *sharps, tetris *list);
point               *get_sharps(char *data);
point               *optimize_sharps(point *sharps);
tetris	            *create_node(tetris *list, point *sharps, char name);
tetris	            *push_back(tetris *list, point *sharps);
void	            delete_list(tetris *list);
void	            print_list(tetris *list); //testing
int                 count_tetris(tetris *list);
int                 get_map_size(tetris *list);
map                 *generate_map(int size);
void                solve(tetris *list);
void                delete_map(map *map);
void                print_map(map *map);
int    solve_map(map *map, tetris *list);
int     free_n_return(point *point);
void    clear_last(map *map, point *pos, tetris *list);
int		place_tetri(map *map, point *pos, tetris *list);
int		item_in_ranges(tetris *list, point *pos, int size);
# endif
