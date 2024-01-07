/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:42:47 by soksak            #+#    #+#             */
/*   Updated: 2024/01/07 05:42:50 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	deal_key(int key_code, t_state *screen)
{
	if (key_code == 53)
	{
		mlx_destroy_window(screen->mlx, screen->win);
		free(screen->img_paths);
		free(screen);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_state));
		map_cord(argv[1], data);
		data->map = (char **)malloc(sizeof(char *) * (data->y + 1));
		read_map(data, argv[1]);
		assign_image(data);
		put_map(data);
		mlx_key_hook(data->win, deal_key, data);
		mlx_loop(data->mlx);
	}
	else
		write(1, "Usage : ./so_long <map_location>", 32);
}
