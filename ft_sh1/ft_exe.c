/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:32:23 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/22 15:28:26 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exe(t_tab *t, t_struc *s)
{
	s->i = 0;
	while (t->my_path[s->i])
	{
		t->my_path[s->i] = ft_strjoin(t->my_path[s->i], "/");
		execve(ft_strjoin(t->my_path[s->i], s->arg[0]), s->arg, t->my_env);
		s->i++;
	}
	execve(s->arg[0], s->arg, t->my_env);
}

int		get_tab_row(t_tab *t, char *l)
{
	int     i;
	int		res;

	i = 0;
	while (t->my_env[i])
	{
		res = ft_srchstr(t->my_env[i], l);
		if (res == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_srchstr(char *search, char *tofind)
{
	int	j;

	j = 0;
	while (search[j] == tofind[j])
	{
		j++;
		if (tofind[j] == '\0')
			return (1);
	}
	return (0);
}

void	ft_aff_env(t_tab *t)
{
	int	i;

	i = 0;
	while (t->my_env[i])
	{
		ft_putendl(t->my_env[i]);
		i++;
	}
}

void	ft_unset_tab(t_tab *t, t_struc *s)
{
	int	i;

	i = get_tab_row(t, s->arg[1]);
	ft_strclr(t->my_env[get_tab_row(t, s->arg[1])]);
	free(t->my_env[get_tab_row(t, s->arg[1])]);
	while (t->my_env[i + 1])
	{
		t->my_env[i] = ft_strdup(t->my_env[i + 1]);
		i++;
	}
	t->my_env[i] = '\0';
}
