#include "libft.h"
#include "so_long.h"

void	add_image(t_stack *m)
{
	int	w;
	int	h;
	m->wall = mlx_xpm_file_to_image(m->mlx, "assets/wall.xpm", &w, &h);
	m->floor = mlx_xpm_file_to_image(m->mlx, "assets/floor.xpm", &w, &h);
	m->plr = mlx_xpm_file_to_image(m->mlx, "assets/player.xpm", &w, &h);
	m->cltb = mlx_xpm_file_to_image(m->mlx, "assets/collectible.xpm", &w, &h);
	m->exit = mlx_xpm_file_to_image(m->mlx, "assets/exit.xpm", &w, &h);
	if (!m->wall || !m->floor || !m->exit || !m->cltb || !m->plr)
	{
		m->flag = false;
		return ;
	}
}

void	win_creator(t_stack *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
	{
		m->flag = false;
		return ;
	}
	m->win = mlx_new_window(m->mlx, m->width * 64, m->high * 64, "so_long");
	if (!m->win)
	{
		m->flag = false;
		return ;
	}
}

void	map_render(t_stack *m)
{
	win_creator(m);
	if (m->flag == false)
		return ;
	add_image(m);
	if (m->flag == false)
		return ;
	
	mlx_loop(m->mlx);
}
