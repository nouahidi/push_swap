/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:50:59 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/18 12:25:52 by nouahidi         ###   ########.fr       */
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
