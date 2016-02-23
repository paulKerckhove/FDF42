/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:44:46 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/23 14:52:01 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_settings(void)
{
	ft_putstr("\n\n=======================================================");
	ft_putstr("\n                   FDF 42 by pkerckho                  \n");
	ft_putstr("=======================================================\n\n");
	ft_putstr("                      ------------                    |  \n");
	ft_putstr("                      | Controls |                     | \n");
	ft_putstr("                      ------------                    |\n\n");
	ft_putstr("#########################################################\n");
	ft_putstr("#   move up              ||      up                     #\n");
	ft_putstr("#   move down            ||     down                    #\n");
	ft_putstr("#   move left            ||     left                    #\n");
	ft_putstr("#   move right           ||     right                   #\n");
	ft_putstr("#   zoom in              ||      +                      #\n");
	ft_putstr("#   zoom out             ||      -                      #\n");
	ft_putstr("#########################################################\n");
}

