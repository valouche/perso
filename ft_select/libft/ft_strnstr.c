/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:53:54 by vdiridol          #+#    #+#             */
/*   Updated: 2013/11/28 11:49:49 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return ((char *)(s1));
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && s2[j] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (s2[j] == '\0')
		return ((char *)(&s1[i - j]));
	return (NULL);
}
