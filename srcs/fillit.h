/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:55:57 by moguy             #+#    #+#             */
/*   Updated: 2019/01/07 16:39:49 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define PATH *((t_coord*)(lst->content))
# define PAT ((t_coord*)(lst->content))
# define CX coord.x
# define CY coord.y
# include "../libft/libft.h"

typedef struct		s_coord
{
	int				height;
	int				lenght;
	int				x[4];
	int				y[4];
	char			c;
}					t_coord;

t_list				*ft_parsing(int fd, int j);

t_list				*ft_lnew2(t_coord *coord, size_t content_size);

t_coord				*ft_coordup(t_coord *coord);

char				**ft_collect(const int fd);

char				**ft_creat_tab(int nb);

int					ft_resolve(t_list *lst, int k, char **str, int j);

int					ft_check_tetri(char **str, int i);

int					ft_count_h(t_coord coord);

int					ft_count_l(t_coord coord);

int					ft_check_tab_size(int i);

int					ft_check_nb(t_list *lst);

int					ft_check_nl(int fd, char *argv);

int					ft_can_i(char **tab, t_coord coord, int i, int j);

char				**ft_put_tetri(char **tab, t_coord coord, int i, int j);

void				ft_aff_tab(char **str);

void				ft_check_endl(int fd, char *argv);

void				ft_deltab(char **tab);

void				ft_del(void *ap, size_t size);

void				ft_error(void);

void				ft_usage(void);

void				ft_lstadd_end(t_list **lst, t_list *new);

char				**ft_clear_tetri(char **tab, t_coord coord, int i, int j);

#endif
