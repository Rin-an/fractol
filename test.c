#include "fractol.h"

//Structures

/*typedef struct s_rect{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;*/

// Testing key events (and getting keycodes while at it)
int	handle_keypress(int keycode, t_data *data)
{
	//(void)keycode;
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(1);
	}
	printf("Keypress=%d\n",keycode);
	return (0);
}

//Rendering things
/*int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render_sqr(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}*/

/*int	render_bgrd(t_img *img)
{
	int	x;
	int	y = -1;

	while (++y <= 600)
	{
		x = -1;
		while (++x <= 600)
		{
			img_pix_put(img, x, y, 0xFFFFFF);
		}
	}
	return (0);
}*/

/*int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_bgrd(&data->img);
	render_rect(&data->img, (t_rect){0,0,100,100,0xFF0000});
	render_rect(&data->img, (t_rect){600 - 100, 300 - 100, 100, 100,0x00FF00});
	render_sqr(&data->img, (t_rect){600 / 2, 300 / 2, 50, 50, 0x0000FF});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}*/

int	encode_rgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (img->line_len * y + x * (img->bpp / 8));
	*(int*)pixel = color;
}

int	render_mandelbrot(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
//	render_bgrd(&data->img);
	mandelbrot(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/*int	render_budhhabrot(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	budhhabrot(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}*/

int	zoom(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data->win_ptr)
		return (1);
	double interp;

	if (button == 4)
	{
		/*data->min_re *= 1.25;
		data->max_re *= 1.25;
		data->min_im *= 1.25;
		data->max_im *= 1.25;*/
		interp = 1.0 / 1.03;
		data->min_re = x - ((x - data->min_re) * interp);
		data->max_re = x + ((data->max_re - x) * interp);
		data->min_im = y - ((y - data->min_im) * interp);
		data->max_im = y + ((data->max_im - y) * interp);
	}
	else if (button == 5)
	{
		/*data->min_re /= 1.25;
		data->max_re /= 1.25;
		data->min_im /= 1.25;
		data->max_im /= 1.25;*/
		interp = 1.0 * 1.03;
		data->min_re = x - ((x - data->min_re) * interp);
		data->max_re = x + ((data->max_re - x) * interp);
		data->min_im = y - ((y - data->min_im) * interp);
		data->max_im = y + ((data->max_im - y) * interp);
	}
	printf("min_re = %.2f, max_re = %.2f\n",data->min_re, data->max_re);
	printf("min_im = %.2f, max_im = %.2f\n",data->min_im, data->max_im);
	render_mandelbrot(data);
	return (0);
}

//Main function as u see lel
int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
	{
		ft_putstr("Please add an argument!\n");
		ft_putstr("Here is a list of what is available:\n");
		ft_putstr("Mandelbrot set\nJulia set\nBudhhabrot set\n");
		exit(EXIT_FAILURE);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_width = 600;
	data.win_height = 600;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width,data.win_height, "My window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	if (ft_strcmp(av[1], "Mandelbot"))
	{
		data.max_re = 2.0;
		data.min_re = -2.0;
		data.max_im = 2.0;
		data.min_im = -2.0;
		mlx_loop_hook(data.mlx_ptr, &render_mandelbrot, &data);
		mlx_mouse_hook(data.win_ptr, &zoom, &data);
	}
	mlx_hook(data.win_ptr, 2, 0, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, 3, 0 , &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}
