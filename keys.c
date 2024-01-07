/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:55 by soksak            #+#    #+#             */
/*   Updated: 2024/01/04 16:28:23 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
