/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:07:37 by soksak            #+#    #+#             */
/*   Updated: 2024/01/14 04:22:43 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(char **map, int x, int y)
{
	if (y < 1 || x >= (strlen_y(map) - 1) || x < 1
		|| y >= (int)ft_strlen(map[0]) || map[x][y] == '1' ||
		map[x][y] == 'T')
		return ;
	map[x][y] = 'T';
	valid_map(map, x - 1, y);
	valid_map(map, x + 1, y);
	valid_map(map, x, y - 1);
	valid_map(map, x, y + 1);
}

static void	extension_check(char *arg)
{
	int	len;

	len = ft_strlen(arg) - 4;
	if (ft_strncmp(&arg[len], ".ber", 4) != 0)
	{
		ft_error ("The file extension is not correct!");
	}
	if (open(arg, O_RDONLY) == -1)
		ft_error("The file could not be opened!");
}

void	arg_check(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '.' && arg[1] != '/')
		ft_error("Secret file detected!");
	while (arg[++i])
	{
		if (arg[i] == '/')
		{
			if (!arg[i + 1])
				ft_error("File not found!");
			if (arg[i + 1] == '.')
				ft_error ("Secret file detected!");
		}
	}
	extension_check(arg);
}

void	access_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				free_map(map, "Player cannot access the necessary points!");
			j++;
		}
		j = 0;
		i++;
	}
}

void	mapcheck(t_state *data)
{
	char	**checkmap;
	int		i;

	i = -1;
	checkmap = malloc (sizeof(char *) * (data->y + 1));
	if (!checkmap)
		exit (0);
	while (data->map[++i])
		checkmap[i] = ft_strdup(data->map[i]);
	checkmap[i] = 0;
	check_map_chars(checkmap);
	check_player (data, checkmap);
	check_exit (data, checkmap);
	col_check(data, checkmap);
	is_closed_map (checkmap);
	valid_map (checkmap, data->player[0], data->player[1]);
	access_check (checkmap);
	i = 0;
	while (checkmap[i])
		free (checkmap[i++]);
	free (checkmap);
}
