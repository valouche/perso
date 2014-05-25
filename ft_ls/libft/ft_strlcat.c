/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:15:30 by vdiridol          #+#    #+#             */
/*   Updated: 2013/11/26 17:47:28 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (size > lendst)
	{
		while (src[i] != '\0' && size - 1 > lendst + i)
		{
			dst[lendst +  i] = src[i];
			i++;
		}
		dst[lendst + i] = '\0';
		return (lendst + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
