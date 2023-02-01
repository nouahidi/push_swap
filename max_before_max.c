/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_before_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:36:15 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 12:01:58 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	len_inst(int ps, t_var	*v)
{
	t_list	*t;

	t = v->pb;
	while (t)
	{
		if (t->position == ps)
		{
			if (position_b(t->position, v) <= ft_lstsize(v->pb) / 2)
				return (position_b(t->position, v));
			else
				return (ft_lstsize(v->pb) - position_b(t->position, v));
		}
		t = t->next;
	}
	return (0);
}

static	void	push_top1(long long top, t_var	*v, int i)
{	
	while (1)
	{
		if (top == v->pb->content)
		{
			push_a(v);
			return ;
		}
		if (i == 0)
			reverse_rotate_b(v);
		else if (i == 1)
			rotate_b(v);
	}
}

static	void	norm_push_a(t_var *v)
{
	t_list	*t;

	t = v->pb;
	while (t)
	{
		if (t->position == ft_lstsize(v->pb))
			v->max = t;
		t = t->next;
	}
	t = v->pb;
	while (t)
	{
		if (t->position == ft_lstsize(v->pb) - 1)
			v->b_max = t;
		t = t->next;
	}
}

void	norm_push_a2(t_var *v)
{
	if (position_b(v->b_max->position, v) <= ft_lstsize(v->pb) / 2)
		push_top1(v->b_max->content, v, 1);
	else
		push_top1(v->b_max->content, v, 0);
	if (position_b(v->max->position, v) <= ft_lstsize(v->pb) / 2)
		push_top1(v->max->content, v, 1);
	else
		push_top1(v->max->content, v, 0);
}

void	max_before_max(t_var *v)
{
	t_list	*t;

	t = v->pb;
	if (ft_lstsize(v->pb) == 1)
	{
		push_a(v);
		return ;
	}
	norm_push_a(v);
	if (len_inst(v->max->position, v) <= len_inst(v->b_max->position, v))
	{
		if (position_b(v->max->position, v) <= ft_lstsize(v->pb) / 2)
			push_top1(v->max->content, v, 1);
		else
			push_top1(v->max->content, v, 0);
	}
	else
	{
		norm_push_a2(v);
		swap_a(v);
	}
	if (v->pb)
		max_before_max(v);
}
