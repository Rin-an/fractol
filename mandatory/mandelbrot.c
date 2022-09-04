/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/09/02 16:01:12 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_mandelbrot(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	data->re_factor = (data->max_re - data->min_re) / (data->win_width);
	data->im_factor = (data->max_im - data->min_im) / (data->win_height);
	mandelbrot(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	return (0);
}

int	mandelbrot(t_img *img, t_data *data)
{
	t_fract	man;
	t_index	in;

	in.y = -1;
	while (++in.y < data->win_height)
	{
		man.c_im = data->max_im - in.y * data->im_factor;
		in.x = -1;
		while (++in.x < data->win_width)
		{
			man.c_re = data->min_re + (in.x * data->re_factor);
			man.z_re = man.c_re;
			man.z_im = man.c_im;
			in.i = -1;
			color(data, img, in, &man);
		}
	}
	return (0);
}
