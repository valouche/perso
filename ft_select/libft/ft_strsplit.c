/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:44:01 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/26 15:44:10 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_wordcount(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		if (s[i] != c && j != 0)
		{
			k++;
			j = 0;
		}
		i++;
	}
	return (k);
}

static int		ft_geti(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int		ft_getj(const char *s, char c, int i)
{
	int		j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mat;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (c == 0 || s == NULL)
		return (NULL);
	mat = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!mat)
		return (NULL);
	while (s[i] != '\0')
	{
		i = ft_geti(s, c, i);
		j = ft_getj(s, c, i);
		mat[k] = ft_strsub(s, i, j);
		k++;
		i = i + j;
	}
	mat[ft_wordcount(s, c)] = NULL;
	return (mat);
}
