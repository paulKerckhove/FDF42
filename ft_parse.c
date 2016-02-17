/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:27:10 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/17 16:41:46 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_split_line(t_env *e)
{
	char	*line;
	int		ret;

	ret = 0;
	if (get_next_line(e->fd, &line) == 1)
	{
		e->line = ft_strsplit(line, ' ');
		free(line);
		++ret;
	}
	return (ret);
}

void		ft_parse2(t_env *e, char *file)
{
	char		*line;
	int			len;

	e->cnt_col = 0;
	e->cnt_line = 0;
	while (get_next_line(e->fd, &line) == 1)
	{
		++e->cnt_line;
		len = ft_strlen(line);
		free(line);
	}
	if (e->cnt_line == 0 || len == 0)
		ft_error("read has failed");
	e->tab = (int **)ft_memalloc(sizeof(int *) * e->cnt_line);
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	ft_split_line(e);
	while (e->line[e->cnt_col])
		++e->cnt_col;
	while (e->cnt_line  > 0)
	{
		e->tab[e->cnt_line - 1] = (int*)ft_memalloc(sizeof(int*) * e->cnt_col);
		--e->cnt_line;
	}
}

void	ft_freeparse2(t_env *e)
{
	int		i;

	i = 0;
	while (e->line[i])
	{
		ft_strdel(&e->line[i]);
		++i;
	}
}

/*
** The parse function is used to to get through our file (array) line by line.
** In the parse2 we manage to get the lenght of our colomns and our lines. Once
** it's done we close our file then re open it to start from the top of our
** array. We then use the ft_split function to get rid of all the spaces, line
** by line. Then we apply the ft_atoi function that converts chars into ints on
** each tile of our array.
*/

void		ft_parse(t_env *e, char *file)
{
	size_t	nmbr_col;

	nmbr_col = 0;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("the open has failed");
	ft_parse2(e, file);
	while (nmbr_col < e->cnt_col)
	{
		e->tab[0][nmbr_col] = ft_atoi(e->line[nmbr_col]);
		++nmbr_col;
	}
	ft_freeparse2(e);
	while (ft_split_line(e) == 1)
	{
		++e->cnt_line;
		nmbr_col = -1;
		while (e->line[++nmbr_col])
			e->tab[e->cnt_line][nmbr_col] = ft_atoi(e->line[nmbr_col]);
		if (nmbr_col != e->cnt_col)
			ft_error("invalid map");
	}
	++e->cnt_line;
	size_t		x;
	size_t		y;

	y = 0;
	while (y < e->cnt_line)
	{
		x = 0;
		while (x < e->cnt_col)
		{
			ft_putnbr(e->tab[y][x]);
			ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
