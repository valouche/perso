/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:29:41 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/01 21:30:24 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	 int		bgn;
	 int		end;

	bgn = 0;
	end = 0;
	if (!s)
		return (NULL);
	while ((s[bgn] == ' ' || s[bgn] == '\n' || s[bgn] == '\t') && (s[bgn]))
		bgn++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && (bgn <= end))
		end--;
	return (ft_strsub(s, bgn, (end - bgn + 1)));

}
