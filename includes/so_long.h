#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

typedef struct map 
{
	int		high;
	int		width;
	bool	flag;
	char	*map;
	char	**map2;
	char	**copy;
	int		pcounter;
	int		ecounter;
	int		ccounter;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*plr;
	void	*exit;
	void	*cltb;
}   t_stack;
void	map_checker(char *map_path, t_stack *map);
void	middle_checker(t_stack *map, int i);
void	structsetter(t_stack *map);
void	map_elements(char *m, t_stack *map);
void	map_connect(int fd, t_stack *map);
void	counter_checker(t_stack *map);
void	map_dimensions(int fd, t_stack *map);
int		path_error(char *map_path);
int		cleanall(t_stack *map);
void	start_flood_fill(t_stack *map);
void	map_render(t_stack *m);
void	add_image(t_stack *m);
void	win_creator(t_stack *m);
void	find_plr(t_stack *map, int *x, int *y);
#endif
