/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:31:16 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 21:57:55 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_first_line_border(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i + 1] == '\0')
		{
			if (map[0][i] != '\n')
				return (0);
		}
		else if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	borders_only_walls(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j + 1])
	{
		if (map[j][0] != '1')
			return (0);
		i = 0;
		while (map[j][i + 2])
			i++;
		if ((map[j][i] != '1') || (map[j][i + 1] != '\n'))
			return (0);
		j++;
	}
	i = 0;
	while (map[j][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_borders(char **map)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i + 1] == NULL)
			size--;
		if ((int)ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	if (!check_first_line_border(map) || !borders_only_walls(map))
		return (0);
	return (1);
}

int	map_size(char *name)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(name, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**read_map(char *name, t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	data->size = map_size(name);
	fd = open(name, O_RDWR);
	if (fd == -1 || !data->size)
		return (NULL);
	map = (char **)malloc((data->size + 1) * sizeof(char *));
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
	if (!validate_borders(map) || !validate_elements(map, data)
		|| (data->size == ((int)ft_strlen(map[0]) - 1)))
		return (free_map(map), NULL);
	return (map);
}
