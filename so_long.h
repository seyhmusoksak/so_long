/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:00:14 by soksak            #+#    #+#             */
/*   Updated: 2024/01/07 05:44:16 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_xpm
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
}	t_xpm;

typedef struct s_state
{
	t_xpm		*img_paths;
	char		**map;
	int			x;
	int			y;
	int			collectiables;
	int			player[2];
	void		*mlx;
	void		*win;
}	t_state;

// Hook Func.
int		deal_key(int key_code, t_state *screen);

// Map Func.
void	map_cord(char *map, t_state *data);
void	put_image(t_state *data, char **map, int i, int j);
void	assign_image(t_state *data);
void	read_map(t_state *data, char *map);
void	put_map(t_state *data);

#endif
