/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:12:15 by vdiridol          #+#    #+#             */
/*   Updated: 2014/01/09 18:08:16 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# define FD ft_open()

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include "libft/includes/libft.h"
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct	termios t_term;

typedef struct	winsize t_win;

typedef struct	s_list
{
	int				subline;
	int				select;
	struct s_list	*end;
	char			*arg;
	int				x;
	int				y;
	size_t			size;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

extern t_term	g_term;
extern t_list	**g_list;

void	put_last(t_list **list, int ymax);
int		get_ymax(t_list **list, int ymax);
int		ft_open(void);
void	ft_echap(int *buff, int ac);
void	ft_error(int res, int ac);
int		reset_term(void);
void	ft_chk_sig(void);
sig_t	signal(int sig, sig_t func);
int		ft_putint(int c);
void	mk_rnd_list(t_list **list);
t_list	*mk_node(char *av, int ac,  t_list *new);
void	mk_list(t_list **list, char *av, int ac);
void	ft_chk_slct(t_list **list);
void	ft_chk_down(int *buff, t_list **list);
void	ft_chk_up(int *buff, t_list **list);
void	ft_print(int ac, t_list *list);
int		mk_term(void);
void	print_new_end(t_list **list);
void	print_new_list(t_list **list);
void	ft_rmv_end(t_list *tmp, t_list *tmp2, t_list **list);
void	rmv_list(t_list **list);
void	ft_del(int *buff, t_list **list);
int		ft_loop(int *buff, t_list **list, int ac);
t_list	*ft_list(t_list **list, int ac, char **av);

#endif /* !SELECT_H */
