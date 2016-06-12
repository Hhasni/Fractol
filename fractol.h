/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/09 06:27:40 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <stdbool.h>
# include <unistd.h>
# include <time.h>
# include </usr/X11/include/X11/X.h>

# define MLX_KEY_ESC	53
# define WIDTH	  		1024
# define HEIGHT			768
# define MLX_KEY_MINUS  78
# define MLX_KEY_EQUAL  69
# define MLX_KEY_0		29
# define MLX_KEY_1		18
# define MLX_KEY_2		19
# define MLX_KEY_3		20
# define MLX_KEY_4		21
# define MLX_KEY_5		23
# define MLX_KEY_6		22
# define MLX_KEY_7		26
# define MLX_KEY_8		28
# define MLX_KEY_9		25
# define MLX_KEY_SPACE	49
# define MLX_KEY_LEFT	123
# define MLX_KEY_RIGHT	124
# define MLX_KEY_UP		126
# define MLX_KEY_DOWN	125
# define MLX_KEY_R		15
# define MLX_KEY_C		8
# define MLX_KEY_Z		6
# define MLX_KEY_X		7
# define MLX_KEY_S		1
# define SCROLL_UP		5
# define SCROLL_DOWN	4

typedef struct			s_data
{
	void				*mlxptr;
	void				*mlx_win;
	void				*mlx_img;
	char				type;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_rbkp;
	double				z_ibkp;
	double				z_i;
	double				tmp;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom;
	double				mx;
	double				my;
	double				xoff;
	double				yoff;
	bool				ismove;
	bool				isfirst;
	bool				reset;
	bool				randcol;
	double				iteration_max;
	double				image_x;
	double				image_y;
	int					pixel[1024][1024];
	double				scale;
	int					buddaint;
	char				*str;
	int					sizel;
	int					stack;
	int					test1;
	int					x;
	int					i;
	int					bpp;
	int					endian;
	int					maxc;
}						t_data;

int						ft_min(int a, int b);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strlen(char *s);
char					*ft_strdup(char *str);
void					ft_putendl(char *s);
int						ft_error(int e, int r);
void					ft_draw_pixel(t_data *data, int color);
void					ft_init_sierpinski(t_data *data);
void					ft_init_buddhabrot(t_data *data);
void					ft_init_julia(t_data *data);
void					ft_init_mandelbrot(t_data *data);
void					ft_init_scarpet(t_data *data);
void					ft_julia(t_data *data);
void					ft_sierpinski(t_data *data);
void					ft_mandelbrot(t_data *data);
void					ft_buddhabrot(t_data *data);
void					ft_scarpet(t_data *data);
int						ft_key_press(int keycode, t_data *data);
int						expose_hook(t_data *data);
void					ft_reset_pixel_tab(t_data *data);
void					ft_init_struct(t_data *data);
int						ft_check_fractal(t_data *data, char *str);
void					ft_putstr(char *s);

#endif
