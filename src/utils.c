#include "so_long.h"
#include "libft.h"

void	game_win(t_stack *map)
{
	write (1, "You Win", 7);
	cleanall(map);
	return ;
}

void	put_tile(t_stack *m, void *img, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, img, x, y);
	return ;
}
