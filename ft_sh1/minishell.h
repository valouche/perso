/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:41:16 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/27 14:59:05 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"
# include <unistd.h>

typedef	struct	s_tab
{
	char	**my_env;
	char	**my_path;
	char	**new_tab;
	char	**cd;
}				t_tab;

typedef	struct	s_struc
{
	int		ret;
	char	**prio;
	char	**arg;
	char	*buff;
	int		i;
	pid_t	father;
	int		ac;
}				t_struc;

int		ft_builtin(t_tab *t, t_struc *s, int ret);
void	ft_prio(t_struc *s, t_tab *t);
void	ft_error(t_struc *s, int error);
void	ft_unset_tab(t_tab *t, t_struc *s);
void	ft_aff_env(t_tab *t);
void	ft_get_env(char **env, t_tab *t);
int		ft_srchstr(char *search, char *tofind);
int		get_tab_row(t_tab *t, char *l);
int		ft_setenv(t_tab *t, t_struc *s);
void	ft_pwd(t_tab *t, char *pwd);
char	*get_line(t_tab *t, char *l);
int		ft_cd(t_struc *s, t_tab *t, int ret);
int		ft_check_env(t_tab *t, t_struc *s, int ret);
void	ft_exe(t_tab *t, t_struc *s);
void	ft_fork(t_tab *t, t_struc *s, int ret);
void	ft_get_path(t_tab *t);

#endif	/* !MINISHELL_H */
