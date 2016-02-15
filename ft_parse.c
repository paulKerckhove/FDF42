/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:27:10 by pkerckho          #+#    #+#             */
/*   Updated: 2016/02/15 11:07:29 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/includes/libft.h"

void		ft_parse2(t_env *e, char *file)
{
	char	*line;
	size_t	i;

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
** and we use the variable (i) to count till the end and have the size.
** Then we close the file because we are at then end of it and we re open it
** to start from the beginning. Now we malloc each start of line of our board
** because we know the size of the total baord (i) but not the exact size of
** each line.
** Back to our ft_parse, if the ft_get_next_line hasn't failed we use our two
** variables (i, j) to browse through it and print our whole board in line, and
** we use (ft_putendl) to print it to check.
*/

void		ft_parse(t_env *e, char *file)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
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
