/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:43:31 by jhue              #+#    #+#             */
/*   Updated: 2024/02/01 11:45:05 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move(double x, double y, t_fractol *f)
{
	double	percent;

	if (x)
		percent = (f->max_r - f->min_r) / (double)WIDTH;
	else
		percent = (f->max_i - f->min_i) / (double)HEIGHT;
	f->min_r = f->min_r + x * percent;
	f->max_r = f->max_r + x * percent;
	f->min_i = f->min_i + y * percent;
	f->max_i = f->max_i + y * percent;
}

static void	ft_zoom(double zoom, int x, int y, t_fractol *f)
{
	double	val_x;
	double	val_y;

	val_x = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
	val_y = f->max_i - ((double)y * (f->max_i - f->min_i) / HEIGHT);
	f->min_r = val_x + (f->min_r - val_x) * zoom;
	f->max_r = val_x + (f->max_r - val_x) * zoom;
	f->min_i = val_y + (f->min_i - val_y) * zoom;
	f->max_i = val_y + (f->max_i - val_y) * zoom;
}

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESCAPE)
		ft_exit(f, "Thank you for using my program\n");
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_move(0, 50, f);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_move(0, -50, f);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_move(-50, 0, f);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_move(50, 0, f);
	else if (keycode == KEY_1 && f->fractal != MANDELBROT)
		change_fractal(MANDELBROT, f);
	else if (keycode == KEY_2 && f->fractal != JULIA)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		change_fractal(JULIA, f);
	}
	else if (keycode == KEY_3 && f->fractal != BURNINGSHIP)
		change_fractal(BURNINGSHIP, f);
	else if (keycode == KEY_SPACE)
		color_shift(f);
	render(f);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == KEY_WHEEL_DOWN || keycode == KEY_WHEEL_UP)
	{
		if (keycode == KEY_WHEEL_DOWN)
			ft_zoom(1.50, x, y, f);
		else
			ft_zoom(0.5, x, y, f);
	}
	else if (keycode == KEY_RMB && f->fractal == MANDELBROT)
		julia_shift(x, y, f);
	render(f);
	return (0);
}
