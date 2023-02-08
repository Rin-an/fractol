/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:52:13 by ssadiki           #+#    #+#             */
/*   Updated: 2022/10/31 22:28:43 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	menu(void)
{
	ft_putstr("*****SETTINGS******\n");
	ft_putstr("Change color -- c\n");
	ft_putstr("Change fractal -- f\n");
	ft_putstr("Reinitialize -- space\n");
	ft_putstr("Move fractal -- arrow keys\n");
	ft_putstr("Zoom in/out -- mouse wheel\n");
	ft_putstr("Increase/decrease precision -- +/-\n");
	ft_putstr("Please keep in mind the machine's graphical limit :)\n");
	ft_putstr("Exit -- esc\n");
}

void	instructions(void)
{
	ft_putstr("Here is a list of what is available:\n");
	ft_putstr("Please write one of the following:\n");
	ft_putstr(" Mandelbrot\n Julia\n Ship\n");
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
	choose_fractal(av[1], &data);
	exec_hooks(&data);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}
