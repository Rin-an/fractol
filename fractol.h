#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


//STRCUTURES
typedef struct s_img{
	void	*mlx_img;
	char	*addr;
	int		line_len;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	t_img	img;
}	t_data;

//FRACTALS
int		mandelbrot(t_img *img, t_data *data);
int		budhhabrot(t_img *img, t_data *data);

//VISUALS
int		encode_rgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_mandelbrot(t_data *data);
//UTILS
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
#endif
