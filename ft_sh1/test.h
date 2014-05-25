/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 13:30:19 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/19 16:55:55 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"
# include <unistd.h>

typedef struct  s_tab
{
    char    **my_env;
    char    **my_path;
    char    **new_tab;
}               t_tab;

typedef struct  s_struc
{
    int     ret;
    char    **arg;
    char    buff[1024];
    int     i;
    pid_t   father;
    int     ac;
}               t_struc;

void    ft_get_env(char **env, t_tab *t);
int     ft_srchstr(char *search, char *tofind);
int     get_tab_row(t_tab *t, char *l);
int     ft_setenv(t_tab *t, char **av, int ac);
void    ft_pwd(t_tab *t);
char    *get_line(t_tab *t, char *l);
void    ft_cd(t_struc *s, t_tab *t);
int     ft_check_env(t_tab *t, char **av, int ac);
void    ft_exe(t_tab *t, t_struc *s);
void    ft_fork(t_tab *t, t_struc *s, int ret);
void    ft_get_path(t_tab *t);

#endif  /* !MINISHELL_H */
