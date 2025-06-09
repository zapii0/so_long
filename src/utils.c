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
	if (!m)
		return;

	if (m->win)
		mlx_destroy_window(m->mlx, m->win);

	if (m->floor)
		mlx_destroy_image(m->mlx, m->floor);
	if (m->wall)
		mlx_destroy_image(m->mlx, m->wall);
	if (m->cltb)
		mlx_destroy_image(m->mlx, m->cltb);
	if (m->exit)
		mlx_destroy_image(m->mlx, m->exit);
	if (m->plr)
		mlx_destroy_image(m->mlx, m->plr);

	if (m->mlx)
	{
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		m->mlx = NULL;
	}
}
