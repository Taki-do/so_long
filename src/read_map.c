/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:25:10 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/16 12:08:11 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		map_size(char *name)
{
	int	fd;
	int	size;

	size = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd))
		size++;
	close(fd);
	return (size);
}

char	**read_map(char *name)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	char	**map;

	i = 0;
	size = map_size(name);
	fd = open(name, O_RDONLY);
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
