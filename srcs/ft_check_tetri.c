/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:38:03 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:53:29 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_check_valid(char **str, int i, int j, int *connex)
{
	if (i > 0)
		if (str[i - 1][j] == '#')
			(*connex)++;
	if (j > 0)
		if (str[i][j - 1] == '#')
			(*connex)++;
	if (j < 3)
		if (str[i][j + 1] == '#')
			(*connex)++;
	if (i < 3)
		if (str[i + 1][j] == '#')
			(*connex)++;
}

int			ft_check_tetri(char **str, int i)
{
	int			j;
	int			count;
	int			connex;

	count = 0;
	connex = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#' && (count = count + 1))
				ft_check_valid(str, i, j, &connex);
			if (str[i][j] != '#' && str[i][j] != '.')
				ft_error();
			j++;
		}
		if (j != 4)
			ft_error();
		i++;
	}
	if (count != 4 || connex < 6 || i != 4)
		ft_error();
	return (1);
}
