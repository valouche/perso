/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:11:48 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/29 21:12:00 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] != s2[j])
		{
			i = i - j;
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (s2[j] != '\0')
		return (NULL);
	return ((char *)s1 + (i - j));
}
