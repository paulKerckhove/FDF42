/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:15 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/15 18:17:06 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1000
# define WIN_Y 1000

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct				s_env
{
	int						fd;
	char					**line;
	int						x;
	int						y;
	int						color;
	void					*mlx;
	void					*win;
	size_t					cnt_col;
	size_t					cnt_line;
	int						**tab;
}							t_env;

void						ft_parse(t_env *e, char *file);
int							ft_split_line(t_env *e);
void						ft_parse2(t_env *e, char *file);
void						ft_freeparse2(t_env *e);

#endif
