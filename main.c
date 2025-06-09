#include "libft.h"
#include "so_long.h"

void image_putter(t_stack *map)
{
	int x;
	int y;

	y = 0;
	while (map->map2[y])
	{
		x = 0;
		while (map->map2[y][x])
		{
			if (map->map2[y][x] == 'C')
				put_tile(map, map->cltb, x * 64, y * 64);
			if (map->map2[y][x] == '1')
				put_tile(map, map->wall, x * 64, y * 64);
			if (map->map2[y][x] == '0')
				put_tile(map, map->floor, x * 64, y * 64);
			if (map->map2[y][x] == 'P')
				put_tile(map, map->plr, x * 64, y * 64);
			if (map->map2[y][x] == 'E')
				put_tile(map, map->exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int main(int ac, char **av)
{
	t_stack *map;

	if (ac != 2)
		return (write(2, "Error\n", 6));
	map = ft_calloc(1, sizeof(t_stack));
	if (map == NULL)
		return (write(2, "Error\n", 6));
	structsetter(map);
	map_checker(av[1], map);
	if (map->flag == false)
		return (write(2, "Error\n", 6), cleanall(map));
	start_flood_fill(map);
	if (map->flag == false)
		return (write(2, "Error\n", 6), cleanall(map));
	map_render(map);
	//win_dest(map);
	//cleanall(map);
	return (0);
}
