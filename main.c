/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:26 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/22 17:17:03 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_iso(size_t x, size_t y, t_env *e)
{
	e->x = y * 20 + x * 20 + (WIN_X / 5 * 2);
	e->y = x * 20 + x * 20 + (WIN_Y / 5 * 2);

	if (x == 0)
	{
		e->y_prev = e->y;
		e->x_prev = e->x;
	}
	ft_draw(e->x, e->y, e);
	if (y > 0)
	{
		e->x_prev = (y - 1) * 20 + x * 20 + (WIN_X / 5 * 2);
		e->y_prev = (y - 1) * 20 - x * 20 - e->tab[y - 1][x]
			+ (WIN_Y / 5 * 2);
		ft_draw(e->x, e->y, e);
	}
	e->y_prev = e->y;
	e->x_prev = e->x;
}

void		ft_print(t_env *e)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < e->cnt_line)
	{
		x = 0;
		while (x < e->cnt_col)
		{
			ft_iso(x, y, e);
			++x;
		}
		++y;
	}
}

int		ft_keyfunct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		ft_error("wrong number of arguments");
	ft_parse(&e, argv[1]);
	e.color = 0x0099FF;
	e.y = WIN_Y / 4;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
	ft_print(&e);
	mlx_key_hook(e.win, ft_keyfunct, &e);
	mlx_loop(e.mlx);
	return (0);
}
