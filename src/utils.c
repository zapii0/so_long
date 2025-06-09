/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:56:00 by mzapora           #+#    #+#             */
/*   Updated: 2025/06/09 16:17:25 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	win_dest(t_stack *m)
{
	if (!m)
		return ;
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

int	handler(int keycode, t_stack *m)
{
	if (keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 100)
		handle_move(keycode, m);
	else if (keycode == 65307)
	{
		win_dest(m);
		cleanall(m);
		exit(0);
	}
	else
		return (0);
	image_putter(m);
	return (0);
}

void	map_render(t_stack *m)
{
	win_creator(m);
	if (m->flag == false)
		return ;
	add_image(m);
	if (m->flag == false)
		return ;
	mlx_hook(m->win, 2, 1L << 0, handler, m);
	image_putter(m);
	mlx_loop(m->mlx);
}
