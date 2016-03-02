/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:15 by pkerckho          #+#    #+#             */
/*   Updated: 2016/03/02 11:43:23 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 2560
# define WIN_Y 1400

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 69
# define KEY_MINUS 78
# define PAGE_UP 116
# define PAGE_DOWN 121
# define RESET 71
# define ESC 53
# define SLASH 75
# define STAR 67

# define WELCOME "Welcome to fdf by pkerckho"
# define START "Press any key to start"

# define I_SETINGS "               SETTINGS"
# define I_KEY_UP "    move up       ||  up"
# define I_KEY_DOWN "    move down     ||  down"
# define I_KEY_LEFT "    move left     ||  left"
# define I_KEY_RIGHT "    move right    ||  right"
# define I_KEY_PLUS "    zoom in       ||  +"
# define I_KEY_MINUS "    zoom out      ||  -"
# define I_STAR "  increase height ||  *"
# define I_SLASH "  decrease height ||  /"
# define I_PAGE_UP "  epileptic mode  ||  page up"
# define I_PAGE_DOWN "  epileptic mode  ||  page down"
# define I_RESET "       reset      ||  clear"
# define I_ESC "    exit program  ||  esc"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

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
	size_t					cnt_col;
	size_t					cnt_line;
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
	int						zoom;
	int						lr;
	int						ud;
	int						height;
	int						height_max;
	int						contrast;
	void					*im;
	void					*imc;
	int						imlen;
	int						bpp;
	int						endi;
}							t_env;

void						ft_parse(t_env *e, char *file);
int							ft_split_line(t_env *e);
void						ft_parse2(t_env *e, char *file);
void						ft_freeparse2(t_env *e);
void						ft_draw(int x2, int y2, t_env *e);
int							ft_key_settings(int keycode, t_env *e);
void						ft_settings(t_env e);
void						ft_create_color(int *colors);
void						ft_color(void);
void						ft_put_pixel(t_env *e, int x, int y, int color);
#endif
