/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:49:36 by moguy             #+#    #+#             */
/*   Updated: 2019/01/04 17:16:36 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_i(char **tab, t_coord coord, int i, int j)
{
	if ((tab[i + CY[0]][j + CX[0]] == '.') && (tab[i + CY[1]][j + CX[1]] == '.')
			&& (tab[i + CY[2]][j + CX[2]] == '.')
			&& (tab[i + CY[3]][j + CX[3]] == '.'))
		return (1);
	return (0);
}

char	**ft_put_tetri(char **tab, t_coord coord, int i, int j)
{
	tab[i + CY[0]][j + CX[0]] = coord.c;
	tab[i + CY[1]][j + CX[1]] = coord.c;
	tab[i + CY[2]][j + CX[2]] = coord.c;
	tab[i + CY[3]][j + CX[3]] = coord.c;
	return (tab);
}

char	**ft_clear_tetri(char **tab, t_coord coord, int i, int j)
{
	tab[i + CY[0]][j + CX[0]] = '.';
	tab[i + CY[1]][j + CX[1]] = '.';
	tab[i + CY[2]][j + CX[2]] = '.';
	tab[i + CY[3]][j + CX[3]] = '.';
	return (tab);
}

int		ft_resolve(t_list *lst, int k, char **tab, int j)
{
	int		i;

	i = 0;
	while ((i + PAT->height) <= k)
	{
		while ((j + PAT->lenght) <= k)
		{
			if (ft_can_i(tab, PATH, i, j) == 1)
			{
				ft_put_tetri(tab, PATH, i, j);
				if (lst->next)
				{
					if (ft_resolve(lst->next, k, tab, 0))
						return (1);
				}
				else
					return (1);
				ft_clear_tetri(tab, PATH, i, j);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
