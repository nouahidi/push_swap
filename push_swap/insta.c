/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:27:47 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/20 21:49:26 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_var *v)
{
	int		tmp;

	write (1, "sa\n", 3);
	tmp = v->p->content;
	v->p->content = v->p->next->content;
	v->p->next->content = tmp;
	tmp = v->p->position;
	v->p->position = v->p->next->position;
	v->p->next->position = tmp;
}

void	rotate_a(t_var *v)
{
	int		tmp;
	int		tm;
	t_list	*t;

	t = v->p;
	tmp = v->p->content;
	tm = v->p->position;
	free(v->p);
	v->p = v->p->next;
	ft_lstadd_back(&v->p, ft_lstnew(tmp));
	while (t)
	{
		if (t->next == NULL)
			t->position = tm;
		t = t->next;
	}
	write (1, "ra\n", 3);
}

void	reverse_rotate_a(t_var *v)
{
	t_list	*t;
	int		tmp;
	int		tm;

	t = v->p;
	write (1, "rra\n", 4);
	while (t->next)
	{
		if (t->next->next == NULL)
		{
			tmp = t->next->content;
			tm = t->next->position;
			free(t->next);
			t->next = NULL;
			ft_lstadd_front(&v->p, ft_lstnew(tmp));
			v->p->position = tm;
			return ;
		}
		t = t->next;
	}
}

void	push_a(t_var *v)
{
	t_list	*t;
	int		tmp;

	write (1, "pa\n", 3);
	tmp = v->pb->position;
	t = ft_lstnew(v->pb->content);
	ft_lstadd_front(&v->p, t);
	v->p->position = tmp;
	free(v->pb);
	v->pb = v->pb->next;
}
