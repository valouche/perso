/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:40:58 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 18:09:17 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list	**g_list;
t_term	gterm;

int		mk_term(void)
{
	char	*name_term;
	t_term	term;

	g_term = term;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &g_term) == -1)
		return (-1);
	g_term.c_lflag &= ~(ICANON);
	g_term.c_lflag &= ~(ECHO);
	g_term.c_cc[VMIN] = 1;
	g_term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &g_term) ==-1)
		return (-1);
	tputs(tgetstr("ti", NULL), FD, ft_putint);
	return (0);
}

int		reset_term(void)
{
	if (tcgetattr(0, &g_term) == -1)
		return (-1);
	g_term.c_lflag = (ICANON | ECHO | ISIG);
	if (tcsetattr(0, 0, &g_term) == -1)
		return (-1);
	return (0);
}

void	ft_error(int res, int ac)
{
	if (res == -1 || ac <= 1)
	{
		ft_putendl_fd("Error", FD);
		exit(1);
	}
}

void	ft_enter(t_list **list)
{
	int	ymax;

	reset_term();
	tputs(tgetstr("cl", NULL), FD, ft_putint);
	while ((*list)->y != 0)
		*list = (*list)->next;
	ymax = get_ymax(list, ymax);
	if ((*list)->select == 1 && (*list)->y == ymax)
		ft_putendl_fd((*list)->arg, 1);
	else if ((*list)->select == 1)
		ft_putstr_fd((*list)->arg, 1);
	*list = (*list)->next;
	put_last(list, ymax);
}

int		main(int ac, char **av)
{
	int		buff[3];
	t_list	*list;
	int		res;

	list = NULL;
	res = mk_term();
	ft_error(res, ac);
	list = ft_list(&list, ac, av);
	ft_loop(buff, &list, ac);
	ft_enter(&list);
	return (0);
}
