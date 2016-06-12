/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_putendl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int				ft_error(int e, int r)
{
	if (e == 0)
	{
		ft_putstr("USAGE: ./fractol [julia, mandelbrot, buddhabrot,");
		ft_putendl("sierpinski, scarpet]");
	}
	return (r);
}

void			ft_putstr(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void			ft_init_struct(t_data *data)
{
	data->ismove = false;
	data->isfirst = false;
	data->reset = false;
	data->randcol = false;
	data->scale = 0;
	data->buddaint = 0;
	data->sizel = 0;
	data->stack = 0;
	data->test1 = 0;
	data->z_rbkp = 0;
	data->z_ibkp = 0;
}

int				ft_check_fractal(t_data *data, char *str)
{
	ft_init_struct(data);
	if (!ft_strcmp(str, "buddhabrot"))
		ft_init_buddhabrot(data);
	else if (!ft_strcmp(str, "mandelbrot"))
		ft_init_mandelbrot(data);
	else if (!ft_strcmp(str, "julia"))
		ft_init_julia(data);
	else if (!ft_strcmp(str, "scarpet"))
		ft_init_scarpet(data);
	else if (!ft_strcmp(str, "sierpinski"))
		ft_init_sierpinski(data);
	else
		return (ft_error(0, -1));
	return (data->type);
}
