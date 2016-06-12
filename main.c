/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_data *data)
{
	if (data->type == 0)
		ft_julia(data);
	else if (data->type == 1)
		ft_mandelbrot(data);
	else if (data->type == 2)
		ft_buddhabrot(data);
	else if (data->type == 3)
		ft_scarpet(data);
	else if (data->type == 4)
		ft_sierpinski(data);
	return (0);
}

int			ft_motion_hook(int x, int y, t_data *data)
{
	static int c;

	c = 0;
	if (x % 4 && y % 4)
	{
		if (!data->isfirst)
		{
			data->ismove = true;
			data->isfirst = true;
		}
		if (data->ismove)
		{
			data->mx = x;
			data->my = y;
		}
		expose_hook(data);
	}
	if (data->randcol)
	{
		if (c++ > data->maxc)
			data->test1 = rand();
		else
			data->test1 += 10;
	}
	return (0);
}

int			ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		x = (double)(WIDTH - x) - (WIDTH / 2);
		y = (double)(HEIGHT - y) - (HEIGHT / 2);
		data->zoom += 1 + (int)data->zoom % 10;
		data->x1 -= (x / 40 / (data->zoom / 10));
		data->x2 -= (x / 40 / (data->zoom / 10));
		data->y1 -= (y / 60 / (data->zoom / 10));
		data->y2 -= (y / 60 / (data->zoom / 10));
	}
	else if (button == 4)
		data->zoom -= 1 + (int)data->zoom % 10;
	expose_hook(data);
	return (0);
}

void		ft_fractol(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyRelease, ft_key_press, data);
	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask,
	ft_motion_hook, data);
	mlx_mouse_hook(data->mlx_win, ft_mouse_hook, data);
	mlx_expose_hook(data->mlx_win, expose_hook, data);
	mlx_loop(data->mlxptr);
}

int			main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (ft_error(0, EXIT_FAILURE));
	if ((data.mlxptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlxptr,
	WIDTH, HEIGHT, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_img = mlx_new_image(data.mlxptr, WIDTH, HEIGHT)) == NULL)
		return (EXIT_FAILURE);
	if (!(data.str = mlx_get_data_addr(data.mlx_img, &(data.bpp),
	&(data.sizel), &(data.endian))))
		return (EXIT_FAILURE);
	if ((data.type = ft_check_fractal(&data, av[1])) < 0)
		return (EXIT_FAILURE);
	ft_fractol(&data);
	return (EXIT_SUCCESS);
}
