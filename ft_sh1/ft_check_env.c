/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:24:31 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/22 15:41:39 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unsetenv(t_tab *t, t_struc *s, int ret)
{
	char	*tmp;

	if (s->arg[0] && !ft_strcmp(s->arg[0], "unsetenv"))
	{
		if (s->ac < 2)
		{
			ft_putendl("unsetenv : too few arguments");
			return (1);
		}
		else
		{
			tmp = get_line(t, s->arg[1]);
			if (tmp)
			{
				ft_unset_tab(t, s);
				ret++;
				return (ret);
			}
		}
	}
	return (0);
}

int		ft_check_env(t_tab *t, t_struc *s, int ret)
{
	ret = (ft_unsetenv(t, s, ret));
	if (ret > 0)
		return (ret);
	if (s->arg[0] && !ft_strcmp(s->arg[0], "setenv"))
	{
		if (s->ac == 1)
		{
			ft_aff_env(t);
			ret++;
			return (ret);
		}
		else if (s->ac > 3)
			ft_putendl("setenv : too few arguments");
		else
			ft_setenv(t, s);
		ret++;
		return (ret);
	}
	if (s->arg[0] && !ft_strcmp(s->arg[0], "env"))
	{
		ft_aff_env(t);
		ret++;
		return (ret);
	}
	return (0);
}

void	ft_redefine(t_tab *t, char *tmp2, t_struc *s, char *tmp)
{
	if (tmp && s->ac == 3)
		tmp2 = ft_strjoin(tmp2, s->arg[2]);
	else
		tmp2 = ft_strjoin(tmp2, "\0");
	free(t->my_env[get_tab_row(t, s->arg[1])]);
	t->my_env[get_tab_row(t, s->arg[1])] = tmp2;
}

void	ft_create(t_tab *t, t_struc *s, char *tmp2)
{
	int	i;

	i = 0;
	while (t->my_env[i])
		i++;
	t->new_tab = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (t->my_env[i])
	{
		t->new_tab[i] = strdup(t->my_env[i]);
		i++;
	}
	if (s->ac == 3)
			tmp2 = ft_strjoin(tmp2, s->arg[2]);
	else if (s->ac == 2)
		tmp2 = ft_strjoin(tmp2, "\0");
	t->new_tab[i] = tmp2;
	i++;
	t->new_tab[i] = '\0';
	t->my_env = t->new_tab;
}

int		ft_setenv(t_tab *t, t_struc *s)
{
	char	*tmp;
	char	*tmp2;

	tmp = get_line(t, s->arg[1]);
	tmp2 = ft_strjoin(s->arg[1], "=");
	if (tmp)
	{
		ft_redefine(t, tmp2, s, tmp);
		return (0);
	}
	else if (!tmp)
	{
		ft_create(t, s, tmp2);
		return (0);
	}
	return (0);
}
