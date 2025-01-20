/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:49 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/20 19:09:26 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_assets(t_data *data)
{
	int		height;
	int		width;

	height = 64;
	width = 64;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &width, &height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm", &width, &height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "assets/azfal.xpm", &width, &height);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx, "assets/collectible.xpm", &width, &height);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 2)
	{
		data.map = read_map(av[1], &data);
		if (!data.map)
			ft_printf("Error\n");
		data.count = 0;
		data.mlx = mlx_init();
		ft_printf("data.size = %d\n\n", data.size);
		data.win = mlx_new_window(data.mlx, 64 * ft_strlen(data.map[0]),
			64 * data.size, "Nice Window here!");
		data.img = mlx_new_image(data.mlx, 64 * ft_strlen(data.map[0]), 64 * data.size);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_lenght, &data.endian);
		init_assets(&data);
		render_map(&data);
		mlx_hook(data.win, 02, 1L << 0, take_input, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
