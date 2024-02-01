/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:06:04 by jhue              #+#    #+#             */
/*   Updated: 2024/01/31 11:24:55 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->fractal = MANDELBROT;
	f->min_i = -1.2;
	f->min_r = -2;
	f->max_r = 1;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	f->ki = 0;
	f->kr = 0;
	f->color_pattern = -1;
	f->buf = NULL;
}

static void	set_img(t_fractol *f)
{
	int	endian;
	int	pixel_bit;
	int	size_line;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		ft_exit(f, "Error, image wasn't created.\n");
	f->buf = mlx_get_data_addr(f->img, &pixel_bit, &size_line, &endian);
}

void	reset_img(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	set_img(f);
}

void	change_fractal(int fract, t_fractol *f)
{
	if (fract == MANDELBROT)
	{
		f->fractal = MANDELBROT;
		f->min_i = -1.2;
		f->min_r = -2;
		f->max_r = 1;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (fract == JULIA)
	{
		f->fractal = JULIA;
		f->min_i = -2;
		f->min_r = -2;
		f->max_r = 2;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
		change_other(f);
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		ft_exit(f, "Error, mlx doesn't start.\n");
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		ft_exit(f, "Error, window wasn't created.\n");
	color_shift(f);
}
