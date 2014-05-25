/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 10:33:44 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/19 17:14:55 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    ft_aff_env(t_tab *t)
{
    int i;

    i = 0;
    while (t->my_env[i])
	{
		ft_putendl(t->my_env[i]);
		i++;
	}
}

char    *get_line(t_tab *t, char *l)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    while (t->my_env[i])
    {
        tmp = ft_strstr(t->my_env[i], l);
        if (tmp)
        {
            tmp = ft_strsub(tmp, ft_strlen(l), ft_strlen(tmp) - (ft_strlen(l)));
            break ;
        }
        i++;
    }
    return (tmp);
}

int main(int ac, char **av, char **env)
{
	t_tab	t;
	int		i;

	i = 0;
	(void)av;
	(void)ac;
	ft_get_env(env, &t);;
	ft_check_env(&t, av, ac);
	ft_putendl("");
	ft_aff_env(&t);
	ft_putendl("");
	return (0);
}

int     ft_check_env(t_tab *t, char **av, int ac)
{
    if (!ft_strcmp(av[1], "setenv"))
    {
        if (ac  == 2)
        {
		   ft_aff_env(t);
		   return (1);
		}
        ft_setenv(t, av, ac);
        return (1);
    }
    if (ac == 2 && !ft_strcmp(av[1], "env"))
    {
		ft_aff_env(t);
        return (1);
    }
    return (0);
}

int     ft_setenv(t_tab *t, char **av, int ac)
{
    char    *tmp;
    char    *tmp2;
    int     i;

    i = 0;
    tmp = get_line(t, av[2]);
    tmp2 = ft_strjoin(av[2], "=");
    if (tmp && ac == 4)
    {
		ft_putendl("ac 4");
        tmp2 = ft_strjoin(tmp2, av[3]);
        free(t->my_env[get_tab_row(t, av[2])]);
        t->my_env[get_tab_row(t, av[2])] = tmp2;
		return (0);
    }
    if (tmp && ac == 3)
    {
		ft_putendl("ac 3");
        tmp2 = ft_strjoin(tmp2, "\0");
        free(t->my_env[get_tab_row(t, av[2])]);
        t->my_env[get_tab_row(t, av[2])] = tmp2;
		return (0);
    }
	else if (!tmp)
    {
		ft_putendl("!tmp");
        while (t->my_env[i])
            i++;
        t->new_tab = (char **)malloc(sizeof(char *) * (i + 2));
        i = 0;
		while (t->my_env[i])
        {
            t->new_tab[i] = strdup(t->my_env[i]);
            i++;
        }
        if (ac == 4)
		{
			ft_putendl(" tmp && ac 4");
			tmp2 = ft_strjoin(tmp2, av[3]);
        }
		if (ac == 3)
		{
			ft_putendl("tmp && ac 3");
			tmp2 = ft_strjoin(tmp2, "\0");
        }
		t->new_tab[i] = tmp2;
        i++;
        t->new_tab[i] = '\0';
        t->my_env = t->new_tab;
		return (0);
    }
    return (0);
}

int     get_tab_row(t_tab *t, char *l)
{
    int     i;
    int     res;

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

int     ft_srchstr(char *search, char *tofind)
{
    int j;
	int	i;

	i = 0;
    j = 0;
	while (search[j] == tofind[j])
	{
		j++;
		if (tofind[j] == '\0')
			return (1);
	}
	return (0);
}

void    ft_get_env(char **env, t_tab *t)
{
    int     i;

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
