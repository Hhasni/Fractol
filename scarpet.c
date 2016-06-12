/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scarpet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_scarpet2(t_data *data, int x, int y)
{
	int			i;

	i = 0;
	x = x / data->zoom + data->x1;
	y = y / data->zoom + data->y1;
	while ((x > 0 || y > 0) && i < data->iteration_max)
	{
		if (x % 3 == 1 && y % 3 == 1)
			break ;
		x /= 3;
		y /= 3;
		i++;
	}
	if (i == data->iteration_max)
		ft_draw_pixel(data, 0x19B5FE);
	else
		ft_draw_pixel(data, i * 1000 / data->iteration_max);
}

void			ft_init_scarpet(t_data *data)
{
	data->scale = 0.1;
	data->x1 = -5;
	data->x2 = 5;
	data->y1 = -5;
	data->y2 = 5;
	data->zoom = 0.1;
	data->iteration_max = 50;
	data->type = 3;
	data->buddaint = 1;
}

void			ft_scarpet(t_data *data)
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
			data->i = 0;
			ft_scarpet2(data, j, i);
			data->x++;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlxptr, data->mlx_win, data->mlx_img, 0, 0);
}
