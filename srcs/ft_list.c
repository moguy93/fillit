/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:05:26 by moguy             #+#    #+#             */
/*   Updated: 2019/02/08 03:49:23 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lnew2(t_coord *coord, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	newlst->content = coord;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}

void	ft_lstadd_end(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_coord	*ft_coordup(t_coord *coord)
{
	t_coord	*dup;

	if (!(dup = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	dup->x[0] = coord->x[0];
	dup->y[0] = coord->y[0];
	dup->x[1] = coord->x[1];
	dup->y[1] = coord->y[1];
	dup->x[2] = coord->x[2];
	dup->y[2] = coord->y[2];
	dup->x[3] = coord->x[3];
	dup->y[3] = coord->y[3];
	dup->c = coord->c;
	dup->height = coord->height;
	dup->lenght = coord->lenght;
	free(coord);
	return (dup);
}

void	ft_del(void *ap, size_t size)
{
	size = 0;
	ft_memdel(&ap);
}
