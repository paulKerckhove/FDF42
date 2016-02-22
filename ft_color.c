/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:34:35 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/22 18:10:28 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**ft_createcolor(char **colors)
{
	colors[0] = "\xfe00f6";
	colors[1] = "\x011efe";
	colors[2] = "\x08deeee";
	colors[3] = "\x0bff01";
	colors[4] = "\x0fdfe02";
	colors[5] = "\x0fe0000";
}


void		ft_color(void)
{
	char *colors[6];
	int i;

	i = 0;
	while (i != 5)
		ft_putstr(colors[i++]);
	if (i == 5)
		i = 0;
}
