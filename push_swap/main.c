/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:42:35 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 22:30:41 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rt(long long *l, t_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_lstsize(v->p))
	{
		j = 0;
		while (j < ft_lstsize(v->p))
		{
			if (l[i] == l[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_sort(long long *l, t_var *v)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(v->p) - 1)
	{
		if (l[i] > l[i + 1])
			return ;
		i++;
	}
	ft_lstclear(&v->p);
	free(l);
	exit(0);
}

void	norm_main(t_var *v, long long *l)
{
	v->cnt = 1;
	v->k = ft_lstsize(v->p);
	list_numbering(v, l);
	v->pb = NULL;
	v->k = ft_lstsize(v->p);
	if (v->k < 6)
		push_swap(v);
	else if (ft_lstsize(v->p) < 101)
		push_100_500(v, 5);
	else
		push_100_500(v, 9);
	ft_lstclear(&v->p);
}

int	main(int ac, char **av)
{
	long long		*l;
	t_var			v;

	v.i = 1;
	v.h = 0;
	v.p = NULL;
	if (ac > 1)
	{
		while (av[v.i])
		{
			if (!check_nb(av[v.i]))
				return (write (1, "Error", 5), 1);
			ft_aatoi(av[v.i], &v);
			v.i++;
		}
		l = tab_int(&v, v.p);
		v.i--;
		if (!check_rt(l, &v))
			return (write (1, "Error", 5), \
			ft_lstclear(&v.p), free(l), 1);
		check_sort(l, &v);
		norm_main(&v, l);
	}
	return (0);
}
