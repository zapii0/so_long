#include "libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_stack	*map;

	if (ac != 2)
		return (write(2, "wrong argument", 15));
	map = malloc(sizeof(t_stack));
	if (map == NULL)
		return(write(2, "malloc_error", 13));
	structsetter(map);
	map_checker(av[1], map);
	start_flood_fill(map);
	//ft_printf("pcounter%d\necounter%d\nccounter%d\nwidth%d\nhigh%d\n", map->pcounter, map->ecounter , map->ccounter , map->width, map->high);
	if (map->flag == false)
	{
		write(2, "error\n", 7);
		cleanall(map);
		return (1);
	}
}
