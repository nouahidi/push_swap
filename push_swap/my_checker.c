/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:37 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 22:38:56 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_srt(long long *l, t_var *v)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(v->st_a) - 1)
	{
		if (l[i] > l[i + 1])
			return ;
		i++;
	}
	ft_lstclear(&v->st_a);
	free(l);
	exit(0);
}

int	check_rtt(long long *l, t_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_lstsize(v->st_a))
	{
		j = 0;
		while (j < ft_lstsize(v->st_a))
		{
			if (l[i] == l[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	nom_main_bon(t_var	*v)
{
	if (read_inp(v) == 0)
		return (write (1, "KO\n", 3), 1);
	else
		return (write (1, "OK\n", 3), 0);
}

int	main(int ac, char **av)
{
	long long		*l;
	t_var			v;

	v.i = 1;
	v.h = 0;
	v.st_a = NULL;
	if (ac > 1)
	{
		while (av[v.i])
		{
			if (!check_nb(av[v.i]))
				return (write (1, "error", 5), 1);
			ft_aatoi_bon(av[v.i], &v);
			v.i++;
		}
		l = tab_int(&v, v.st_a);
		if (!check_rtt(l, &v))
			return (write (1, "error", 5), \
			ft_lstclear(&v.st_a), free(l), 1);
		// check_srt(l, &v);
		if (nom_main_bon(&v) == 0)
			return (1);
		else
			return (0);
	}
}
