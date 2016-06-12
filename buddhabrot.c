/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_buddhabrot2_extend(t_data *data, int *i, bool *test)
{
	double		tmp;

	tmp = 0;
	while (*i < data->iteration_max)
	{
		tmp = data->z_r;
		data->z_r = (data->z_r * data->z_r) - (data->z_i * data->z_i)
		+ data->c_r;
		data->z_i = 2 * data->z_i * tmp + data->c_i;
		if (data->z_r * data->z_r + data->z_i * data->z_i > 2)
		{
			*test = true;
			break ;
		}
		*i += 1;
	}
}

void			ft_buddhabrot2(t_data *data, int x, int y)
{
	int			i;
	bool		test;
	int			j;

	j = 0;
	i = 0;
	test = false;
	if (data->ismove)
	{
		data->z_r = (data->mx - (WIDTH / 2)) / 500;
		data->z_i = (data->my - (HEIGHT / 2)) / 500;
	}
	data->c_r = x / data->zoom + data->x1;
	data->c_i = y / data->zoom + data->y1;
	ft_buddhabrot2_extend(data, &i, &test);
	if (test)
	{
		while (j++ < i)
			data->pixel[y][x] += data->buddaint;
	}
}

void			ft_buddhabrot3(t_data *data)
{
	int			i;
	int			j;
	int			color;

	j = 0;
	i = 0;
	color = 0;
	data->x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->i = 0;
			color = (ft_min(data->pixel[j][i], 255) << 16) |
			(ft_min(data->pixel[j][i], 255) << 8) |
			ft_min(data->pixel[j][i], 255);
			ft_draw_pixel(data, color);
			data->x++;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlxptr, data->mlx_win, data->mlx_img, 0, 0);
}

void			ft_buddhabrot(t_data *data)
{
	int			i;
	int			j;
	int			n;

	i = 0;
	n = 0;
	data->x = 0;
	if (!data->stack)
		ft_reset_pixel_tab(data);
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->i = 0;
			ft_buddhabrot2(data, j, i);
			data->z_r = 0;
			data->z_i = 0;
			j++;
			data->x++;
		}
		i++;
	}
	if (data->ismove)
		ft_buddhabrot3(data);
}

void			ft_init_buddhabrot(t_data *data)
{
	data->x1 = -2.3;
	data->x2 = 2.3;
	data->y1 = -2.3;
	data->y2 = 2.3;
	data->zoom = 200;
	data->iteration_max = 100;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	data->type = 2;
	data->buddaint = 1;
	data->reset = true;
}
