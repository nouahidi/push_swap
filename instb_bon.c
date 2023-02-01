/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instb_bon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:27 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 22:56:26 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_bon(t_var *v)
{
	t_list	*t;
	int		tmp;

	if (v->st_a)
	{
		tmp = v->st_a->position;
		t = ft_lstnew(v->st_a->content);
		ft_lstadd_front(&v->st_b, t);
		v->st_b->position = tmp;
		free(v->st_a);
		v->st_a = v->st_a->next;
	}
}

void	swap_b_bon(t_var *v)
{
	int		tmp;

	if (v->st_b && v->st_b->next)
	{
		tmp = v->st_b->content;
		v->st_b->content = v->st_b->next->content;
		v->st_b->next->content = tmp;
		tmp = v->st_b->position;
		v->st_b->position = v->st_b->next->position;
		v->st_b->next->position = tmp;
	}
}

void	reverse_rotate_b_bon(t_var *v)
{
	t_list	*t;
	int		tmp;
	int		tm;

	if (v->st_b)
	{
		t = v->st_b;
		t = v->st_b;
		while (t->next)
		{
			if (t->next->next == NULL)
			{
				tmp = t->next->content;
				tm = t->next->position;
				free(t->next);
				t->next = NULL;
				ft_lstadd_front(&v->st_b, ft_lstnew(tmp));
				v->st_b->position = tm;
				return ;
			}
			t = t->next;
		}
	}
}

void	rotate_b_bon(t_var *v)
{
	int		tmp;
	int		tm;
	t_list	*t;

	if (v->st_b)
	{
		t = v->st_b;
		tmp = v->st_b->content;
		tm = v->st_b->position;
		free(v->st_b);
		v->st_b = v->st_b->next;
		ft_lstadd_back(&v->st_b, ft_lstnew(tmp));
		while (t)
		{
			if (t->next == NULL)
				t->position = tm;
			t = t->next;
		}
	}
}
