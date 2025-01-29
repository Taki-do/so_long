/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:52 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 21:57:56 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_free(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->floor_img);
	mlx_destroy_image(data->mlx, data->player_img);
	mlx_destroy_image(data->mlx, data->collectible_img);
	mlx_destroy_display(data->mlx);
	if (data->map)
		free_map(data->map);
	free(data->mlx);
}

int	input_wall(t_data *data, int x, int y)
{
	if (data->map[y][x] != '1')
	{
		data->map[data->player_y][data->player_x] = data->previous_tile;
		data->previous_tile = data->map[y][x];
		if (data->previous_tile == 'C')
		{
			data->previous_tile = '0';
			data->collected++;
		}
		data->map[y][x] = 'P';
		data->player_x = x;
		data->player_y = y;
		if (data->previous_tile == 'E'
			&& data->collected == data->collectible)
			return (close_window(data));
		render_map(data);
	}
	return (0);
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
		mlx_free(data);
		exit(0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		data->count++;
		ft_printf("Moves done : %d\n", data->count);
	}
	return (input_wall(data, x, y));
}

int	close_window(t_data *data)
{
	mlx_free(data);
	exit(0);
	return (0);
}
