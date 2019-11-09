/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:02 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	int					size;
	char				**map;
}					t_map;

typedef struct		s_point
{
	int					x;
	int					y;
}					t_point;

typedef struct		s_tetris
{
	char				name;
	struct s_tetris		*next;
	t_point				*tetri;
}					t_tetris;

t_tetris			*read_data(char *file_name);
int					check_data(char *data);
int					count_sharps(char *data);
int					check_symbols(char *data);
int					check_tetri(char *data);
t_tetris			*save_tetri(t_point *sharps, t_tetris *list);
t_point				*get_sharps(char *data);
t_point				*optimize_sharps(t_point *sharps);
t_tetris			*create_node(t_tetris *list, t_point *sharps, char name);
t_tetris			*push_back(t_tetris *list, t_point *sharps);
void				delete_list(t_tetris *list);
int					count_tetris(t_tetris *list);
int					get_map_size(t_tetris *list);
t_map				*generate_map(int size);
void				solve(t_tetris *list);
void				delete_map(t_map *map);
void				print_map(t_map *map);
int					solve_map(t_map *map, t_tetris *list);
int					free_n_return(t_point *point);
void				clear_last(t_map *map, t_point *pos, t_tetris *list);
int					place_tetri(t_map *map, t_point *pos, t_tetris *list);
int					item_in_ranges(t_tetris *list, t_point *pos, int size);

#endif
