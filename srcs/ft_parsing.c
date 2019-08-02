/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:15:39 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:52:23 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		put_up_left(t_coord *coord)
{
	while (coord->x[0] != 0 && coord->x[1] != 0 && coord->x[2] != 0 &&
			coord->x[3] != 0)
	{
		coord->x[0] -= 1;
		coord->x[1] -= 1;
		coord->x[2] -= 1;
		coord->x[3] -= 1;
	}
	while (coord->y[0] != 0 && coord->y[1] != 0 && coord->y[2] != 0 &&
			coord->y[3] != 0)
	{
		coord->y[0] -= 1;
		coord->y[1] -= 1;
		coord->y[2] -= 1;
		coord->y[3] -= 1;
	}
}

static void		ft_more(t_coord *coord)
{
	put_up_left(coord);
	(*coord).lenght = ft_count_l(*coord);
	(*coord).height = ft_count_h(*coord);
}

static t_coord	*putin(char **str)
{
	int			i;
	int			j;
	int			z;
	t_coord		*coord;

	i = 0;
	z = -1;
	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				(*coord).x[++z] = j;
				(*coord).y[z] = i;
			}
			j++;
		}
		i++;
	}
	ft_more(coord);
	return (coord);
}

static int		ft_shortcut(int j, int fd)
{
	char	*line;
	int		k;

	line = NULL;
	if (j > 0)
	{
		if (get_next_line(fd, &line) > 0)
			if (line[0] != '\0')
				ft_error();
		j--;
	}
	k = j;
	free(line);
	return (k);
}

t_list			*ft_parsing(int fd, int j)
{
	char	**str;
	t_list	*lst;
	t_coord *coord;
	char	c;

	c = 'A';
	lst = NULL;
	while ((str = ft_collect(fd)))
	{
		j -= 4;
		j = ft_shortcut(j, fd);
		coord = putin(str);
		(*coord).c = c;
		if (c == 'A')
			lst = ft_lnew2(ft_coordup(coord), sizeof(t_coord*));
		else
			ft_lstadd_end(&lst, ft_lnew2(ft_coordup(coord), sizeof(t_coord*)));
		c++;
		ft_deltab(str);
	}
	if (c > 'Z')
		ft_error();
	return (lst);
}
