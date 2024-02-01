/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:14 by jhue              #+#    #+#             */
/*   Updated: 2024/01/29 16:28:20 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;
	int		n;

	n = -1;
	zr = 0;
	zi = 0;
	while (++n < MAX_ITERATION)
	{
		if ((zr * zr) + (zi * zi) > 4)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	return (n);
}
