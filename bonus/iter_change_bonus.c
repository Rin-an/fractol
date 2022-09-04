/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_change_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:59:07 by ssadiki           #+#    #+#             */
/*   Updated: 2022/08/29 16:01:09 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
