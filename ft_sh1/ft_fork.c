/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:45:45 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/27 14:57:33 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork(t_tab *t, t_struc *s, int ret)
{
	pid_t	father;

	s->i = 0;
	while (s->arg[s->i])
	{
		ft_putendl(s->arg[s->i]);
		s->i++;
	}
	father = fork();
	if (father > 0)
	{
		wait(0);
		write(1, "$hell done Cooper->", 19);
	}
	if (father == 0)
	{
		if (s->ac == 0)
			exit(0);
		if (ret == 0)
		{
			ft_exe(t, s);
			ft_putendl_fd("I don't think so.", 2);
		}
		exit(0);
	}
}

void	ft_move_dir(t_tab *t, t_struc *s, char *tmp, unsigned int j)
{
	int	error;

	s->i = 0;
	tmp = get_line(t, "PWD");
	t->cd = ft_strsplit(s->arg[1], '/');
	while (t->cd[s->i])
	{
		if (!ft_strcmp(t->cd[s->i], ".."))
		{
			j = ft_strlen(tmp);
			while (tmp[j] != '/')
				j--;
			tmp[j] = '\0';
		}
		if (ft_strcmp(t->cd[s->i], ".."))
		{
			t->cd[s->i] = ft_strjoin("/", t->cd[s->i]);
			tmp = ft_strjoin(tmp, t->cd[s->i]);
		}
		s->i++;
	}
	error = chdir(tmp);
	ft_error(s, error);
	ft_pwd(t, tmp);
}

int		ft_cd(t_struc *s, t_tab *t, int ret)
{
	char			*tmp;
	unsigned int	j;

	j = 0;
	tmp = NULL;
	if (s->arg[0] && !ft_strcmp(s->arg[0], "cd"))
	{
		if (!s->arg[1])
		{
			chdir(get_line(t, "HOME"));
			ft_pwd(t, get_line(t, "HOME"));
		}
		else
		{
			ft_move_dir(t, s, tmp, j);
			ret++;
			return(ret);
		}
	}
	return (0);
}

void	ft_pwd(t_tab *t, char *pwd)
{
	char		*tmp;
	int			line;

	line = get_tab_row(t, "PWD");
	tmp = get_line(t, "PWD");
	free(t->my_env[line]);
	t->my_env[line] = ft_strjoin("PWD=", pwd);
	line = get_tab_row(t, "OLDPWD");
	free(t->my_env[line]);
	t->my_env[line] = ft_strjoin("OLDPWD=", tmp);
}

char	*get_line(t_tab *t, char *l)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (t->my_env[i])
	{
		tmp = ft_strstr(t->my_env[i], ft_strjoin(l, "="));
		if (tmp)
		{
			tmp = ft_strsub(tmp, ft_strlen(l) + 1, ft_strlen(tmp) - (ft_strlen(l)));
			break ;
		}
		i++;
	}
	return (tmp);
}
