#include "fractol.h"
#define PI 3.142857
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
	//render_bgrd(&data->img);
	mandelbrot(&data->img);
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

/*int	zoom(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		
	}
}*/

int	position_mouse(int button, int x, int y, t_data *data)
{
	(void)button;
	if (data->win_ptr != NULL)
	{
	//		mlx_mouse_get_pos(data->win_ptr, &x, &y);
		//printf("Mouse code = %i\n", button);
		printf("x=%i\n y=%i\n", x, y);
	}
	return (0);
}
int	render_red(t_img *img)
{
	int	x, y;

	y = -1;
	while (++y <= 600)
	{
		x = -1;
		while (++x <= 600)
			img_pix_put(img, x ,y, 0xE6261F);
	}
	return (0);
}

int render_green(t_img *img)
 {
     int x, y;

     y = -1;
     while (++y <= 600)
     {
         x = -1;
         while (++x <= 600)
             img_pix_put(img, x ,y, 0xA3E048);
     }
     return (0);
 }

int render_blue(t_img *img)
{
	 int x, y;

     y = -1;
     while (++y <= 600)
     {
		 x = -1;
		 while (++x <= 600)
			 img_pix_put(img, x ,y, 0x34BBE6);
	 }
	 return (0);
}

int	render_purple(t_img *img)
{
	int x, y;

	y = -1;
	while (++y <= 600)
	{
		x = -1;
		while (++x <= 600)
			img_pix_put(img, x ,y, 0xFF00FF);
	}
	return (0);
}

int render_orange(t_img *img)
{
    int x, y;

    y = -1;
    while (++y <= 600)
    {
        x = -1;
        while (++x <= 600)
            img_pix_put(img, x ,y, 0xeB7532);
    }
    return (0);
}

int render_indigo(t_img *img)
{
    int x, y;

    y = -1;
    while (++y <= 600)
    {
        x = -1;
        while (++x <= 600)
            img_pix_put(img, x ,y, 0x4355DB);
    }
    return (0);
}

int render_yellow(t_img *img)
{
    int x, y;

    y = -1;
    while (++y <= 600)
    {
        x = -1;
        while (++x <= 600)
            img_pix_put(img, x ,y, 0xF7D038);
    }
    return (0);
}

int	render_rainbow(t_data *data)
{
	static int i;
	if (data->win_ptr == NULL)
		return (1);
	if (i == 0)
	{
		i++;
		render_red(&data->img);
	}
	else if (i == 1)
	{
		i++;
		render_orange(&data->img);
	}
	else if (i == 2)
	{
		i++;
		render_yellow(&data->img);
	}
	else if (i == 3)
	{
		i++;
		render_green(&data->img);
	}
	else if (i == 4)
	{
		i++;
		render_blue(&data->img);
	}
	else if (i == 5)
	{
		i++;
		render_indigo(&data->img);
	}
	else
	{
		render_purple(&data->img);
		i = 0;
	}
	usleep(1000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
//Main function as u see lel

int	main(void)
{
	t_data	data;

//	(void)av;
/*	if (ac == 1)
	{
		ft_putstr("Please add an argument!\n");
		ft_putstr("Here is a list of what is available:\n");
		ft_putstr("Mandelbrot set\nJulia set\nBudhhabrot set\n");
		exit(EXIT_FAILURE);
	}*/
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT, "My window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render_rainbow, &data);
	mlx_hook(data.win_ptr, 2, 0, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, 3, 0 , &handle_keyrelease, &data);
	mlx_mouse_hook(data.win_ptr,&position_mouse, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}
