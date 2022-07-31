/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:54:38 by ssadiki           #+#    #+#             */
/*   Updated: 2022/07/31 17:00:10 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (img->line_len * y + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	color(t_img *img, t_index in)
{
	if (in.i == ITER)
		img_pix_put(img, in.x, in.y, 0x000000);
	else
		img_pix_put(img, in.x, in.y, 0xF0F8FF * in.i);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_width = 800;
	data->win_height = 800;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "Fractol");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0;
	data->max_im = 2.0;
}
