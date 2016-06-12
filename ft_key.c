/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_arrow_press(int keycode, t_data *data)
{
	if (keycode == MLX_KEY_LEFT)
	{
		data->x1 -= 4 / data->zoom;
		data->x2 -= 4 / data->zoom;
	}
	else if (keycode == MLX_KEY_RIGHT)
	{
		data->x1 += 4 / data->zoom;
		data->x2 += 4 / data->zoom;
	}
	else if (keycode == MLX_KEY_UP)
	{
		data->y1 -= 4 / data->zoom;
		data->y2 -= 4 / data->zoom;
	}
	else if (keycode == MLX_KEY_DOWN)
	{
		data->y1 += 4 / data->zoom;
		data->y2 += 4 / data->zoom;
	}
	else
		return ;
	expose_hook(data);
}

static void			ft_other_press(int keycode, t_data *data)
{
	if (keycode == MLX_KEY_ESC)
		exit(0);
	else if (keycode == MLX_KEY_MINUS && data->iteration_max > 1)
		data->iteration_max -= 1;
	else if (keycode == MLX_KEY_EQUAL && data->iteration_max < 1000)
		data->iteration_max += 1;
	else if (keycode == MLX_KEY_1 && data->buddaint > 1)
		data->buddaint -= 1;
	else if (keycode == MLX_KEY_2)
		data->buddaint += 1;
	else if (keycode == MLX_KEY_R)
		data->reset = !data->reset;
	else if (keycode == MLX_KEY_C)
		data->randcol = !data->randcol;
	expose_hook(data);
}

static void			ft_other_press2(int keycode, t_data *data)
{
	if (keycode == MLX_KEY_X && data->maxc < 100)
		data->maxc += 1;
	else if (keycode == MLX_KEY_Z && data->maxc > 0)
		data->maxc -= 1;
	else if (keycode == MLX_KEY_SPACE)
		data->ismove = !data->ismove;
	else if (keycode == MLX_KEY_S)
		data->stack = !data->stack;
	else
		return ;
	expose_hook(data);
}

int					ft_key_press(int keycode, t_data *data)
{
	ft_arrow_press(keycode, data);
	ft_other_press(keycode, data);
	ft_other_press2(keycode, data);
	return (0);
}
