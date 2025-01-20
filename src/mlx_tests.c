/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:52 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/20 20:22:58 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	take_input(int keycode, t_data *data)
{
	int			x;
	int			y;

	x = data->player_x;
	y = data->player_y;
	if (keycode == 119)
		y--;
	else if (keycode == 97)
		x--;
	else if (keycode == 115)
		y++;
	else if (keycode == 100)
		x++;
	else if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		data->count++;
		ft_printf("Moves done : %d\n", data->count);
	}
	if (data->map[y][x] != '1')
	{
		data->map[y][x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_x = x;
		data->player_y = y;
		render_map(data);
	}
	return (0);
}
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
