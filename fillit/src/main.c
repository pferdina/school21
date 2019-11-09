/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:14 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:10 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetris	*list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	list = read_data(av[1]);
	if (!list)
	{
		ft_putendl("error");
		return (0);
	}
	solve(list);
	delete_list(list);
	return (0);
}
