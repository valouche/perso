/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:43:18 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/01 14:48:39 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*str2;
	unsigned char 		*str1;
	char				*ptr;

	ptr = NULL;
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)(c))
		{
			i++;
			return (&str1[i]);
		}
		i++;
	}
	return (ptr);
}
