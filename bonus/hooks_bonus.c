/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:48:57 by ssadiki           #+#    #+#             */
/*   Updated: 2022/08/29 16:13:39 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_keypress(int keycode, t_data *data)
{
	if (keycode == 124)
	{
		data->max_re += 0.1;
		data->min_re += 0.1;
	}
	if (keycode == 126)
	{
		data->max_im += 0.1;
		data->min_im += 0.1;
	}
	if (keycode == 123)
	{
		data->max_re -= 0.1;
		data->min_re -= 0.1;
	}
	if (keycode == 125)
	{
		data->max_im -= 0.1;
		data->min_im -= 0.1;
	}
}

int	exit_keypress(int keycode, t_data *data)
{
	if (!data->win_ptr)
		return (1);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
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
	(void)x;
	(void)y;
	if (!data->win_ptr)
		return (1);
	if (button == 4)
	{
		data->min_re *= 1.25;
		data->max_re *= 1.25;
		data->min_im *= 1.25;
		data->max_im *= 1.25;
	}
	else if (button == 5)
	{
		data->min_re /= 1.25;
		data->max_re /= 1.25;
		data->min_im /= 1.25;
		data->max_im /= 1.25;
	}
	else if (button == 1)
		trigger_motion(data);
	iter_change(button, data);
	return (0);
}

void	exec_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 0, &exit_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &exit_button, data);
	mlx_mouse_hook(data->win_ptr, &zoom, data);
	mlx_loop(data->mlx_ptr);
}
