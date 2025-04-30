#include "libft.h"
#include "so_long.h"

int	path_error(char *map_path)
{
	int	i;

	i = ft_strlen(map_path);
	if (i < 5)
		return (1);
	if (map_path[i - 1] != 'r' || map_path[i - 2] != 'e' \
	|| map_path[i - 3] != 'b'|| map_path[i - 4] != '.')
		return (1);
	return (0);
}

void	map_checker(char *map_path, t_stack *map)
{
	int	fd;
	
	if (path_error(map_path))
	{
		map->flag = false;
		return ;
	}
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		map->flag = false;
		return ;
	}
	
}
