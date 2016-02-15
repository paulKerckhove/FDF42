/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:26 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/15 17:43:12 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_keyfunct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	void	*mlx;
	void	*win;
	int		x;
	int		y;

	if (argc != 2)
		ft_error("wrong number of arguments");
	ft_parse(&e, argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, ft_keyfunct, 0);
	mlx_loop(mlx);
	return (0);
}
