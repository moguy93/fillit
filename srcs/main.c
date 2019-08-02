/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:13:48 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:53:03 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		do_it(char **str, t_list *lst, int k)
{
	while (ft_resolve(lst, k, str, 0) != 1)
	{
		ft_deltab(str);
		k++;
		str = ft_creat_tab(k);
	}
	ft_aff_tab(str);
	ft_lstdel(&lst, ft_del);
	ft_deltab(str);
}

int			main(int argc, char **argv)
{
	t_list	*lst;
	int		fd;
	int		k;
	char	**str;
	int		j;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	fd = 0;
	ft_check_endl(fd, argv[1]);
	j = ft_check_nl(fd, argv[1]);
	if (j == 0)
		ft_error();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error();
	if (!(lst = ft_parsing(fd, j)))
		ft_error();
	k = ft_check_tab_size(ft_check_nb(lst));
	str = ft_creat_tab(k);
	do_it(str, lst, k);
	return (0);
}
