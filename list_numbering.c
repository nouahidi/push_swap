/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_numbering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:44:16 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 16:54:22 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_n(int pt, t_var	*v)
{
	t_list	*t;
	int		i;

	i = 0;
	t = v->p;
	while (t)
	{
		if (t->position == pt)
			return (i);
		t = t->next;
		i++;
	}
	return (0);
}

int	position_b(int pt, t_var	*v)
{
	t_list	*t;
	int		i;

	i = 0;
	t = v->pb;
	while (t)
	{
		if (t->position == pt)
			return (i);
		t = t->next;
		i++;
	}
	return (0);
}

static long long	*numb_tab(long long *tab, t_var	*v)
{
	int	j;
	int	i;
	int	tmp;

	j = v->k;
	i = 0;
	while (j > 0)
	{
		while (i < v->k - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		j--;
	}
	return (tab);
}

void	list_numbering(t_var *v, long long *l)
{
	int			i;
	t_list		*t;

	t = v->p;
	i = 0;
	l = numb_tab(l, v);
	t = v->p;
	while (t)
	{
		while (i < v->k)
		{
			if (t->content == l[i])
			{
				t->position = i + 1;
				break ;
			}
			i++;
		}
		i = 0;
		t = t->next;
	}
	free(l);
}
