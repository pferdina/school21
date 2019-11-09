/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:02 by pferdina          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:09 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_sharps(char *data)
{
	int counter;

	counter = 0;
	while (*data)
	{
		if (*data == '#')
			counter++;
		data++;
	}
	return (counter);
}

int		check_symbols(char *data)
{
	int i;

	i = 0;
	if (count_sharps(data) != 4)
		return (0);
	while (data[i])
	{
		if (data[i] != '.' && data[i] != '#')
		{
			if (i % 5 == 4 && data[i] == '\n')
			{
				i++;
				continue ;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_tetri(char *data)
{
	int		counter;
	int		i;
	int		j;

	i = 0;
	j = 1;
	counter = 0;
	while (data[i])
	{
		if (data[i] == data[i + 1] && data[i] == '#')
			counter++;
		if (data[i] == data[i + 5] && data[i] == '#')
			counter++;
		i++;
	}
	if ((counter != 3 && counter != 4))
		return (0);
	return (1);
}

int		check_data(char *data)
{
	char	*tmp;

	tmp = ft_strdup(data);
	if (tmp[20] != 0)
	{
		if (tmp[20] == '\n')
			tmp[20] = '\0';
		else if (tmp[20] != '\0')
			return (0);
	}
	if (!check_symbols(tmp))
	{
		free(tmp);
		return (0);
	}
	if (!check_tetri(tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
