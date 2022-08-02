/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/08/02 15:53:21 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_julia(int x, int y, t_data *data)
{
	if (data->flag == 1)
		return (0);
	printf("flag = %i\n",data->flag);
	data->x = data->min_re + x *
		(data->max_re - data->min_re) / (data->win_width);
	data->y = data->min_im + y *
		(data->max_im - data->min_im) / (data->win_height);
	return (0);
}

int	trigger_motion(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	if (data->flag == 0)
	{
		printf("What about here?\n");
		mlx_hook(data->win_ptr, 6, 0, &move_julia, data);
		data->flag = 1;
	}
	else
	{
		printf("here?\n");
		data->flag = 0;
	}
	return (0);
}

int	render_julia(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	julia(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	julia(t_img *img, t_data *data)
{
	t_fract	jul;
	t_index	in;
	double	tmp;

	jul.re_factor = (data->max_re - data->min_re) / (data->win_width);
	jul.im_factor = (data->max_im - data->min_im) / (data->win_height);
	in.y = -1;
	while (++in.y < data->win_height)
	{
		in.x = -1;
		while (++in.x < data->win_width)
		{
			jul.z_re = data->min_re + (in.x * jul.re_factor);
			jul.z_im = data->min_im + (in.y * jul.im_factor);
			in.i = -1;
			while (++in.i < ITER && (jul.z_re * jul.z_re
					+ jul.z_im * jul.z_im < 4))
			{
				tmp = jul.z_re * jul.z_re - jul.z_im * jul.z_im;
				jul.z_im = (2 * jul.z_im * jul.z_re) + data->y;
				jul.z_re = tmp + data->x;
			}
			color(img, in);
		}
	}
	return (0);
}
