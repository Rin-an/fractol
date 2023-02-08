/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/11/01 03:51:35 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	move_julia(int x, int y, t_data *data)
{
	if ((x >= 0 && x <= data->win_width) && (y >= 0 && y <= data->win_width)
		&& data->flag == 1)
	{
		data->x = data->min_re + x
			* (data->max_re - data->min_re) / (data->win_width);
		data->y = data->min_im + y
			* (data->max_im - data->min_im) / (data->win_height);
	}
	return (0);
}

int	trigger_motion(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	mlx_hook(data->win_ptr, 6, 0, &move_julia, data);
	return (0);
}

int	render_julia(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	data->re_factor = (data->max_re - data->min_re) / (data->win_width);
	data->im_factor = (data->max_im - data->min_im) / (data->win_height);
	julia(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	return (0);
}

void	color_jul(t_data *data, t_img *img, t_index in, t_fract *fract)
{
	double	tmp;

	while (++in.i < data->iter && (fract->z_re * fract->z_re
			+ fract->z_im * fract->z_im < 4))
	{
		tmp = fract->z_re * fract->z_re - fract->z_im * fract->z_im;
		fract->z_im = (2 * fract->z_im * fract->z_re) + fract->c_im;
		fract->z_re = tmp + fract->c_re;
	}
	if (in.i == data->iter)
		img_pix_put(img, in.x, in.y, 0x000000);
	else
		img_pix_put(img, in.x, in.y, data->iro * in.i);
}

int	julia(t_img *img, t_data *data)
{
	t_fract	jul;
	t_index	in;

	in.y = -1;
	jul.c_re = data->x;
	jul.c_im = data->y;
	while (++in.y < data->win_height)
	{
		in.x = -1;
		while (++in.x < data->win_width)
		{
			jul.z_re = data->min_re + (in.x * data->re_factor);
			jul.z_im = data->min_im + (in.y * data->im_factor);
			in.i = -1;
			color_jul(data, img, in, &jul);
		}
	}
	return (0);
}
