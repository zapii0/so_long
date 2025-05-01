#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdbool.h>
#include <fcntl.h>

typedef struct map 
{
    int		high;
	int		width;
	bool	flag;
	char	*map;
}   t_stack;
void	map_checker(char *map_path, t_stack *map);
#endif
