/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:15 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/22 16:51:33 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1600
# define WIN_Y 1200

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct				s_env
{
	int						fd;
	char					**line;
	size_t						x;
	size_t						y;
	int						color;
	void					*mlx;
	void					*win;
	size_t						cnt_col;
	size_t						cnt_line;
	int						**tab;
	int						x_prev;
	int						y_prev;
	int						tmp_error;
	int						error;
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						tmpx;
	int						tmpy;
}							t_env;

void						ft_parse(t_env *e, char *file);
int							ft_split_line(t_env *e);
void						ft_parse2(t_env *e, char *file);
void						ft_freeparse2(t_env *e);
void						ft_draw(int x2, int y2, t_env *e);

#endif
