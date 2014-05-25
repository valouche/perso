/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:19:06 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/13 13:59:13 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include "ft_ls.h"

void	ft_ls(char *dir);
void	ft_ls_multi(char **argv, unsigned int i);
t_list	ft_mklist(char *str);

int		main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (argc == 1)
		ft_ls(".");
	if (argc == 2)
		ft_ls(argv[1]);
	if (argc > 2)
		ft_ls_multi(argv, i);
	return (0);
}

void	ft_ls(char *dir)
{
	struct dirent	*rd;
	DIR             *dirpt;

	dirpt = opendir(dir);
	while ((rd = readdir(dirpt)))
	{
		if (rd->d_name[0] != '.')
		{
			ft_mklist(rd->d_name);
			ft_putendl(rd->d_name);
		}
	}
	closedir(dirpt);
}

void	ft_ls_multi(char **argv, unsigned int i)
{
	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putendl(":");
		ft_ls(argv[i++]);
		ft_putchar('\n');
	}
}

t_list	ft_mklist(char *str)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = list;
		tmp->prev = NULL;
	}
	return (*tmp);
}
