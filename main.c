#include "libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_stack	*map;

	if (ac != 2)
		return (write(2, "error\n", 7));
	map = ft_calloc(1, sizeof(t_stack));
	if (map == NULL)
		return(write(2, "error\n", 7));
	structsetter(map);
	map_checker(av[1], map);
	if (map->flag == false)
		return (cleanall(map));
	start_flood_fill(map);
	if (map->flag == false)
		return (cleanall(map));
	return (0);
}
