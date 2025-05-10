#include "so_long.h"
#include "libft.h"

int	check_res_fl(t_stack *map, int	i, int j)
{
	write(1, "dasd", 4);
	while (map->copy[i])
	{
		j = 0;
		while (map->copy[i][j])
		{
			if (map->copy[i][j] == 'E')
			{
				if (j + 1 < map->width  && map->copy[i][j + 1] == 'V')
					return (0);
				else if (j - 1 >= 0 && map->copy[i][j - 1] == 'V')
					return (0);
				else if (i + 1 < map->high && map->copy[i + 1][j] == 'V')
					return (0);
				else if (i - 1 >= 0 && map->copy[i - 1][j] == 'V')
					return (0);
				else
					return (1); 
			}	
			if (map->copy[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (1);
}

void	find_plr(t_stack *map, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(map->copy[i])
	{
		j = 0;
		while (map->copy[i][j])
		{
			if (map->copy[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

char	**copy_map(t_stack *map)
{
	char	**mapcpy;
	int		i;

	i = 0;
	mapcpy = malloc (sizeof(char) * map->high);
	if (!mapcpy)
	{
		map->flag = false;
		return (NULL);
	}
	while (i < map->high)
	{
		mapcpy[i] = ft_strdup(map->map2[i]);
		if (mapcpy[i])
		{
			map->flag = false;
			return (NULL);
		}
		i++;
	}
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

	map->copy = copy_map(map);
	if (!map->copy)
	{
		map->flag = false;
		return ;
	}
	write(1, "lll", 3);
	find_plr(map, &x, &y);
	flood_fill(map, x, y);
	if (check_res_fl(map, 0, 0))
	{
		map->flag = false;
		return ;
	}
}