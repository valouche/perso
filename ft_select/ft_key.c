/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:08:27 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 16:23:19 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	put_last(t_list **list, int ymax)
{
	while ((*list)->y != 0)
	{
		if ((*list)->select == 1 && (*list)->y == ymax)
		{
			ft_putstr_fd(" ", 1);
			ft_putendl_fd((*list)->arg, 1);
		}
		else if ((*list)->select == 1)
		{
			ft_putstr_fd(" ", 1);
			ft_putstr_fd((*list)->arg, 1);
		}
		*list = (*list)->next;
	}
}

int		get_ymax(t_list **list, int ymax)
{

	ymax = 0;
	while ((*list)->y != 0)
		*list = (*list)->next;
	*list = (*list)->next;
	while ((*list)->y != 0)
	{
		if ((*list)->select == 1)
			ymax = (*list)->y;
		*list = (*list)->next;
	}
	return (ymax);
}

void	ft_print(int ac, t_list *list)
{
	while (ac++ <= list->y)
	{
		if (list->subline == 1)
		{
			tputs(tgetstr("us", NULL), FD, ft_putint);
			ft_putendl_fd(list->arg, FD);
			tputs(tgetstr("me", NULL), FD, ft_putint);
			list = list->next;
		}
		else
		{
			ft_putendl_fd(list->arg, FD);
			list = list->next;
		}
	}
}

void	ft_echap(int *buff, int ac)
{
	int	res;

	if (buff[0] == 27)
	{
		tputs(tgetstr("te", NULL), FD, ft_putint);
		res = reset_term();
		ft_error(res, ac);
		exit(0);
	}
}

void	ft_chk_slct(t_list **list)
{
	if ((*list)->select == 0)
	{
		tputs(tgetstr("mr", NULL), FD, ft_putint);
		(*list)->select = 1;
	}
	else
	{
		tputs(tgetstr("me", NULL), FD, ft_putint);
		(*list)->select = 0;
	}
}
