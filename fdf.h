/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:15 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/10 11:20:29 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 400
# define WIN_Y 400

# include "libft/includes/libft.h"
# include "minilibx/mlx.h"

typedef struct			s_mlx
{
	int		x;
	int		y;
	int		color;
	void	*mlx;
	void	*win;
}						t_mlx;

#endif
