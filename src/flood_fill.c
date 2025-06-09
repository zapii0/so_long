/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:55:08 by mzapora           #+#    #+#             */
/*   Updated: 2025/06/09 15:42:46 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	check_res_fl(t_stack *map, int i, int j)
{
	int	exit_reachable;

	exit_reachable = 0;
	while (i < map->high)
	{
		j = 0;
		while (map->copy[i][j])
		{
			if (map->copy[i][j] == 'C')
				return (1);
			if (map->copy[i][j] == 'E')
			{
				if ((j + 1 < map->width && map->copy[i][j + 1] == 'V') || \
					(j - 1 >= 0 && map->copy[i][j - 1] == 'V') || \
					(i + 1 < map->high && map->copy[i + 1][j] == 'V') || \
					(i - 1 >= 0 && map->copy[i - 1][j] == 'V'))
					exit_reachable = 1;
			}
			j++;
		}
		i++;
	}
	if (exit_reachable)
		return (0);
	return (1);
}

void	find_plr(t_stack *m, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (m->map2[i])
	{
		j = 0;
		while (m->map2[i][j])
		{
			if (m->map2[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

char	**copy_map(t_stack *map)
{
	char	**mapcpy;
	int		i;

	i = 0;
	mapcpy = calloc(map->high + 1, sizeof(char *));
	if (!mapcpy)
	{
		map->flag = false;
		return (NULL);
	}
	while (i < map->high)
	{
		mapcpy[i] = ft_strdup(map->map2[i]);
		if (!mapcpy[i])
		{
			map->flag = false;
			while (--i >= 0)
				free(mapcpy[i]);
			free(mapcpy);
			return (NULL);
		}
		i++;
	}
	mapcpy[i] = NULL;
	return (mapcpy);
}

void	flood_fill(t_stack *map, int x, int y)
{
	if (map->copy[y][x] == '1' || map->copy[y][x] == 'V' || \
		map->copy[y][x] == 'E')
		return ;
	map->copy[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	start_flood_fill(t_stack *map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	map->copy = copy_map(map);
	if (!map->copy)
	{
		map->flag = false;
		return ;
	}
	find_plr(map, &x, &y);
	flood_fill(map, x, y);
	if (check_res_fl(map, 0, 0))
		map->flag = false;
	while (i < map->high)
		free(map->copy[i++]);
	free(map->copy);
	map->copy = NULL;
}
