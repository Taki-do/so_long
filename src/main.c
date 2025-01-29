/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:49 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 21:57:54 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
		free(map[y++]);
	free(map);
}

void	init_assets(t_data *data)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	data->count = 0;
	data->previous_tile = '0';
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"assets/exit.xpm", &width, &height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"assets/wall.xpm", &width, &height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"assets/floor.xpm", &width, &height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"assets/azfal.xpm", &width, &height);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx,
			"assets/collectible.xpm", &width, &height);
}

void	init_mlx(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 64 * data->width, 64 * data->size,
			"Azfal Adventures");
	data->img = mlx_new_image(data->mlx, 64 * data->width, 64 * data->size);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_lenght, &data->endian);
	data->collected = 0;
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_strstr(av[1], ".ber"))
			return (ft_putstr_fd("Error\n", 2), 1);
		data.map = read_map(av[1], &data);
		if (!data.map)
			return (ft_putstr_fd("Error\n", 2), 1);
		data.width = ft_strlen(data.map[0]) - 1;
		data.mlx = mlx_init();
		init_assets(&data);
		if (!findpath(&data))
			return (ft_putstr_fd("Error\n", 2), mlx_free(&data), 1);
		init_mlx(&data);
		render_map(&data);
		mlx_hook(data.win, 12, 1L << 15, render_map, &data);
		mlx_hook(data.win, 02, 1L << 0, take_input, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
		mlx_free(&data);
	}
	return (0);
}
