/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:24:38 by ssadiki           #+#    #+#             */
/*   Updated: 2022/10/31 21:49:29 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_color(t_data *data)
{
	static int	c;

	if (c == 4)
		c = 0;
	if (c == 0)
		data->iro = 0x110000;
	else if (c == 1)
		data->iro = 0x001100;
	else if (c == 2)
		data->iro = 0x000011;
	else if (c == 3)
		data->iro = 0xF0F8FF;
		c++;
}

void	iter_change(int button, t_data *data)
{
	if (button == 4)
	{
		if (data->iter > 30)
			data->iter -= 5;
	}
	else if (button == 5)
		data->iter += 5;
}

void	left_click(t_data *data)
{
	if (data->flag == 0)
	{
		data->flag = 1;
		trigger_motion(data);
	}
	else
		data->flag = 0;
}

void	reinit_param(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0;
	data->max_im = 2.0;
	data->iro = 0xF0F8FF;
}
