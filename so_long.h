/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:00:14 by soksak            #+#    #+#             */
/*   Updated: 2024/01/14 04:33:11 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_xpm
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	char	*map;
}	t_xpm;

typedef struct s_state
{
	t_xpm		*img_paths;
	char		**map;
	int			x;
	int			y;
	int			collectiables;
	int			movement;
	int			exit[2];
	int			player[2];
	void		*mlx;
	void		*win;
}	t_state;

// Move Func.
int		deal_key(int key_code, t_state *screen);
void	move_up(t_state *data);
void	move_down(t_state *data);
void	move_left(t_state *data);
void	move_right(t_state *data);

// Map Func.
void	map_cord(char *map, t_state *data);
void	put_image(t_state *data, char **map, int i, int j);
void	assign_image(t_state *data);
void	read_map(t_state *data, char *map);
void	put_map(t_state *data);

//Map Check Func.
void	check_player(t_state *data, char **map);
void	check_map_chars(char **str);
void	check_exit(t_state *data, char **map);
void	col_check(t_state *data, char **map);
void	is_closed_map(char **map);
void	mapcheck(t_state *data);
void	access_check(char **map);
void	arg_check(char *arg);
void	valid_map(char **map, int x, int y);
void	mapcheck(t_state *data);

//Utils

void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_map(char **map, char *msg);
int		strlen_y(char **str);
void	ft_error(char *msg);

#endif
