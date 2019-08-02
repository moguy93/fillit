/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:29:57 by moguy             #+#    #+#             */
/*   Updated: 2019/01/04 16:35:19 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_h(t_coord coord)
{
	int		height;
	int		z;

	z = 0;
	height = 0;
	while (z < 4)
	{
		if (height < coord.y[z])
			height = coord.y[z];
		z++;
	}
	return (height + 1);
}

int		ft_count_l(t_coord coord)
{
	int		lenght;
	int		z;

	z = 0;
	lenght = 0;
	while (z < 4)
	{
		if (lenght < coord.x[z])
			lenght = coord.x[z];
		z++;
	}
	return (lenght + 1);
}
