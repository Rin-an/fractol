/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/07/31 19:07:57 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_julia(int x, int y, t_data *data)
{
	data->x = x;
	data->y = y;
	return (0);
}

int	trigger_motion(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data->win_ptr)
		return (1);
	if (button == 1)
		mlx_hook(data->win_ptr, 6, 0,&move_julia, data);
	else
		return (0);
	return (0);
}

int	render_julia(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	julia(&data->img, data);
	mlx_hook(data->win_ptr, 4, 0, &trigger_motion, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	julia(t_img *img, t_data *data)
{
	t_fract	jul;
	t_index	in;
	double	tmp;

	jul.re_factor = (data->max_re - data->min_re) / (data->win_width);
	jul.im_factor = (data->max_im - data->min_im) / (data->win_height);
	jul.c_re = data->min_re + data->x * jul.re_factor;
	jul.c_im = data->min_im + data->y * jul.im_factor;
	in.y = -1;
	while (++in.y < data->win_height)
	{
		in.x = -1;
		while (++in.x < data->win_width)
		{
			jul.z_re = data->min_re + (in.x * jul.re_factor);
			jul.z_im = data->min_im + (in.y * jul.im_factor);;
			in.i = -1;
			while (++in.i < ITER && (jul.z_re * jul.z_re 
					+ jul.z_im * jul.z_im < 4))
			{
				tmp = jul.z_re * jul.z_re - jul.z_im * jul.z_im;
				jul.z_im = (2 * jul.z_im * jul.z_re) + jul.c_im;
				jul.z_re = tmp + jul.c_re;
			}
			color(img, in);
		}
	}
	return (0);
}
