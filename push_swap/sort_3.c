/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:05:15 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/18 16:10:43 by nouahidi         ###   ########.fr       */
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
		if (v->tp->content > t->content)
			v->tp = t;
		t = t->next;
	}
}

void	sort_3(t_var *v)
{
	t_list	*t;
	int		j;

	v->tp = v->p;
	if (ft_lstsize(v->p) == 2)
	{
		sort_2(v);
		return ;
	}
	norm(v);
	j = ft_search(v);
	if (j == 1)
		rotate_a(v);
	if (j == 2)
		reverse_rotate_a(v);
	t = v->p->next;
	if (t->content > t->next->content)
	{
		reverse_rotate_a(v);
		swap_a(v);
	}
}
