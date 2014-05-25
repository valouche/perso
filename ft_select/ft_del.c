/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:04:36 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 16:06:58 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	print_new_list(t_list **list)
{
	while ((*list)->y != 0)
		*list = (*list)->next;
	while ((*list)->y < (*list)->next->y)
	{
		if ((*list)->select == 1 || (*list)->subline == 1)
		{
			if ((*list)->select == 1)
				tputs(tgetstr("mr", NULL), FD, ft_putint);
			if ((*list)->subline == 1)
				tputs(tgetstr("us", NULL), FD, ft_putint);
			ft_putendl_fd((*list)->arg, FD);
			*list = (*list)->next;
			tputs(tgetstr("me", NULL), FD, ft_putint);
		}
		else
		{
			ft_putendl_fd((*list)->arg, FD);
			*list = (*list)->next;
		}
	}
	print_new_end(list);
}

void	print_new_end(t_list **list)
{
	if ((*list)->select == 1 || (*list)->subline == 1)
	{
		if ((*list)->select == 1)
			tputs(tgetstr("mr", NULL), FD, ft_putint);
		if ((*list)->subline == 1)
				tputs(tgetstr("us", NULL), FD, ft_putint);
		ft_putendl_fd((*list)->arg, FD);
	}
	else
		ft_putendl_fd((*list)->arg, FD);
}

void	ft_del(int *buff, t_list **list)
{
	if (buff[0] == 3365659 || buff[0] == 127)
	{
		if ((*list)->y == (*list)->next->y)
			exit(0);
		rmv_list(list);
		tputs(tgetstr("cl", NULL), FD, ft_putint);
		print_new_list(list);
		while ((*list)->subline != 1)
			*list = (*list)->next;
		tputs(tgoto(tgetstr("cm", NULL), 0, (*list)->y), FD, ft_putint);
	}
}

void	rmv_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list)->y > (*list)->next->y)
		ft_rmv_end(tmp, tmp2, list);
	else
	{
		while ((*list)->y < (*list)->next->y)
		{
			(*list)->select = (*list)->next->select;
			(*list)->arg = (*list)->next->arg;
			*list = (*list)->next;
		}
		tmp = *list;
		tmp2 = *list;
		*list = (*list)->prev;
		while (tmp2->y != 0)
			tmp2 = tmp2->next;
		tmp2->prev = *list;
		(*list)->next = tmp2;
		free(tmp);
	}
}

void	ft_rmv_end(t_list *tmp, t_list *tmp2, t_list **list)
{
	if ((*list)->y > (*list)->next->y)
	{
		tmp = *list;
		tmp2 = (*list)->prev;
		(*list)->prev->subline = 1;
		*list = (*list)->next;
		tmp2->next = *list;
		(*list)->prev = tmp2;
		free(tmp);
	}
}
