#include "libft.h"
#include "so_long.h"

void	map_elements(int fd, t_stack *map)
{
	
}

void	map_dimensions(int fd, t_stack *map)
{
	char	*line;
	int		width;
	char	*tmp;

	map->high = 0;
	map->width = 0;	
	while ((line = get_next_line(fd)))
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		width = ft_strlen(line);
		if (map->width == 0)
			map->width = width;
		if (map->width != width)
		{
			map->flag = false;
			free(line);
			return ;
		}
		map->high++;
		free(line);
	}
}

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
	
	map->flag = true;
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
	map_dimensions(fd, map);
	if (map->flag == false)
	{
		close(fd);
		return ;
	}
	map_elements(fd, map);
}
