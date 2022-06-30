/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budhhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:37:18 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/29 16:36:43 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>
#define ITERATION 1000

int	budhhabrot(t_img *img, t_data *data)
{
	double	min_re, max_re;
	double	min_im, max_im;
	double	c_im, c_re;
	double	z_re, z_im, z_re2, z_im2;
	double	re_factor;
	double	im_factor;
	int		x, y, i;

	min_re = -2.0;
	max_re = 2.0;
	min_im = -2.0;
	max_im = 2.0;
	y = 0;
//	max_im = min_im + (max_re - min_re) * data->win_height/data->win_width;

	re_factor = (max_re - min_re) / (data->win_width);
	im_factor = (max_im - min_im) / (data->win_height);
	while (y < data->win_height)
	{
		c_im = max_im - y * im_factor;
		x = 0;
		while (x < data->win_width)
		{
			c_re = min_re + (x * re_factor);
			z_re = c_re;
			z_im = c_im;
			i = 0;
			while (i < ITERATION)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im * z_im > 4)
				{
					break;
				}
				z_im = (2 * z_im * z_re) + c_im;
				z_re = z_re2 - z_im2 + c_re;
				i++;
			}
			/*if (i == ITERATION)
			{
				img_pix_put(img, x, y, 0x000000);
			}*/
			if (i != ITERATION)
				img_pix_put(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}

/*int	mandelbrot(t_img *img)
{
	double MinRe = -2.0;
	double MaxRe = 2.0;
	double MinIm = -2.0;
	double	MaxIm = 2.0;
	//double MaxIm = MinIm+(MaxRe-MinRe)*data->win_height/data->win_width;
	double Re_factor = (MaxRe-MinRe)/(data->win_width);
	double Im_factor = (MaxIm-MinIm)/(data->win_height);
	int MaxIterations = 50;

	int y = 0;
	while(y < data->win_height)
	{
    	double c_im = MaxIm - y*Im_factor;
		int x = 0;
   		 while(x < data->win_width)
   		 {
    	    double c_re = MinRe + x*Re_factor;

    	    double Z_re = c_re, Z_im = c_im;
    	    bool isInside = true;
			int n = 0;
       		 while(n < MaxIterations)
       		 {
       		     double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
        	    if(Z_re2 + Z_im2 > 4)
        	    {
        	        isInside = false;
        	        break;
        	    }
           		 Z_im = 2*Z_re*Z_im + c_im;
           		 Z_re = Z_re2 - Z_im2 + c_re;
				 n++;
        	}
       		 if(isInside) { img_pix_put(img, x, y, 0x000000); }
			 x++;
    	}
		 y++;
	}
	return (0);
}*/
