/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:40:42 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/21 20:00:54 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	findcollectibles(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->collectible = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				data->collectible++;
			x++;
		}
		y++;
	}
}

void	findplayer(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= ((int)ft_strlen(map[0]) - 1) || y >= data->size)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'S')
		return ;
	if (map[y][x] == 'C')
		data->collected++;
	if (map[y][x] == 'E')
		data->can_exit = 1;
	map[y][x] = 'S';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

int	findpath(t_data *data)
{
	int		y;
	char	**copy;

	y = 0;
	copy = (char **)malloc((data->size + 1) * sizeof(char *));
	if (!copy)
		return (0);
	while (data->map[y])
	{
		copy[y] = ft_strdup(data->map[y]);
		y++;
	}
	copy[y] = NULL;
	data->can_exit = 0;
	data->collected = 0;
	findcollectibles(copy, data);
	findplayer(copy, data);
	flood_fill(copy, data->player_x, data->player_y, data);
	free_map(copy);
	if ((data->collected == data->collectible) && data->can_exit)
		return (1);
	return (0);
}
