/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:44:46 by pkerckho          #+#    #+#             */
/*   Updated: 2016/03/02 11:48:23 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_settings(t_env e)
{
	int		i_y;

	i_y = 0;
	mlx_string_put(e.mlx, e.win, 0, i_y, 0xccccff, I_SETINGS);
	mlx_string_put(e.mlx, e.win, 0, i_y + 16, 0xccccff, I_KEY_UP);
	mlx_string_put(e.mlx, e.win, 0, i_y + 32, 0xccccff, I_KEY_DOWN);
	mlx_string_put(e.mlx, e.win, 0, i_y + 48, 0xccccff, I_KEY_LEFT);
	mlx_string_put(e.mlx, e.win, 0, i_y + 64, 0xccccff, I_KEY_RIGHT);
	mlx_string_put(e.mlx, e.win, 0, i_y + 80, 0xccccff, I_KEY_PLUS);
	mlx_string_put(e.mlx, e.win, 0, i_y + 96, 0xccccff, I_KEY_MINUS);
	mlx_string_put(e.mlx, e.win, 0, i_y + 112, 0xccccff, I_PAGE_UP);
	mlx_string_put(e.mlx, e.win, 0, i_y + 128, 0xccccff, I_PAGE_DOWN);
	mlx_string_put(e.mlx, e.win, 0, i_y + 144, 0xccccff, I_STAR);
	mlx_string_put(e.mlx, e.win, 0, i_y + 160, 0xccccff, I_SLASH);
	mlx_string_put(e.mlx, e.win, 0, i_y + 176, 0xccccff, I_RESET);
	mlx_string_put(e.mlx, e.win, 0, i_y + 192, 0xccccff, I_ESC);
}
