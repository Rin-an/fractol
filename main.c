/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:52:13 by ssadiki           #+#    #+#             */
/*   Updated: 2022/07/31 18:30:56 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Testing key events (and getting keycodes while at it)
void	manage_mandelbrot(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render_mandelbrot, data);
}

void	manage_julia(t_data *data)
{
	data->x = 0;
	data->y = 0;
	mlx_loop_hook(data->mlx_ptr, &render_julia, data);
}

void	instructions(void)
{
	ft_putstr("Here is a list of what is available:\n");
	ft_putstr("Please write one of the following:\n");
	ft_putstr(" Mandelbrot\n Julia\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
	{
		ft_putstr("Please add an argument!\n");
		instructions();
	}
	else if (ac > 2)
	{
		ft_putstr("Too many arguments!\n");
		instructions();
	}
	init_data(&data);
	if (ft_strcmp(av[1], "Mandelbrot"))
		manage_mandelbrot(&data);
	else if (ft_strcmp(av[1], "Julia"))
		manage_julia(&data);
	else
		instructions();
	exec_hooks(&data);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}
