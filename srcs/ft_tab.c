/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:22:19 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:53:19 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_nb(t_list *lst)
{
	int		i;

	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		ft_check_tab_size(int i)
{
	if (i == 1 || i == 2)
		return ((i == 1) ? 2 : 3);
	if (i == 3 || i == 4 || i == 5 || i == 6)
		return ((i == 3 || i == 4) ? 4 : 5);
	if (i == 7 || i == 8 || i == 9)
		return (6);
	if (i == 10 || i == 11 || i == 12)
		return (7);
	if (i == 13 || i == 14 || i == 15 || i == 16)
		return (8);
	if (i == 17 || i == 18 || i == 19 || i == 20)
		return (9);
	if (i == 21 || i == 22 || i == 23 || i == 24 || i == 25)
		return (10);
	if (i == 26)
		return (11);
	return (0);
}

char	**ft_creat_tab(int nb)
{
	char	**tab;
	int		i;
	int		n;

	i = 0;
	n = nb;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		ft_error();
	while (i < nb)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (nb + 1))))
			ft_error();
		tab[i][nb] = '\0';
		nb--;
		while (nb >= 0)
		{
			tab[i][nb] = '.';
			nb--;
		}
		nb = n;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_aff_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putendl(str[i]);
		i++;
	}
}
