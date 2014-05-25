/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:53:07 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 15:54:46 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list	**g_list;
t_term	g_term;

int		ft_open(void)
{
	static int	i = 0;
	static int	fd;

	if (i == 0)
	{
		fd = open(ttyname(0), O_RDWR);
		i++;
	}
	return (fd);
}

void	ft_rzwin(int c)
{
	t_win	win;

	(void)c;
	ioctl(0, TIOCGWINSZ, &win);
	while ((*g_list)->y < (*g_list)->next->y)
		*g_list = (*g_list)->next;
	if (win.ws_row <= (*g_list)->y)
	{
		tputs(tgetstr("cl", NULL), FD, ft_putint);
		ft_putendl_fd("Too small window", FD);
	}
	else
	{
		tputs(tgetstr("cl", NULL), FD, ft_putint);
		print_new_list(g_list);
		while ((*g_list)->subline != 1)
			*g_list = (*g_list)->next;
		tputs(tgoto(tgetstr("cm", NULL), 0, (*g_list)->y), FD, ft_putint);
	}
}

void	ft_reset_term(int c)
{
	(void)c;
	reset_term();
	tputs(tgetstr("cl", NULL), 0, ft_putint);
	exit(0);
}

void	ft_chk_sig(void)
{
	signal(SIGINT, ft_reset_term);
	signal(SIGWINCH, ft_rzwin);
}
