/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:41:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/21 20:07:21 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define TILE_SIZE 64

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data {
	void	*img;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	void    *mlx;
    void    *win;
	char	*addr;
    char    **map;
	int		player_x;
	int		player_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		size;
	int		width;
	int		count;
	int		collectible;
	int		collected;
	int		can_exit;
	char	previous_tile;
}	t_data;


int		map_size(char *name);
int		close_window(t_data *vars);
int		findpath(t_data *data);
int		take_input(int keycode, t_data *vars);
int		validate_elements(char **map, t_data *data);

char	**read_map(char *name, t_data *data);

void	free_map(char **map);
void	mlx_free(t_data *data);
void	render_map(t_data *data);

#endif