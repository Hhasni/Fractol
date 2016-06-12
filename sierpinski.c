/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_sierpinski2(t_data *data, int x, int y)
{
	int				i;
	double			tmp1;
	double			tmp2;

	i = 0;
	tmp1 = 0;
	tmp2 = 0;
	x = x / data->zoom + data->x1;
	x = y / data->zoom + data->y1;
	while ((data->z_r * data->z_r + data->z_i * data->z_i) < 4
	&& i < data->iteration_max)
	{
		tmp1 = data->z_r;
		tmp2 = data->z_i;
		data->z_r = tmp1 * tmp1 - tmp2 * tmp2 + data->c_r;
		data->z_i = tmp1 * tmp2 + tmp1 * tmp2 + data->c_i;
		i++;
	}
	if (i == data->iteration_max)
		ft_draw_pixel(data, 0x19B5FE);
	else
		ft_draw_pixel(data, i * 1000 / data->iteration_max);
}

void				ft_init_sierpinski(t_data *data)
{
	data->scale = 0.1;
	data->x1 = -5;
	data->x2 = 5;
	data->y1 = -5;
	data->y2 = 5;
	data->zoom = 0.1;
	data->iteration_max = 50;
	data->type = 4;
	data->buddaint = 1;
}

void				ft_sierpinski(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	data->x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->i = 0;
			if ((i & j) == 0)
			{
				if (i == data->iteration_max)
					ft_draw_pixel(data, 0x19B5FE);
				else
					ft_draw_pixel(data, i * 1000 / data->iteration_max);
			}
			data->x++;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlxptr, data->mlx_win, data->mlx_img, 0, 0);
}
