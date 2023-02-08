/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:38:32 by ssadiki           #+#    #+#             */
/*   Updated: 2022/11/01 03:59:09 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	manage_mandelbrot(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render_mandelbrot, data);
}

void	manage_julia(t_data *data)
{
	data->x = -0.8;
	data->y = 0.156;
	data->flag = 0;
	mlx_loop_hook(data->mlx_ptr, &render_julia, data);
}

void	manage_burning_ship(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render_ship, data);
}

void	change_fractal(t_data *data)
{
	static int	c;

	if (c == 0)
		manage_mandelbrot(data);
	else if (c == 1)
		manage_julia(data);
	else if (c == 2)
	{
		manage_burning_ship(data);
		c = -1;
	}
	c++;
}

void	choose_fractal(char *av, t_data *data)
{
	if (ft_strcmp(av, "Mandelbrot"))
		manage_mandelbrot(data);
	else if (ft_strcmp(av, "Julia"))
		manage_julia(data);
	else if (ft_strcmp(av, "Ship"))
		manage_burning_ship(data);
	else
		instructions();
	menu();
}
