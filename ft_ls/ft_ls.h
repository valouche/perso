/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:03:05 by vdiridol          #+#    #+#             */
/*   Updated: 2013/12/13 14:00:08 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef _FT_LS_H_
# define _FT_LS_H_

# include <stdlib.h>
# include <libft.h>

typedef	struct	s_list
{
	char			*str;
	struct	s_list	*next;
	struct	s_list	*prev;
}				t_list;

#endif
