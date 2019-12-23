/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:51:13 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/23 02:47:53 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	fdf
{
	int			x;
	int			y;
	int			**z;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	float		angle;
	int			zoom_z;

	void		*mlx_ptr;
	void		*win_ptr;
}				fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif