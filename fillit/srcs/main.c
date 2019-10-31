/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:14 by pferdina          #+#    #+#             */
/*   Updated: 2019/10/31 16:27:15 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft/libft.h"
#include <stdio.h> // testing

int	main(int ac, char **av)
{
	int		fd;
	tetris	*list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	list = read_data(av[1]);
	solve(list);
	return (0);
}
