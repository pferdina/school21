/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:55:06 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/12 22:48:53 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_y(char *file_name)
{
	char	*line;
	int 	fd;
	int		y;

	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

int		get_x(char *filename)
{
	int		x;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (x);
}

void	fill_matrix(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->y = get_y(file_name);
	data->x = get_x(file_name);
	data->z = (int**)malloc(sizeof(int*) * (data->y + 1));
	data->z[data->y] = NULL;
	i = 0;
	while (i < data->y)
	{
		data->z[i] = (int*)malloc(sizeof(int) * (data->x + 1));
		i++;
	}
	fd = open (file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z[i], line);
		i++;
		free(line);
	}
	close(fd);
}