/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhue < jhue@student.42lyon.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:08 by jhue              #+#    #+#             */
/*   Updated: 2024/01/31 10:59:06 by jhue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(t_fractol *f, char *str)
{
	if (f->img && f->mlx)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	free(f->mlx);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_ishexa(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
