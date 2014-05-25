/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:11:16 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 16:12:40 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_chk_down(int *buff, t_list **list)
{
	if (buff[0] == 4348699)
	{
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 0;
		*list = (*list)->next;
		tputs(tgetstr("me", NULL), FD, ft_putint);
		tputs(tgoto(tgetstr("cm", NULL), 0, (*list)->y), FD, ft_putint);
		tputs(tgetstr("us", NULL), FD, ft_putint);
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 1;
	}
}

void	ft_chk_up(int *buff, t_list **list)
{
	if (buff[0] == 4283163)
	{
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 0;
		*list = (*list)->prev;
		tputs(tgetstr("me", NULL), FD, ft_putint);
		tputs(tgoto(tgetstr("cm", NULL), 0, (*list)->y), FD, ft_putint);
		tputs(tgetstr("us", NULL), FD, ft_putint);
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 1;
	}
}

void	ft_down(t_list **list)
{
	if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
	ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 0;
		*list = (*list)->next;
		tputs(tgetstr("me", NULL), FD, ft_putint);
		tputs(tgoto(tgetstr("cm", NULL), 0, (*list)->y), FD, ft_putint);
		tputs(tgetstr("us", NULL), FD, ft_putint);
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		ft_putstr_fd((*list)->arg, FD);
		(*list)->subline = 1;
}

int		ft_loop(int *buff, t_list **list, int ac)
{
	while (1)
	{
		g_list = list;
		ft_chk_sig();
		tputs(tgoto(tgetstr("cm", NULL), 0, (*list)->y), FD, ft_putint);
		buff[0] = 0;
		read(0, buff, 3);
		ft_chk_up(buff, list);
		ft_chk_down(buff, list);
		if (buff[0] == 32)
		{
			ft_chk_slct(list);
			ft_down(list);
		}
		ft_del(buff, list);
		ft_echap(buff, ac);
		if (buff[0] == 10)
			return (0);
		tputs(tgetstr("me", NULL), FD, ft_putint);
	}
}
