/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:43:30 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:53:40 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_nl(int fd, char *argv)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	a = 'm';
	j = 1;
	fd = open(argv, O_RDONLY);
	while (j)
	{
		j = read(fd, &a, 1);
		if (a == '\n')
			i++;
	}
	close(fd);
	return (i);
}

void	ft_check_endl(int fd, char *argv)
{
	int		i;
	int		j;
	char	a;
	char	b;

	i = 1;
	j = 1;
	a = 'm';
	b = 'g';
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error();
	while (i && j)
	{
		i = read(fd, &a, 1);
		j = read(fd, &b, 1);
	}
	close(fd);
	if (b == '\n' && a == '\n')
		ft_error();
}

char	**ft_collect(const int fd)
{
	int		i;
	int		h;
	char	**str;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * 5)) || fd < 0)
		ft_error();
	while (i < 4)
	{
		h = get_next_line(fd, &str[i]);
		if (h == -1 || (h == 0 && i != 0))
			ft_error();
		if (h == 0)
		{
			ft_deltab(str);
			return (NULL);
		}
		i++;
	}
	str[4] = NULL;
	ft_check_tetri(str, 0);
	return (str);
}
