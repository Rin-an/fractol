#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define ITER 1000

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
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		x;
	double		y;
	t_img	img;
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
	int i;
	int x;
	int y;
}	t_index;
//FRACTALS
int		mandelbrot(t_img *img, t_data *data);
int		render_mandelbrot(t_data *data);
int		julia(t_img *img, t_data *data);
int		render_julia(t_data *data);
//VISUALS
void	img_pix_put(t_img *img, int x, int y, int color);
void	color(t_img *img, t_index in);
//HOOKS
int	zoom(int button, int x, int y, t_data *data);
int	exit_keypress(int keycode, t_data *data);
int	exit_button(t_data *data);
void	exec_hooks(t_data *data);
//UTILS
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	init_data(t_data *data);
#endif
