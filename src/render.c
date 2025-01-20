/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:32:55 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/20 18:20:37 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
					i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
					i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->player_img,
					i * TILE_SIZE, j * TILE_SIZE);
				data->player_x = i;
				data->player_y = j;
			}
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collectible_img,
					i * TILE_SIZE, j * TILE_SIZE);
			i++;
		}
		j++;
	}
}
