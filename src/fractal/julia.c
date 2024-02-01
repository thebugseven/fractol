/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:53:53 by jhue              #+#    #+#             */
/*   Updated: 2024/01/29 16:28:16 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_shift(double x, double y, t_fractol *f)
{
	f->kr = f->min_r + (x * (f->max_r - f->min_r) / (double)WIDTH);
	f->ki = f->max_i - (y * (f->max_i - f->min_i) / (double)HEIGHT);
	change_fractal(JULIA, f);
}

int	ft_julia(double zr, double zi, t_fractol *f)
{
	int		n;
	double	tmp;

	n = -1;
	while (++n < MAX_ITERATION)
	{
		if ((zr * zr) + (zi * zi) > 4)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
	}
	return (n);
}
