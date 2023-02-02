/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:05:15 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/02 13:46:27 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_var *v)
{
	if (v->p->content > v->p->next->content)
		swap_a(v);
}

static void	norm(t_var *v)
{
	t_list	*t;

	t = v->p;
	while (t)
	{
		if (v->tp->content < t->content)
			v->tp = t;
		t = t->next;
	}
}

static void	norm2(t_var *v)
{
	if (v->p->next == v->tp)
	{
		if (v->p->next->position - v->p->position == 2)
		{
			swap_a(v);
			rotate_a(v);
		}
		else if (v->p->next->position - v->p->position == 1)
			reverse_rotate_a(v);
	}
	else
		if (v->p->position > v->p->next->position)
			swap_a(v);
}

void	sort_3(t_var *v)
{
	v->tp = v->p;
	if (ft_lstsize(v->p) == 2)
	{
		sort_2(v);
		return ;
	}
	norm(v);
	if (v->p == v->tp)
	{
		if (v->p->position - v->p->next->position == 1)
		{
			rotate_a(v);
			swap_a(v);
		}
		else
			rotate_a(v);
	}
	norm2(v);
}
