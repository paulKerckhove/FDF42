/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:27:10 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/12 13:06:54 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/includes/libft.h"

void		ft_parse2(t_env *e, char *file)
{
	char	*line;
	size_t		i;

	i = 0;
	while ((ft_get_next_line(e->fd, &line) == 1))
	{
		i++;
		free(line);
	}
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	if (!(e->line = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		ft_error("the malloc has failed");
	free(line);
}

/*
** In this function we are "parsing", checking if what we are
** openning and reading exist (is openned and readable) then we call our
** second parsing function (ft_parse2), it will apply our ft_get_next_line
** function on the data and malloc it.
** Back to our ft_parse, if the ft_get_next_line hasn't failed we use our two
** variables (i, j) to browse through it and print it (ft_putendl).
*/

void		ft_parse(t_env *e, char *file, int argc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (argc != 2)
		ft_error("wrong number of arguments");
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("the open has failed");
	ft_parse2(e, file);
	while ((ft_get_next_line(e->fd, &(e->line[i])) == 1))
		i++;
	while (++j < i)
	{
		ft_putendl(e->line[j]);
		free(e->line[j]);
	}
	free(e->line);
}
