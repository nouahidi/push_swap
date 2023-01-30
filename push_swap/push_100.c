/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:32:18 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 18:49:29 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	norm_push_3(t_var *v)
{
	if (v->pb->position == 2)
	{
		push_a(v);
		push_a(v);
	}
	else
	{
		push_a(v);
		push_a(v);
		swap_a(v);
	}
}

void	push_3(t_var *v)
{
	t_list	*t;
	t_list	*max;

	t = v->pb;
	while (t)
	{
		if (t->position == 3)
			max = t;
		t = t->next;
	}
	while (1)
	{
		if (v->pb->content == max->content)
		{
			push_a(v);
			break ;
		}
		rotate_b(v);
	}
	norm_push_3(v);
}

void	push_top(long long top, t_var	*v, int i)
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

void	push_elm(t_var *v, int ps, int i)
{
	while (1)
	{
		if (ps == v->p->position)
		{
			push_b(v);
			return ;
		}
		if (i == 1)
			rotate_a(v);
		else if (i == 0)
			reverse_rotate_a(v);
	}
}

void	push_100_500(t_var	*v, int w)
{
	int		k;
	t_list	*t;

	k = v->k / w;
	v->tmp = k;
	t = v->p;
	v->chunk_limit = 0;
	while (t)
	{
		if (t->position <= k)
		{
			v->chunk_limit++;
			push_b(v);
			if (t->position >= k - (v->tmp / 2) && ft_lstsize(v->pb) > 1)
				rotate_b(v);
			if (!v->p)
				break ;
		}
		else
			rotate_a(v);
		t = v->p;
		if (v->chunk_limit == k)
			k += v->tmp;
	}
	max_before_max(v);
}
