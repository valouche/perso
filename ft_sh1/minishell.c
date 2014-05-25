/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:44:26 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/27 14:55:26 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_Shell_done(t_tab *t);

void	ft_get_path(t_tab *t)
{
	char	*tmp;
	int		i;

	i = 0;
	while (t->my_env[i])
	{
		tmp = ft_strstr(t->my_env[i], "PATH=");
		if (tmp)
		{
			tmp = ft_strsub(tmp, 5, ft_strlen(tmp) - 4);
			t->my_path = ft_strsplit(tmp, ':');
			break ;
		}
		i++;
	}
}

int		ft_builtin(t_tab *t, t_struc *s, int ret)
{
	ret = ft_check_env(t, s, ret);
	if (ret > 0)
		return (ret);
	ret = ft_cd(s, t, ret);
	return (ret);
}

static	void	ft_Shell_done(t_tab *t)
{
	int		ret;
	t_struc	s;

	s.buff = malloc(sizeof(char) * 1024);
	while ((s.ret = read(0, s.buff, 1024)))
	{
		s.ac = 0;
		s.buff[s.ret - 1] = '\0';
		if (ft_strstr(s.buff, ";"))
			ft_prio(&s, t);
		else
			s.arg = ft_strsplit(s.buff, ' ');
		if (s.arg[0] && !ft_strcmp(s.arg[0], "exit"))
			break ;
		while (s.arg[s.ac])
			s.ac++;
		ret = ft_builtin(t, &s, ret);
		ft_fork(t, &s, ret);
		free(s.buff);
		s.buff = malloc(sizeof(char) * 1024);
	}
}

void	ft_get_env(char **env, t_tab *t)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	t->my_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		t->my_env[i] = ft_strdup(env[i]);
		i++;
	}
	t->my_env[i] = '\0';
}

int		main(int ac, char **av, char **env)
{
	t_tab	t;

	(void)av;
	(void)ac;
	write(1, "$hell done Cooper->", 19);
	ft_get_env(env, &t);
	ft_get_path(&t);
	ft_Shell_done(&t);
	return (0);
}
