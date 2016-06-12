/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw_pixel(t_data *data, int color)
{
	int			in;

	in = (data->bpp >> 3) * (((int)data->i * (data->sizel >> 2))
	+ (int)data->x);
	data->str[in] = color + data->test1 & 0xff;
	data->str[in + 1] = (color + data->test1 & 0xff00) >> 8;
	data->str[in + 2] = (color + data->test1 & 0xff0000) >> 16;
	data->i++;
}
