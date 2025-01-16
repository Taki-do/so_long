#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	take_input(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("The %d key (ESC) has been pressed\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	if (keycode = 97)
	{
		printf("The key A has been pressed\n");
	}
	printf("The %d key has been pressed\n", keycode);
	return (0);
}

void	render_map(t_data *img, t_vars *vars)
{
	int	x;
	int	y;
	int	height;
	int	width;

	y = 0;
	while (img->map[y])
	{
		x = 0;
		while (img->map[y][x])
		{
			if (img->map[y][x] == '1')
			{
				width = x * 64;
				height = y * 64;
				mlx_xpm_file_to_image(vars->mlx, "azfal.xpm", &width, &height);
			}
			x++;
		}
		y++;
	}
}

int	mlx_start(char **map)
{
	t_vars 	vars;
	t_data	img;

	//launch X server
	vars.mlx = mlx_init();
	//create a window and name it
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Nice Window here!");
	//instantiate image on the window
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	//get all the info about img created on the windows;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	img.map = map;
	//adjust where to put pixels
	my_mlx_pixel_put(&img, 50, 50, 0x0000FF00);
	//put pixels
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//take keys
	mlx_key_hook(vars.win, take_input, &vars);
	//run till the end
	render_map(&img, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	free(vars.win);
}
