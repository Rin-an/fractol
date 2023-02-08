/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:48:57 by ssadiki           #+#    #+#             */
/*   Updated: 2022/10/31 22:20:25 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_keypress(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->max_re += 0.01;
		data->min_re += 0.01;
	}
	if (keycode == 126)
	{
		data->max_im += 0.01;
		data->min_im += 0.01;
	}
	if (keycode == 124)
	{
		data->max_re -= 0.01;
		data->min_re -= 0.01;
	}
	if (keycode == 125)
	{
		data->max_im -= 0.01;
		data->min_im -= 0.01;
	}
}

int	manage_keypress(int keycode, t_data *data)
{
	if (!data->win_ptr)
		return (1);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 8)
		change_color(data);
	if (keycode == 3)
		change_fractal(data);
	if (keycode == 49)
		reinit_param(data);
	if (keycode == 69)
		data->iter *= 2.0;
	if (keycode == 78)
		data->iter /= 2.0;
	move_keypress(keycode, data);
	return (0);
}

int	exit_button(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	zoom(int button, int x, int y, t_data *data)
{
	if (!data->win_ptr)
		return (1);
	data->x = data->min_re + x * \
		(data->max_re - data->min_re) / (data->win_width);
	data->y = data->min_im + y * \
		(data->max_im - data->min_im) / (data->win_height);
	if (button == 4)
	{
		data->min_re = data->x - (1.25 * (data->x - data->min_re));
		data->max_re = data->x + (1.25 * (data->max_re - data->x));
		data->min_im = data->y - (1.25 * (data->y - data->min_im));
		data->max_im = data->y + (1.25 * (data->max_im - data->y));
	}
	else if (button == 5)
	{
		data->min_re = data->x - ((1.0 / 1.25) * (data->x - data->min_re));
		data->max_re = data->x + ((1.0 / 1.25) * (data->max_re - data->x));
		data->min_im = data->y - ((1.0 / 1.25) * (data->y - data->min_im));
		data->max_im = data->y + ((1.0 / 1.25) * (data->max_im - data->y));
	}
	else if (button == 1)
		left_click(data);
	iter_change(button, data);
	return (0);
}

void	exec_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 0, &manage_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &exit_button, data);
	mlx_mouse_hook(data->win_ptr, &zoom, data);
	mlx_loop(data->mlx_ptr);
}
