/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:15:29 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/02 13:48:06 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_push(t_var	*v, int j)
{
	if ((v->k - j) >= j + 1)
	{
		while (j)
		{
			rotate_a(v);
			j--;
		}
		push_b(v);
		if (v->k - 3)
			push_swap(v);
	}
	else
	{
		while (j < v->k)
		{
			reverse_rotate_a(v);
			j++;
		}
		push_b(v);
		if (v->k - 3)
			push_swap(v);
	}
}

void	push_swap(t_var *v)
{
	t_list		*t;
	int			j;

	t = v->p;
	v->tp = v->p;
	v->cnt++;
	v->k = ft_lstsize(v->p);
	if (v->k > 3)
	{
		while (t)
		{
			if (v->tp->content > t->content)
				v->tp = t;
			t = t->next;
		}
		j = ft_search(v);
		norm_push(v, j);
	}
	sort_3(v);
	while (v->pb)
		push_a(v);
}
