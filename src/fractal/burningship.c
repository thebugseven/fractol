/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:17:46 by jhue              #+#    #+#             */
/*   Updated: 2024/01/29 16:27:42 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burningship(double cr, double ci)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	i = -1;
	zi = 0;
	zr = 0;
	while (++i < MAX_ITERATION)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	return (i);
}
