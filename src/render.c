/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:12 by jhue              #+#    #+#             */
/*   Updated: 2024/01/31 11:26:44 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_other(t_fractol *f)
{
	f->fractal = BURNINGSHIP;
	f->min_r = 3;
	f->max_r = -3;
	f->min_i = 3;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
}

int	calculate_fractal(double zr, double zi, t_fractol *f)
{
	if (f->fractal == MANDELBROT)
		return (ft_mandelbrot(zr, zi));
	else if (f->fractal == JULIA)
		return (ft_julia(zr, zi, f));
	else
		return (ft_burningship(zr, zi));
	return (0);
}

static void	put_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->buf[(x + y * WIDTH) * 4] = color;
	f->buf[(x + y * WIDTH) * 4 + 1] = color >> 8;
	f->buf[(x + y * WIDTH) * 4 + 2] = color >> 16;
	f->buf[(x + y * WIDTH) * 4 + 3] = color >> 24;
}

void	render(t_fractol *f)
{
	int		n;
	int		x;
	int		y;
	double	zr;
	double	zi;

	y = -1;
	mlx_clear_window(f->mlx, f->win);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			zr = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
			zi = f->max_i - ((double)y * (f->max_i - f->min_i) / HEIGHT);
			n = calculate_fractal(zr, zi, f);
			put_pixel_color(f, x, y, f->color_range[n]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
