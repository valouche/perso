/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 12:22:15 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/05 16:39:47 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*dst;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	dst = (void *)malloc(sizeof(*ptr) * size);
	if (!dst)
		return (NULL);
	dst = ft_memcpy(dst, ptr, size);
	free(ptr);
	return (dst);
}
