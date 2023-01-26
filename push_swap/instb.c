/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:00:15 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/20 15:35:14 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_var *v)
{
	t_list	*t;
	int		tmp;

	write (1, "pb\n", 3);
	tmp = v->p->position;
	t = ft_lstnew(v->p->content);
	ft_lstadd_front(&v->pb, t);
	v->pb->position = tmp;
	free(v->p);
	v->p = v->p->next;
}

void	swap_b(t_var *v)
{
	int		tmp;

	write (1, "sb\n", 3);
	tmp = v->pb->content;
	v->pb->content = v->pb->next->content;
	v->pb->next->content = tmp;
	tmp = v->pb->position;
	v->pb->position = v->pb->next->position;
	v->pb->next->position = tmp;
}

void	reverse_rotate_b(t_var *v)
{
	t_list	*t;
	int		tmp;
	int		tm;

	t = v->pb;
	write (1, "rrb\n", 4);
	t = v->pb;
	while (t->next)
	{
		if (t->next->next == NULL)
		{
			tmp = t->next->content;
			tm = t->next->position;
			free(t->next);
			t->next = NULL;
			ft_lstadd_front(&v->pb, ft_lstnew(tmp));
			v->pb->position = tm;
			return ;
		}
		t = t->next;
	}
}

void	rotate_b(t_var *v)
{
	int		tmp;
	int		tm;
	t_list	*t;

	t = v->pb;
	tmp = v->pb->content;
	tm = v->pb->position;
	free(v->pb);
	v->pb = v->pb->next;
	ft_lstadd_back(&v->pb, ft_lstnew(tmp));
	while (t)
	{
		if (t->next == NULL)
			t->position = tm;
		t = t->next;
	}
	write (1, "rb\n", 3);
}
