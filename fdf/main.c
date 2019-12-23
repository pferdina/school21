/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:38:28 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/23 19:07:06 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
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
		data->zoom_z -= 0.1;
	else if (key == 1)
		data->zoom_z += 0.1;
	else if (key == 53)
	{
		exit(0);
		return (mlx_destroy_window(data->mlx_ptr, data->win_ptr));
	}
	else
		return (0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->zoom = 20;
	data->angle = 0.6;
	data->zoom_z = 0.2;
	data->shift_x = 150;
	data->shift_y = 150;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
