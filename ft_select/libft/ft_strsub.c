/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:26:04 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/01 19:02:35 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	i = 0;
	str	= (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	if (s)
	{
		while (i < len && s[i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
