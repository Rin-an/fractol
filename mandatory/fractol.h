/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:45:22 by ssadiki           #+#    #+#             */
/*   Updated: 2022/10/31 17:02:46 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define ITER 50

//STRCUTURES
typedef struct s_img{
	void	*mlx_img;
	char	*addr;
	int		line_len;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_data{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			flag;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_factor;
	double		im_factor;
	double		x;
	double		y;
	int			iter;
	t_img		img;
}	t_data;

typedef struct s_fract{
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	re_factor;
	double	im_factor;
}	t_fract;

typedef struct s_index{
	int	i;
	int	x;
	int	y;
}	t_index;
//FRACTALS
int		mandelbrot(t_img *img, t_data *data);
int		render_mandelbrot(t_data *data);
int		julia(t_img *img, t_data *data);
int		render_julia(t_data *data);
//VISUALS
void	img_pix_put(t_img *img, int x, int y, int color);
//HOOKS
int		trigger_motion(t_data *data);
void	left_click(t_data *data);
int		move_julia(int x, int y, t_data *data);
void	exec_hooks(t_data *data);
//UTILS
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	init_data(t_data *data);
#endif
