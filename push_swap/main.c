/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:42:35 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/25 22:07:48 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			if (str[i - 1] == '+' || str[i - 1] == '-')
				return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && str[i] != ' ' & str[i] != '\t')
			return (0);
	}
	return (1);
}

long long	*tab_int(t_var *v)
{
	long long	*l;
	int			i;
	t_list		*t;

	t = v->p;
	i = 0;
	l = malloc(v->h * sizeof(long long));
	while (t)
	{
		l[i] = t->content;
		t = t->next;
		i++;
	}
	return (l);
}

int	check_rt(long long *l, t_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->h)
	{
		j = 0;
		while (j < v->h)
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
	while (i < v->h - 1)
	{
		if (l[i] > l[i + 1])
			return ;
		i++;
	}
	i = 0;
	while (i < v->h)
	{
		ft_putnbr(l[i]);
		write(1, "\n", 1);
		i++;
	}
	exit(0);
}

int	main(int ac, char **av)
{
	long long		*l;
	t_var			v;
	// t_list	*t;

	v.i = 1;
	v.h = 0;
	v.p = NULL;
	if (ac > 2)
	{
		while (av[v.i])
		{
			if (!check_nb(av[v.i]))
				return (write (1, "error nember", 12), 0);
			ft_aatoi(av[v.i], &v);
			v.i++;
		}
		l = tab_int(&v);
		v.i--;
		if (!check_rt(l, &v))
			return (write (1, "repeated number", 15), 0);
		check_sort(l, &v);
		v.cnt = 1;
		v.k = ft_lstsize(v.p);
		list_numbering(&v);
		v.k = ft_lstsize(v.p);
		if (ft_lstsize(v.p) < 6)
			push_swap(&v);
		else if (ft_lstsize(v.p) < 101)
			push_100_500(&v, 5);
		else
			push_100_500(&v, 8);
		// while (v.pb)
		// {
		// 	printf ("==>%lld\n", v.pb->content);
		// 	v.pb = v.pb->next;
		// }
		// while (v.p)
		// {
		// 	printf ("--==>%d\n", v.p->position);
		// 	v.p = v.p->next;
		// }
	}
}
