/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insta_bon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:07:06 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 23:17:11 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_bon(t_var *v)
{
	int		tmp;

	if (v->st_a && v->st_a->next)
	{
		tmp = v->st_a->content;
		v->st_a->content = v->st_a->next->content;
		v->st_a->next->content = tmp;
		tmp = v->st_a->position;
		v->st_a->position = v->st_a->next->position;
		v->st_a->next->position = tmp;
	}
}

void	rotate_a_bon(t_var *v)
{
	int		tmp;
	int		tm;
	t_list	*t;

	if (v->st_a)
	{
		t = v->st_a;
		tmp = v->st_a->content;
		tm = v->st_a->position;
		free(v->st_a);
		v->st_a = v->st_a->next;
		ft_lstadd_back(&v->st_a, ft_lstnew(tmp));
		while (t)
		{
			if (t->next == NULL)
				t->position = tm;
			t = t->next;
		}
	}
}

void	reverse_rotate_a_bon(t_var *v)
{
	t_list	*t;
	int		tmp;
	int		tm;

	if (v->st_a)
	{
		t = v->st_a;
		while (t->next)
		{
			if (t->next->next == NULL)
			{
				tmp = t->next->content;
				tm = t->next->position;
				free(t->next);
				t->next = NULL;
				ft_lstadd_front(&v->st_a, ft_lstnew(tmp));
				v->st_a->position = tm;
				return ;
			}
			t = t->next;
		}
	}
}

void	push_a_bon(t_var *v)
{
	t_list	*t;
	int		tmp;

	if (v->st_b)
	{
		tmp = v->st_b->position;
		t = ft_lstnew(v->st_b->content);
		ft_lstadd_front(&v->st_a, t);
		v->st_a->position = tmp;
		free(v->st_b);
		v->st_b = v->st_b->next;
	}
}

void	swap_a_b_bon(t_var *v)
{
	swap_a_bon(v);
	swap_b_bon(v);
}
