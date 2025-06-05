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
void win_dest(t_stack *m)
{
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_image(m->mlx, m->floor);
	mlx_destroy_image(m->mlx, m->wall);
	mlx_destroy_image(m->mlx, m->cltb);
	mlx_destroy_image(m->mlx, m->exit);
	mlx_destroy_image(m->mlx, m->plr);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
}