/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:18:41 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/02 15:26:37 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_bon(t_var *v)
{
	long long	*l;
	int			i;

	l = tab_int(v, v->st_a);
	i = 0;
	while (i < ft_lstsize(v->st_a) - 1)
	{
		if (l[i] > l[i + 1])
			return (0);
		i++;
	}
	free(l);
	return (1);
}

void	read_norm2(t_var *v)
{
	write (1, "Error", 5);
	ft_lstclear(&v->st_a);
	ft_lstclear(&v->st_b);
	free(v->le);
	free (v->st);
	exit(0);
}

void	read_norm(t_var	*v, char *str)
{
	if (ft_strncmp(str, "rrr\n") == 0)
	{
		reverse_rotate_a_bon(v);
		reverse_rotate_b_bon(v);
	}
	else if (ft_strncmp(str, "rr\n") == 0)
	{
		rotate_a_bon(v);
		rotate_b_bon(v);
	}
	else if (ft_strncmp(str, "ss\n") == 0)
	{
		swap_a_bon(v);
		swap_b_bon(v);
	}
	else if (ft_strncmp(str, "pa\n") == 0)
		push_a_bon(v);
	else if (ft_strncmp(str, "pb\n") == 0)
		push_b_bon(v);
	else
		read_norm2(v);
}

int	read_inp(t_var	*v)
{
	v->st = get_next_line(0);
	while (v->st)
	{
		if (ft_strncmp(v->st, "ra\n") == 0)
			rotate_a_bon(v);
		else if (ft_strncmp(v->st, "sa\n") == 0)
			swap_a_bon(v);
		else if (ft_strncmp(v->st, "rb\n") == 0)
			rotate_b_bon(v);
		else if (ft_strncmp(v->st, "sb\n") == 0)
			swap_b_bon(v);
		else if (ft_strncmp(v->st, "rra\n") == 0)
			reverse_rotate_a_bon(v);
		else if (ft_strncmp(v->st, "rrb\n") == 0)
			reverse_rotate_b_bon(v);
		else
			read_norm(v, v->st);
		free(v->st);
		v->st = get_next_line(0);
	}
	free(v->st);
	if (check_sort_bon(v) == 1 && !v->st_b)
		return (ft_lstclear(&v->st_a), 1);
	else
		return (ft_lstclear(&v->st_a), ft_lstclear(&v->st_b), 0);
}
