/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:36:54 by ssadiki           #+#    #+#             */
/*   Updated: 2022/11/01 03:55:00 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	render_ship(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	data->re_factor = (data->max_re - data->min_re) / (data->win_width);
	data->im_factor = (data->max_im - data->min_im) / (data->win_height);
	burning_ship(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	return (0);
}

void	color_ship(t_data *data, t_img *img, t_index in, t_fract *sh)
{
	t_fract	tmp;

	sh->z_re = 0;
	sh->z_im = 0;
	while (++in.i < data->iter && (sh->z_re * sh->z_re
			+ sh->z_im * sh->z_im < 4))
	{
		tmp.z_re = fabs(sh->z_re * sh->z_re - sh->z_im * sh->z_im + sh->c_re);
		tmp.z_im = fabs((2 * sh->z_im * sh->z_re) + sh->c_im);
		sh->z_re = tmp.z_re;
		sh->z_im = tmp.z_im;
	}
	if (in.i == data->iter)
		img_pix_put(img, data->x, data->y, 0x000000);
	else
		img_pix_put(img, in.x, in.y, data->iro * in.i);
}

int	burning_ship(t_img *img, t_data *data)
{
	t_fract	sh;
	t_index	in;

	in.y = -1;
	while (++in.y < data->win_height)
	{
		sh.c_im = data->min_im + (in.y * data->im_factor);
		in.x = -1;
		while (++in.x < data->win_width)
		{
			in.i = -1;
			sh.c_re = data->min_re + (in.x * data->re_factor);
			color_ship(data, img, in, &sh);
		}
	}
	return (0);
}
