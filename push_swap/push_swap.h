/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:51:13 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/25 18:35:13 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				position;
	long long		content;
	struct s_list	*next;
}					t_list;

typedef struct s_var
{
	long long		*l;
	int				i;
	int				k;
	int				cnt;
	int				len;
	int				h;
	int				j;
	t_list			*p;
	t_list			*pb;
	t_list			*tp;
}					t_var;

int				ft_atoi(const char *st);
t_list			*ft_lstnew(long long content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_putnbr(int nb);
void			swap_a(t_var *v);
void			swap_b(t_var *v);
void			reverse_rotate_a(t_var *v);
void			reverse_rotate_b(t_var *v);
void			rotate_a(t_var *v);
void			ft_aatoi(char *st, t_var *v);
void			push_a(t_var *v);
void			push_b(t_var *v);
void			rotate_b(t_var *v);
int				ft_lstsize(t_list *lst);
void			push_swap(t_var *v);
int				ft_search(t_var	*v);
void			list_numbering(t_var *v);
void			sort_3(t_var *v);
int				position_n(int pt, t_var	*v);
void			push_100_500(t_var	*v, int	w);
int				position_b(int pt, t_var	*v);

#endif