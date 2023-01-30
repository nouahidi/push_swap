/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:45:18 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 20:49:39 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cheak_min_max(long long nb, long long r, t_var *v)
{
	if (!((nb * r) >= -2147483648 && (nb * r) <= 2147483647))
	{
		write (1, "error in min and max", 20);
		ft_lstclear(&v->p);
		exit(1);
	}
}

static void	cheak_min_max_bon(long long nb, long long r, t_var *v)
{
	if (!((nb * r) >= -2147483648 && (nb * r) <= 2147483647))
	{
		write (1, "error in min and max", 20);
		ft_lstclear(&v->st_a);
		exit(1);
	}
}

void	ft_aatoi(char *st, t_var *v)
{
	int			i;
	long long	r;
	long long	nb;

	r = 1;
	nb = 0;
	i = 0;
	while (st[i])
	{
		while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
			i++;
		if (!st[i])
			break ;
		if (st[i] == '+' || st[i] == '-')
			if (st[i++] == '-')
				r = -1;
		while (st[i] >= '0' && st[i] <= '9')
			nb = (nb * 10) + (st[i++] - '0');
		while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
			i++;
		cheak_min_max(nb, r, v);
		ft_lstadd_back(&v->p, ft_lstnew(nb * r));
		nb = 0;
		r = 1;
	}
}

void	ft_aatoi_bon(char *st, t_var *v)
{
	int			i;
	long long	r;
	long long	nb;

	r = 1;
	nb = 0;
	i = 0;
	while (st[i])
	{
		while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
			i++;
		if (!st[i])
			break ;
		if (st[i] == '+' || st[i] == '-')
			if (st[i++] == '-')
				r = -1;
		while (st[i] >= '0' && st[i] <= '9')
			nb = (nb * 10) + (st[i++] - '0');
		while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
			i++;
		cheak_min_max_bon(nb, r, v);
		ft_lstadd_back(&v->st_a, ft_lstnew(nb * r));
		nb = 0;
		r = 1;
	}
}
