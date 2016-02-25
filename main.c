/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:26 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/25 17:00:45 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_drawsettings(t_env *e)
{
	e->color = 0x3366ff;
	e->lr = 0;
	e->ud = 0;
	e->contrast = 0;
	e->height = 1;
	e->zoom = 1;
}

void		ft_iso(size_t x, size_t y, t_env *e)
{
	e->x = (WIN_X / 5 * 2) + y * e->zoom + x * e->zoom + e->lr;
	e->y = (WIN_Y / 5 * 2) + y * e->zoom - x * e->zoom - e->tab[y][x]
		* e->height + e->ud;
	 e->color = e->tab[y][x] * (0x3366ff / e->height_max) + e->contrast;
	if (x == 0)
	{
		e->y_prev = e->y;
		e->x_prev = e->x;
	}
	ft_draw(e->x, e->y, e);
	if (y > 0)
	{
		e->x_prev = (WIN_X / 5 * 2) + (y - 1) * e->zoom + x * e->zoom + e->lr;
		e->y_prev = (WIN_Y / 5 * 2) + (y - 1) * e->zoom - x * e->zoom
			- e->tab[y - 1][x] * e->height + e->ud;
		e->color = e->tab[y][x] * 0x3366ff / e->height_max + e->contrast;
		ft_draw(e->x, e->y, e);
	}
	e->y_prev = e->y;
	e->x_prev = e->x;
}

int			ft_print(t_env *e)
{
	size_t		x;
	size_t		y;

	y = 0;
	mlx_clear_window(e->mlx, e->win);
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
	mlx_pixel_put(e->mlx, e->win, e->tmpx, e->tmpy, e->color);
	return (0);
}

int		ft_key_settings(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == STAR)
		ft_drawsettings(e);
	if (keycode == KEY_PLUS || (keycode == KEY_MINUS && e->zoom > 1))
		e->zoom += (keycode == KEY_MINUS ? -1 : 1);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		e->lr += (keycode == KEY_LEFT ? -10 * e->zoom : 10 * e->zoom);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		e->ud += (keycode == KEY_UP ? -10 * e->zoom : 10 * e->zoom);
	if (keycode == PAGE_UP && e->color != 0xFFFFFF)
		e->contrast += 0x123456;
	if (keycode == PAGE_DOWN && e->color >= 0x111111)
		e->contrast -= 0x123456;
	if (keycode == SLASH || keycode == EQUAL)
		e->height += (keycode == SLASH ? -1 : 1);
	mlx_clear_window(e->mlx, e->win);
	ft_print(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		ft_parse(&e, argv[1]);
		ft_drawsettings(&e);
		ft_settings();
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
		ft_print(&e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_settings, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : invalid number of arguments");
	return (0);
}
