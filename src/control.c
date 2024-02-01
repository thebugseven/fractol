/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:14:34 by jhue              #+#    #+#             */
/*   Updated: 2024/02/01 11:42:33 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control(void)
{
	ft_putstr_fd("=========================================\n", 1);
	ft_putstr_fd("|       Control       |\n", 1);
	ft_putstr_fd("View control : WASD or Arrow Keys\n", 1);
	ft_putstr_fd("Zoom : Mouse Wheel\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Mandelbrot : 1\n", 1);
	ft_putstr_fd("Julia : 2\n", 1);
	ft_putstr_fd("Burningship : 3\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Julia with this value of the mouse on Mandelbrot : RMB\n", 1);
	ft_putstr_fd("Color shift : Space Bar\n", 1);
	ft_putstr_fd("End simulation : Escape\n", 1);
	ft_putstr_fd("=========================================\n", 1);
}
