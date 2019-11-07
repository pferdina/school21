/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:41 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/07 20:15:47 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //testing

void		*throw_error(t_tetris *list)
{
	ft_putendl("error");
	delete_list(list);
	return (NULL);
}

t_tetris	*read_data(char *file_name)
{
	int			fd;
	int			buff_size;
	char		buffer[21];
	t_tetris	*list;
	t_point		*sharps;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	list = NULL;
	buffer[20] = '\0';
	while ((buff_size = read(fd, buffer, 21)))
	{
		if (buff_size < 19 || !check_data(&buffer[0]))
		{
			list = throw_error(list);
			break ;
		}
		sharps = get_sharps(buffer);
		list = save_tetri(sharps, list);
	}
	if (buffer[20] == '\n')
		list = throw_error(list);
	close(fd);
	return (list);
}
