/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:38:28 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/23 02:51:18 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	ft_printf("%d - KEY\n", key);
	if (key == 123)
		data->shift_x -= 20;
	else if (key == 124)
		data->shift_x += 20;
	else if (key == 126)
		data->shift_y -= 20;
	else if (key == 125)
		data->shift_y += 20;
	else if (key == 24)
		data->zoom += 1;
	else if (key == 27)
		data->zoom -= 1;
	else if (key == 6)
		data->angle -= 0.1;
	else if (key == 7)
		data->angle += 0.1;
	else if (key == 0)
		data->zoom_z -= 1;
	else if (key == 1)
		data->zoom_z += 1;
	else if (key == 53)
	{
		mlx_destroy_window;
		exit(0);
	}
	else
		return (0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		deal_mouse(int key, fdf *data)
{
	ft_printf("%d - MOUSE\n", key);
	// if (key == 1)
	// 	data->zoom -= 1;
	// if (key == 2)
	// 	data->zoom += 1;
	// mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// draw(data);
	return (0);
}

int		main(int ac, char **av)
{
	fdf	*data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(av[1], data);

	// int i;
	// int j;

	// i = 0;
	// while (i < data->y)
	// {
	// 	j = 0;
	// 	while (j < data->x)
	// 	{
	// 		ft_printf("%3d ", data->z[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->zoom = 20;
	data->angle = 0.6;
	data->zoom_z = 2;
	data->shift_x = 150;
	data->shift_y = 150;
	// bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}