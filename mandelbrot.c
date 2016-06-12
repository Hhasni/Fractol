/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mandelbrot2_extend(t_data *data, int *i)
{
	double		tmp;

	tmp = 0;
	while (*i < data->iteration_max)
	{
		tmp = data->z_r;
		data->z_r = (data->z_r * data->z_r)
		- (data->z_i * data->z_i) + data->c_r;
		data->z_i = 2 * data->z_i * tmp + data->c_i;
		*i += 1;
		if (data->z_r * data->z_r + data->z_i * data->z_i >= 5
		|| *i >= data->iteration_max)
			break ;
	}
}

void			ft_mandelbrot2(t_data *data, int x, int y)
{
	int			i;

	i = 0;
	if (data->ismove)
	{
		data->z_r = (data->mx - (WIDTH / 2)) / 500;
		data->z_i = (data->my - (HEIGHT / 2)) / 500;
		data->z_rbkp = data->z_r;
		data->z_ibkp = data->z_i;
	}
	else
	{
		data->z_r = (data->mx - (WIDTH / 2)) / 500;
		data->z_i = (data->my - (HEIGHT / 2)) / 500;
	}
	data->c_r = x / data->zoom + data->x1;
	data->c_i = y / data->zoom + data->y1;
	ft_mandelbrot2_extend(data, &i);
	if (i == data->iteration_max)
		ft_draw_pixel(data, 0x19B5FE);
	else
		ft_draw_pixel(data, i * 1000 / data->iteration_max);
}

void			ft_mandelbrot(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	data->x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->z_r = 0;
			data->z_i = 0;
			data->i = 0;
			ft_mandelbrot2(data, j, i);
			data->x++;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlxptr, data->mlx_win, data->mlx_img, 0, 0);
}

void			ft_init_mandelbrot(t_data *data)
{
	data->x1 = -2.5;
	data->x2 = 2.5;
	data->y1 = -2;
	data->y2 = 2;
	data->zoom = 200;
	data->iteration_max = 20;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->type = 1;
	data->buddaint = 1;
}
