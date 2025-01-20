/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:41:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/20 19:07:31 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		count;
}	t_data;


int		map_size(char *name);
int		close_window(t_data *vars);
int		validate_elements(char **map);
int		take_input(int keycode, t_data *vars);

char	**read_map(char *name, t_data *data);

void	render_map(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif