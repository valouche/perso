/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:36:59 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/01 21:23:31 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) +  ft_strlen(s2);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	ft_strcpy((char *)str, (char *)s1);
	ft_strcat((char *)str, (char *)s2);
	return (str);
}
