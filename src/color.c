/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:29:09 by jhue              #+#    #+#             */
/*   Updated: 2024/01/29 16:28:24 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int color_start, int color_end, double percent)
{
	int	rgb_start[3];
	int	rgb_end[3];

	rgb_start[0] = (color_start >> 16) & 0xFF;
	rgb_start[1] = (color_start >> 8) & 0xFF;
	rgb_start[2] = (color_start) & 0xFF;
	rgb_end[0] = (color_end >> 16) & 0xFF;
	rgb_end[1] = (color_end >> 8) & 0xFF;
	rgb_end[2] = (color_end) & 0xFF;
	rgb_start[0] = (rgb_end[0] - rgb_start[0]) * percent + rgb_start[0];
	rgb_start[1] = (rgb_end[1] - rgb_start[1]) * percent + rgb_start[1];
	rgb_start[2] = (rgb_end[2] - rgb_start[2]) * percent + rgb_start[2];
	return (0xFF << 24 | rgb_start[0] << 16 | rgb_start[1] << 8 | rgb_start[2]);
}

static void	color_mono(t_fractol *f)
{
	int		i;
	int		j;
	int		color_start;
	int		color_end;
	double	percent;

	i = 0;
	color_start = 0x000000;
	color_end = f->color;
	while (i < MAX_ITERATION)
	{
		j = -1;
		while (++j < MAX_ITERATION / 2)
		{
			percent = (double)j / (MAX_ITERATION / 2);
			f->color_range[i + j] = get_color(color_start, color_end, percent);
		}
		i += j;
		color_start = f->color;
		color_end = 0xFFFFFF;
	}
	f->color_range[MAX_ITERATION] = 0;
}

static void	color_complementary(t_fractol *f, int color[4])
{
	int		i;
	int		j;
	int		k;
	double	percent;

	i = 0;
	k = 0;
	while (i < MAX_ITERATION)
	{
		j = -1;
		while (++j < MAX_ITERATION / 3)
		{
			percent = (double)j / (MAX_ITERATION / 3);
			f->color_range[i + j] = get_color(color[k], color[k + 1], percent);
		}
		k++;
		i += j;
	}
	f->color_range[MAX_ITERATION] = 0;
}

static int	find_compl(int color)
{
	int	compl_color[3];

	compl_color[0] = (color >> 16) & 0xFF;
	compl_color[1] = (color >> 8) & 0xFF;
	compl_color[2] = (color) & 0xFF;
	compl_color[0] = 0xFF - compl_color[0];
	compl_color[1] = 0xFF - compl_color[1];
	compl_color[2] = 0xFF - compl_color[2];
	return (compl_color[0] << 16 | compl_color[1] << 8 | compl_color[2]);
}

void	color_shift(t_fractol *f)
{
	f->color_pattern = (f->color_pattern + 1) % 4;
	reset_img(f);
	if (f->color == 0x000000 || f->color == 0xFFFFFF)
		f->color = 0x00BFFF;
	if (f->color_pattern == 0)
		color_mono(f);
	else if (f->color_pattern == 1)
		color_complementary(f, (int [4]){0x000000, f->color,
			find_compl(f->color), 0xFFFFFF});
	else if (f->color_pattern == 2)
		color_triad(f);
	else
		color_tetra(f);
}
