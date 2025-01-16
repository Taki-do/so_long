/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:49 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/16 12:25:41 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char *av[])
{
	int		i;
	int		fd;
	char	**map;

	if (ac == 2)
	{
		i = 0;
		map = read_map(av[1]);
		mlx_start(map);
		//while (map[i])
		//	ft_printf("%s", map[i++]);
	}
}
