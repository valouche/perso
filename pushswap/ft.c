/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 18:06:16 by vdiridol          #+#    #+#             */
/*   Updated: 2014/05/16 16:07:46 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	ft_mk_list(char *arg, t_list **list)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->num = ft_atoi(arg);
		new->next = NULL;
	}
	if (*list == NULL)
	{
		*list = new;
		new->begin = 1;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		ft_checkdb(char **av)
{
	char	*s;
	int		i;
	int		j;

	j = 1;
	while (av[j])
	{
		s = av[j];
		i = 1;
		while (av[i])
		{
			if (!ft_strcmp(av[i], s) && i != j)
			{
				write(2, "Error\n", 7);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_is_number(char **av)
{
	int	j;
	int	i;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
			{
				write(2, "Error\n", 7);
				return (1) ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_p_error()
{
	write(2, "Error\n", 6);
	return (1);
}

int		ft_error(int ac, char **av)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	if (ac == 1)
		return (ft_p_error());
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (ft_p_error());
		i++;
	}
	ret += ft_checkdb(av);
	ret += ft_is_number(av);
	return (ret);
}

void	printlist(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next->begin != 1)
	{
		ft_putnbr(tmp->num);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
		ft_putnbr(tmp->num);
		write(1, "\n", 1);
}

void	ft_listb(t_list **list)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->num = 1;
		new->next = NULL;
	}
	if (*list == NULL)
	{
		*list = new;
		new->begin = 1;
	}	
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	sa(t_list *lista)
{
	t_list	*tmp;
	int		swap;

	swap = lista->num;
	tmp = lista->next;
	lista->num = tmp->num;
	tmp->num = swap;
	ft_putendl("sa");
}

void	sb(t_list *listb)
{
	t_list	*tmp;
	int		swap;

	swap = listb->num;
	tmp = listb->next;
	listb->num = tmp->num;
	tmp->num = swap;
	ft_putendl("sb");
}

void	ra(t_list **lista)
{
	t_list	*tmp;

	tmp = *lista;
	tmp->begin = 0;
	tmp = tmp->next;
	tmp->begin = 1;
	*lista = tmp;
	ft_putendl("ra");
}

void	rb(t_list **listb)
{
	t_list	*tmp;

	tmp = *listb;
	tmp->begin = 0;
	tmp = tmp->next;
	tmp->begin = 1;
	*listb = tmp;
	ft_putendl("rb");
}

void	rra(t_list **lista)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	tmp = *lista;
	tmp2 = tmp;
	while (tmp->next->begin != 1)
		tmp = tmp->next;
	tmp2->begin = 0;
	tmp->begin = 1;
	*lista = tmp;
	ft_putendl("rra");
}

void	ft_sort(t_list **lista, t_list **listb)
{
	rra(&(*lista));
//	rrb(&(*listb));
	sa(*lista);
	sb(*listb);
	ra(&(*lista));
	rb(&(*listb));
}	

void	ft_mk_rnd(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list;
}

void	ft_pushswap(t_list **lista, int ac)
{
	t_list	*listb;
	int		i;

	i = 1;
	listb = NULL;
	while (i < ac)
	{
		ft_listb(&listb);
		i++;
	}
	ft_mk_rnd(&listb);
	ft_sort(lista, &listb);
}

int		main(int ac, char **av)
{
	int		i;
	t_list	*list;
	int		ret;
	
	list = NULL;
	ret = ft_error(ac, av);
	if (ret != 0)
		return (0);
	i = 1;
	while (i < ac)
	{
		ft_mk_list(av[i], &list);
		i++;
	}
	ft_mk_rnd(&list);
	ft_pushswap(&list, ac);
	printlist(&list);
	return (0);
}
