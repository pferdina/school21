/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:41 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:11 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*throw_error(t_tetris *list)
{
	delete_list(list);
	return (NULL);
}

int			check_last(int check)
{
	if (check != 20)
		return (0);
	return (1);
}

t_tetris	*check_n_result(int fd, int *buff_size, t_tetris *list)
{
	if (!check_last(buff_size[1]))
		list = throw_error(list);
	close(fd);
	free(buff_size);
	return (list);
}

t_tetris	*read_data(char *file_name)
{
	int			fd;
	int			*buff_size;
	char		buffer[21];
	t_tetris	*list;
	t_point		*sharps;

	list = NULL;
	buff_size = (int*)malloc(sizeof(int) * 2);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		list = throw_error(list);
	while ((buff_size[0] = read(fd, buffer, 21)))
	{
		buff_size[1] = buff_size[0];
		if (buff_size[0] < 20 || !check_data(&buffer[0]))
		{
			list = throw_error(list);
			break ;
		}
		sharps = get_sharps(buffer);
		list = save_tetri(sharps, list);
	}
	return (list = check_n_result(fd, buff_size, list));
}