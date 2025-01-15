#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_rectangle(t_data img)
{
    int i;

    i = 0;
    while (i++ < 100)
	    my_mlx_pixel_put(&img, i, 50, 0x00FF0000);
    i = 0;
    while (i++ < 100)
	    my_mlx_pixel_put(&img, 1, 50 + i, 0x00FF0000);
    i = 0;
    while (i++ < 100)
	    my_mlx_pixel_put(&img, i, 150, 0x00FF0000);
    i = 0;
    while (i++ < 100)
	    my_mlx_pixel_put(&img, 100, 50 + i, 0x00FF0000);
}

void    draw_triangle(t_data img)
{
    int i;

    i = 0;
    while (i++ < 100)
    {
	    my_mlx_pixel_put(&img, 100 + i, i, 0x00FF0000);
	    my_mlx_pixel_put(&img, i, 100 - i, 0x00FF0000);
    }
    i = 0;
    while (i++ < 200)
	    my_mlx_pixel_put(&img, i, 100, 0x00FF0000);
}

void    draw_circle(t_data img, int x_c, int y_c, int r)
{
    int x, y;

    for (x = x_c - r; x <= x_c + r; x++) {
        for (y = y_c - r; y <= y_c + r; y++) {
            if (sqrt((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c)) <= r) {
                my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            }
        }
    }
}

void    draw_tige(t_data img)
{
    int i;
    int j;

    j = 0;
    while (j++ < 10)
    {
        i = 0;
        while (i++ < 100)
        {
	        my_mlx_pixel_put(&img, 245 + j, 250 + i, 0x00FF0000);
        }
        j++;
    }
}

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	close(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
	    mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    if 
	return (0);
}

int handle_close(void *param)
{
    (void)param; // Si param n'est pas utilisé
    exit(0); // Quitte le programme
    return (0);
}



int	main(void)
{
    t_vars vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    draw_circle(img, 250, 150, 100);
    draw_tige(img);
    mlx_hook(vars.win, 17, 0, handle_close, NULL); //cross or ALT + F4
    mlx_hook(vars.win, 2, 1L<<0, close, &vars); //press ESC2
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

