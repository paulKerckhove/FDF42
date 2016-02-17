/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:26 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/17 16:28:11 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>



void		ft_print(t_env e)
{
	int		tile;

	if (WIN_Y / (e.cnt_line + 1) < WIN_X / (e.cnt_col + 1))
		tile = WIN_Y / (e.cnt_line + 1);
	else
		tile = WIN_X / (e.cnt_col + 1);
	e.y = (WIN_Y - ((e.cnt_line - 1) * tile)) / 2;
	while (e.y <= WIN_Y - (WIN_Y - ((e.cnt_line - 1) * tile)) / 2)
	{
		e.x = (WIN_X - ((e.cnt_col - 1) * tile)) / 2;
		while (e.x <= WIN_X - (WIN_X - ((e.cnt_col - 1) * tile)) / 2)
		{
			mlx_pixel_put(e.mlx, e.win, e.x, e.y, e.color);
			e.x = e.x + tile;
		}
		e.y = e.y  + tile;
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
	e.color = 0x00FFFF;
	e.y = WIN_Y / 4;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "mlx42");
	ft_print(e);
	mlx_key_hook(e.win, ft_keyfunct, &e);
	mlx_loop(e.mlx);
	return (0);
}
