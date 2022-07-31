/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/07/31 17:35:55 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_mandelbrot(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	mandelbrot(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	mandelbrot(t_img *img, t_data *data)
{
	t_fract	man;
	t_index	in;
	double	tmp;

	in.y = -1;
	man.re_factor = (data->max_re - data->min_re) / (data->win_width);
	man.im_factor = (data->max_im - data->min_im) / (data->win_height);
	while (++in.y < data->win_height)
	{
		man.c_im = data->max_im - in.y * man.im_factor;
		in.x = -1;
		while (++in.x < data->win_width)
		{
			man.c_re = data->min_re + (in.x * man.re_factor);
			man.z_re = man.c_re;
			man.z_im = man.c_im;
			in.i = -1;
			while (++in.i < ITER && (man.z_re * man.z_re 
					+ man.z_im * man.z_im < 4))
			{
				tmp = man.z_re * man.z_re - man.z_im * man.z_im;
				man.z_im = (2 * man.z_im * man.z_re) + man.c_im;
				man.z_re = tmp + man.c_re;
			}
			color(img, in);
		}
	}
	return (0);
}
