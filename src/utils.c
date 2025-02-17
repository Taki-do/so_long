/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:11 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 21:57:59 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_if_elements(int player, int collectible, int exit, t_data *data)
{
	if ((player != 1) || (collectible < 1) || (exit != 1))
		return (0);
	data->collectible = collectible;
	return (1);
}

int	validate_elements(char **map, t_data *data)
{
	int	i;
	int	j;
	int	player;
	int	collectible;
	int	exit;

	j = 0;
	player = 0;
	collectible = 0;
	exit = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'P')
				player++;
			else if (map[j][i] == 'C')
				collectible++;
			else if (map[j][i] == 'E')
				exit++;
		}
	}
	return (check_if_elements(player, collectible, exit, data));
}
