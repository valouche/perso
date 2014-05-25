/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:12:37 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/08 18:31:34 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_mkbuf(int const fd, int nread, char *buf)
{
	char		*str;
	static int	flag;

	if (!buf)
		str = NULL;
	while (nread > 0)
	{
		nread = read(fd, buf, BUFF_SIZE);
		if (flag == 0)
		{
			str = ft_strsub(buf, 0, nread);
			flag += 1;
		}
		else
		{
			buf = ft_strsub(buf, 0, nread);
			str = ft_strjoin(str, buf);
		}
		free(buf);
	}
	if (nread == -1)
		str = NULL;
	return (str);
}

int	get_next_line(int const fd, char **line)
{
	static int	flag;
	static char	*stk;
	int			nread;
	char		*buf;
	int j;

	j = 0;
	nread = 1;
	if (flag == 0)
	{
		buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1));
		stk = ft_mkbuf(fd, nread, buf);
	}
	if (stk == NULL)
		return (-1);
	if (stk[flag] == '\0')
	{
		free(stk);
		return (0);
	}
	while (stk[flag + j] != '\n' && stk[flag + j] != '\0')
		j++;
	*line = ft_strsub(stk, flag, j);
	flag = flag + j + 1;
	return (1);
}
