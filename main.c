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
	map_checker(av[1], map);
}