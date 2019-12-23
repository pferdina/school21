/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:50:13 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/23 02:48:50 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define MOD(a) ((a > 0) ? a : -a)

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z[(int)y][(int)x];
	z1 = data->z[(int)y1][(int)x1];

	// zooming
	x *= data->zoom;
	x1 *= data->zoom;
	y *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom_z;
	z1 *= data->zoom_z;
	// color
	data->color = (z || z1) ?  0xffffff : 0xe80c0c;
	// 3D
	isometric(&x, &y, z, data->angle);
	isometric(&x1, &y1, z1, data->angle);
	//shift
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->y - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}