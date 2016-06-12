/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int				ft_strlen(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

char			*ft_strdup(char *str)
{
	char		*new;
	int			len;
	int			i;

	i = 0;
	new = NULL;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

void			ft_reset_pixel_tab(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < 1024)
	{
		j = 0;
		while (j < 1024)
			data->pixel[i][j++] = 0;
		i++;
	}
}
