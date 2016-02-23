/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:42:06 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/23 11:17:47 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw(int x2, int y2, t_env *e)
{
	e->tmpx = e->x_prev;
	e->tmpy = e->y_prev;
	e->dx = abs(x2 - e->x_prev);
	e->dy = abs(y2 - e->y_prev);
	e->sx = e->x_prev < x2 ? 1 : -1;
	e->sy = e->y_prev < y2 ? 1 : -1;
	e->error = (e->dx > e->dy ? e->dx : -(e->dy)) / 2;
	while (!(e->tmpy == y2 && e-> tmpx == x2))
	{
		mlx_pixel_put(e->mlx, e->win, e->tmpx, e->tmpy, e->color);
		e->tmp_error = e->error;
		if (e->tmp_error > -(e->dx))
		{
			e->error -= (e->dy);
			e->tmpx += e->sx;
		}
		if (e->tmp_error < (e->dy))
		{
			e->error += (e->dx);
			e->tmpy += e->sy;
		}
	}
} 
