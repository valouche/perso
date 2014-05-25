/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:47:17 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/27 14:50:23 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_struc *s, int error)
{
	if (error != 0)
	{
		ft_putstr(s->arg[1]);
		ft_putendl("is not a directory");
	}
}

void	ft_prio(t_struc *s, t_tab *t)
{
	int	ret;

	s->i = 0;
	s->prio = ft_strsplit(s->buff, ';');
	while (s->prio[s->i])
	{
		s->arg = ft_strsplit(s->prio[s->i], ' ' );
		ret = ft_builtin(t, s, ret);
		ft_fork(t, s, ret);
	}
}
