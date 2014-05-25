/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:41:49 by vdiridol          #+#    #+#             */
/*   Updated: 2013/11/27 11:33:33 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void*s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)(c))
			return ((char *)&(str[i]));
		i++;
	}
	return (0);
}
