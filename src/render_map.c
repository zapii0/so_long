/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:55:48 by mzapora           #+#    #+#             */
/*   Updated: 2025/06/09 16:19:53 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	cltbcounter(t_stack *m)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (m->map2[i])
	{
		j = 0;
		while (m->map2[i][j])
		{
			if (m->map2[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	move_player(t_stack *m, int new_x, int new_y)
{
	int		x;
	int		y;
	char	next_tile;

	if (new_y < 0 || new_x < 0 || !m->map2[new_y] || \
		new_x >= (int)ft_strlen(m->map2[new_y]))
		return ;
	find_plr(m, &x, &y);
	next_tile = m->map2[new_y][new_x];
	if ((next_tile == 'E' && m->ccounter > 0) || next_tile == '1')
		return ;
	if (next_tile == 'C')
		m->ccounter--;
	if (next_tile == 'E' && m->ccounter == 0)
	{
		ft_printf("You win!\n");
		win_dest(m);
		cleanall(m);
		exit(0);
	}
	m->map2[y][x] = '0';
	m->map2[new_y][new_x] = 'P';
	m->moves++;
	ft_printf("Moves: %d\n", m->moves);
}

void	handle_move(int keycode, t_stack *m)
{
	int	x;
	int	y;

	find_plr(m, &x, &y);
	if (keycode == 119)
		move_player(m, x, y - 1);
	else if (keycode == 97)
		move_player(m, x - 1, y);
	else if (keycode == 115)
		move_player(m, x, y + 1);
	else if (keycode == 100)
		move_player(m, x + 1, y);
	return ;
}
