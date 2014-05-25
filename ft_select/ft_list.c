/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:02:29 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 16:03:53 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_putint(int c)
{
	write(FD, &c, 1);
	return (1);
}

void	mk_rnd_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list;
	(*list)->prev = tmp;
}

t_list	*mk_node(char *av, int ac, t_list *new)
{
	new->arg = av;
	new->x = 0;
	new->y = ac - 1;
	new->size = ft_strlen(new->arg);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	mk_list(t_list **list, char *av, int ac)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (*list == NULL)
		new = mk_node(av, ac, new);
	else if (*list)
	{
		new->arg = av;
		new->x = 0;
		new->y = ac - 1;
		new->size = ft_strlen(new->arg);
		new->next = *list;
		new->prev = NULL;
		new->next->prev = new;
		if (new->y == 0)
			new->subline = 1;
	}
	*list = new;
}

t_list	*ft_list(t_list **list, int ac, char **av)
{
	ac -= 1;
	while (ac >= 1)
	{
		mk_list(list, av[ac], ac);
		ac--;
	}
	mk_rnd_list(list);
	ft_print(ac, *list);
	return (*list);
}
