/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:37:46 by vdiridol          #+#    #+#             */
/*   Updated: 2013/11/26 18:15:20 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*str2;
	unsigned char 		*str1;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
