/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:21:44 by jhue              #+#    #+#             */
/*   Updated: 2024/02/01 11:47:03 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;
	int			i;

	i = 0;
	if (ac == 1)
		control_error();
	else
		get_args(&f, av);
	set_init(&f);
	init(&f);
	render(&f);
	control();
	mlx_hook(f.win, CLOSE_BUTTON, 0, close_fractal, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
