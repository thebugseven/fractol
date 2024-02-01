/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:25:54 by jhue              #+#    #+#             */
/*   Updated: 2024/02/01 11:48:26 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "keycode.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define MAX_ITERATION 30
# define WIDTH 1500
# define HEIGHT 1200

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	int		fractal;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	int		color_range[MAX_ITERATION + 1];
	int		color_pattern;
	int		color;
	char	*buf;
}	t_fractol;

void	set_init(t_fractol *f);
void	init(t_fractol *f);

void	reset_img(t_fractol *f);
void	change_other(t_fractol *f);
void	render(t_fractol *f);

int		ft_mandelbrot(double cr, double ci);
int		ft_julia(double zr, double zi, t_fractol *f);
void	julia_shift(double x, double y, t_fractol *f);
int		ft_burningship(double cr, double ci);
void	change_fractal(int fract, t_fractol *f);

void	color_shift(t_fractol *f);
void	color_triad(t_fractol *f);
void	color_tetra(t_fractol *f);

void	ft_exit(t_fractol *f, char *str);
int		ft_ishexa(char c);
int		ft_isdigit(char c);
void	control(void);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
void	get_args(t_fractol *f, char **av);

int		mouse_event(int keycode, int x, int y, t_fractol *f);
int		key_event(int keycode, t_fractol *f);

int		close_fractal(t_fractol *f);

#endif