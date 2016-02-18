/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:26 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/18 18:10:27 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_iso(size_t x, size_t y, t_env *e)
{
	int		prime_x;
	int		prime_y;

	e->x = y * 20 + x * 20 + (WIN_X / 5 * 2);
	e->y = x * 20 + x * 20 + (WIN_Y / 5 * 2);

	if (y == 0)
		prime_y = e->y;
	if (x == 0)
		prime_x = e->x;
	prime_x = e->y;
	prime_y = e->x;
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
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->color);
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
