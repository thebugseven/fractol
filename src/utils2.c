/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:13:40 by jhue              #+#    #+#             */
/*   Updated: 2024/02/01 11:49:11 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	if (str[0] != '0' || str[1] != 'x')
		return (-1);
	i = 2;
	while (str[i] && ft_ishexa(str[i]))
	{
		if (ft_isdigit(str[i]))
			nb = nb * 16 + (str[i] - '0');
		else
			nb = nb * 16 + (str[i] - 'A' + 10);
		i++;
	}
	if (str[i] || i != 8)
		return (-1);
	return (nb);
}

void	get_args(t_fractol *f, char **av)
{
	f->color = ft_atoi(av[1]);
	if (f->color == -1)
		ft_exit(f, "Wrong input for the color, should be : 0x000000\n");
	
}

int	close_fractal(t_fractol *f)
{
	ft_exit(f, "Thank you for using my program\n");
	return (0);
}
