/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:51:13 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/23 19:02:19 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int			x;
	int			y;
	int			**z;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	float		angle;
	float		zoom_z;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void			read_file(char *file_name, t_fdf *data);
void			bresenham(float x, float y, float x1, float y1, t_fdf *data);
void			draw(t_fdf *data);

#endif
