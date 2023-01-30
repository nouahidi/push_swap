/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:50:59 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 16:45:35 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search(t_var	*v)
{
	t_list	*t;
	int		j;

	j = 0;
	t = v->p;
	while (t)
	{
		if (v->tp->content == t->content)
			return (j);
		t = t->next;
		j++;
	}
	return (j);
}

long long	*tab_int(t_var *v, t_list *st)
{
	long long	*l;
	int			i;
	t_list		*t;

	(void)v;
	t = st;
	i = 0;
	l = malloc(ft_lstsize(st) * sizeof(long long));
	while (t)
	{
		l[i] = t->content;
		t = t->next;
		i++;
	}
	return (l);
}
