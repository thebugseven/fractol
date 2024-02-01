/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:08 by jhue              #+#    #+#             */
/*   Updated: 2024/01/29 16:28:27 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color_percent(int color, double percent)
{
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
	rgb[0] += percent;
	rgb[1] += percent;
	rgb[2] += percent;
	return (0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	color_triad(t_fractol *f)
{
	int	triad[2];
	int	i;

	i = 0;
	triad[0] = get_color_percent(f->color, -0.66 * 256);
	triad[1] = get_color_percent(f->color, -0.33 * 256);
	while (i < MAX_ITERATION)
	{
		f->color_range[i] = f->color;
		f->color_range[i + 1] = triad[0];
		f->color_range[i + 2] = triad[1];
		i += 3;
	}
	f->color_range[MAX_ITERATION] = 0;
}

void	color_tetra(t_fractol *f)
{
	int	tetra[3];
	int	i;

	i = 0;
	tetra[0] = get_color_percent(f->color, -0.75 * 256);
	tetra[1] = get_color_percent(f->color, -0.5 * 256);
	tetra[2] = get_color_percent(f->color, -0.25 * 256);
	while (i < MAX_ITERATION)
	{
		f->color_range[i] = f->color;
		f->color_range[i + 1] = tetra[0];
		f->color_range[i + 2] = tetra[1];
		f->color_range[i + 3] = tetra[2];
		i += 4;
	}
	f->color_range[MAX_ITERATION] = 0;
}
