/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:54:38 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/23 18:27:12 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(int max, int i)
{
	int		c[3];
	int		x;

	x = (1530 / max) * i;
	if (x >= 0 && x < 255)
	{
		c[0] = 255;
		c[1] = x;
		c[2] = 0;
	}
	else if (x >= 255 && x < 510)
	{
		c[0] = 510 - x;
		c[1] = 255;
		c[2] = 0;
	}
	else if (x >= 510 && x < 765)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = x - 510;
	}
	else
		ft_color2(c, x);
	return ((c[0] << 16) + (c[1] << 8) + c[2]);
}

void    ft_color2(int *c, int x)
{
	if (x >= 765 && x < 1020)
	{
		c[0] = 0;
		c[1] = 1020 - x;
		c[2] = 255;
	}
	else if (x >= 1020 && x < 1275)
	{
		c[0] = x - 1020;
		c[1] = 0;
		c[2] = 255;
	}
	else
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 1530 - x;
	}
}

void    ft_px(t_env *e, int x, int y, int c)
{
	int		r;
	int		g;
	int		b;

	r = (c & 0xFF0000) >> 16;
	g = (c & 0xFF00) >> 8;
	b = (c & 0xFF);
	if (y >= 0 && x >= 0 && y < HEIGHT && x < WIDTH)
	{
		e->px[(y * e->sl) + ((e->bpp / 8) * x) + 2] = r;
		e->px[(y * e->sl) + ((e->bpp / 8) * x) + 1] = g;
		e->px[(y * e->sl) + ((e->bpp / 8) * x)] = b;
	}
}
