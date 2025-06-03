#include "libft.h"
#include "so_long.h"

void	structsetter(t_stack *map)
{
	map->ccounter = 0;
	map->moves = 0;
	map->ecounter = 0;
	map->flag = true;
	map->pcounter = 0;
	map->high = 0;
	map->width = 0;
	map->map = ft_strdup("");
	if (map->map == NULL)
	{
		map->flag = false;
		return ;
	}
}
void	middle_checker(t_stack *map, int i)
{
	int	j;

	j = 0;
	if (map->map2[i][0] != '1' || map->map2[i][map->width - 1] != '1')
	{
		map->flag = false;
		return ;
	}
	while (map->map2[i][j])
	{
		if (map->map2[i][j] == 'P')
			map->pcounter++;
		else if (map->map2[i][j] == 'E')
			map->ecounter++;
		else if (map->map2[i][j] == 'C')
			map->ccounter++;
		else if (map->map2[i][j] != '0' && map->map2[i][j] != '1')
		{
			map->flag = false;
			return ;
		}
		j++;
	}
}

void	counter_checker(t_stack *map)
{
	if (map->ccounter < 1)
		map->flag = false;
	if (map->ecounter != 1)
		map->flag = false;
	if (map->pcounter != 1)
		map->flag = false;
}

int	cleanall(t_stack *map)
{
	int	i;

	if (map->map)
		free(map->map);
	i = 0;
	if (map->map2)
	{
		while (i < map->high && map->map2[i])
		{
			free(map->map2[i]);
			i++;
		}
		free(map->map2);
	}
	i = 0;
	free(map);
	return (1);
}
