/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_julia2(t_data *data, int x, int y)
{
	int			i;
	double		tmp;

	i = 0;
	tmp = 0;
	if (data->ismove)
	{
		data->c_r = (data->mx - (WIDTH / 2)) / 500;
		data->c_i = (data->my - (HEIGHT / 2)) / 500;
	}
	data->z_r = x / data->zoom + data->x1;
	data->z_i = y / data->zoom + data->y1;
	while (data->z_r * data->z_r + data->z_i * data->z_i <
	4 && i < data->iteration_max)
	{
		tmp = data->z_r;
		data->z_r = (data->z_r * data->z_r)
		- (data->z_i * data->z_i) + data->c_r;
		data->z_i = 2 * data->z_i * tmp + data->c_i;
		i++;
	}
	if (i == data->iteration_max)
		ft_draw_pixel(data, 0x19B5FE);
	else
		ft_draw_pixel(data, i * 1000 / data->iteration_max);
}

void			ft_julia(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	data->x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->i = 0;
			ft_julia2(data, j, i);
			data->x++;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlxptr, data->mlx_win, data->mlx_img, 0, 0);
}

void			ft_init_julia(t_data *data)
{
	data->scale = 1;
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
	data->type = 0;
	data->buddaint = 1;
}
